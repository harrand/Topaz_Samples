#include "render.hpp"
#include "core/matrix_transform.hpp"
#include "gl/resource.hpp"
#include "gl/imported_shaders.hpp"
#include "image_import.hpp"

#include ImportedShaderHeader(draw, vertex)
#include ImportedShaderHeader(draw, fragment)

namespace game
{
	void GameRenderInfo::set_camera(tz::Vec2 cam_pos, float cam_rot)
	{
		this->camera_pos = cam_pos;
		this->camera_rot = cam_rot;
		this->view_matrix = tz::view(this->camera_pos.with_more(0.0f), {camera_rot, 0.0f, 0.0f});
	}

	void GameRenderInfo::update_dimensions(tz::Vec2 viewport_dimensions)
	{
		// Firstly we get aspect ratio.
		// Player should be able to see 100 world units up-and-down, and the relevant number left/right
		constexpr float vertical_stretch = 10.0f;
		float aspect_ratio = viewport_dimensions[0] / viewport_dimensions[1];
		float horizontal_stretch = aspect_ratio * vertical_stretch;
		this->projection_matrix = tz::orthographic(-horizontal_stretch, horizontal_stretch, vertical_stretch, -vertical_stretch, -10.0f, 10.0f);
	}

	TextureStorage::Element::Element(const char* path):
	data(samplelib::read_image(path)),
	image(tz::gl2::ImageResource::from_memory(this->data.format, this->data.dimensions, this->data.image_data))
	{

	}

	RenderState::RenderState():
	rinfo(),
	game_buf(tz::gl2::BufferResource::from_one(GameRenderInfo{}, tz::gl2::ResourceAccess::DynamicFixed)),
	object_storage_buf(tz::gl2::BufferResource::from_many
	({
		ObjectInfo
		{
			.model = tz::model({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}),
			.texture_id = 0
		},
		ObjectInfo
		{
			.model = tz::model({-10.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}),
			.texture_id = 1
		},
		ObjectInfo
		{
			.model = tz::model({10.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}),
			.texture_id = 2
		}
	}, tz::gl2::ResourceAccess::DynamicVariable)),
	game_buffer_handle(tz::nullhand),
	object_storage_buffer_handle(tz::nullhand),
	textures()
	{
		this->textures.textures =
		{
			TextureStorage::Element("../../002_tiles2d/data/orb_fire.png"),
			TextureStorage::Element("../../002_tiles2d/data/orb_frost.png"),
			TextureStorage::Element("../../002_tiles2d/data/orb_void.png")
		};

		this->rinfo.shader().set_shader(tz::gl2::ShaderStage::Vertex, ImportedShaderSource(draw, vertex));
		this->rinfo.shader().set_shader(tz::gl2::ShaderStage::Fragment, ImportedShaderSource(draw, fragment));
		this->game_buffer_handle = this->rinfo.add_resource(this->game_buf);
		this->object_storage_buffer_handle = this->rinfo.add_resource(this->object_storage_buf);
		for(TextureStorage::Element& texture_element : this->textures.textures)
		{
			this->rinfo.add_resource(texture_element.image);
		}
		this->rinfo.set_options({tz::gl2::RendererOption::NoDepthTesting});
	}

	const tz::gl2::RendererInfo& RenderState::info() const
	{
		return this->rinfo;
	}

	std::size_t RenderState::get_triangle_count(tz::gl2::Renderer& renderer) const
	{
		// Assume each 'quad' is 2 triangles. Therefore num triangles = 2 * number of objects in scene. This is resizeable so isn't trivial to calculate.
		return static_cast<tz::gl2::BufferResource*>(renderer.get_resource(this->object_storage_buffer_handle))->data_as<ObjectInfo>().size() * 2;
	}

	GameRenderInfo& RenderState::get_mutable_state(tz::gl2::Renderer& renderer)
	{
		return static_cast<tz::gl2::BufferResource*>(renderer.get_resource(this->game_buffer_handle))->data_as<GameRenderInfo>().front();
	}

	std::span<ObjectInfo> RenderState::get_scene_object_state(tz::gl2::Renderer& renderer)
	{
		return static_cast<tz::gl2::BufferResource*>(renderer.get_resource(this->object_storage_buffer_handle))->data_as<ObjectInfo>();
	}
}
