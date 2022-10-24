#include "render.hpp"
#include "image_import.hpp"
#include "tz/gl/imported_shaders.hpp"
#include "tz/core/matrix_transform.hpp"

#include ImportedShaderHeader(draw, vertex)
#include ImportedShaderHeader(draw, fragment)

namespace game
{
	tz::gl::ImageResource make_resource(const samplelib::ImageImportResult& import_result)
	{
		return tz::gl::ImageResource::from_memory(import_result.image_data,
		{
			.format = import_result.format,
			.dimensions = import_result.dimensions,
		});
	}

	void GameRenderInfo::set_camera(tz::Vec3 cam_pos, tz::Vec3 cam_rot)
	{
		this->camera_pos = cam_pos;
		this->camera_rot = cam_rot;
		this->view_matrix = tz::view(this->camera_pos, this->camera_rot);
	}
	
	void GameRenderInfo::update_dimensions(tz::Vec2 viewport_dimensions)
	{
		this->projection_matrix = tz::perspective(1.5708f, viewport_dimensions[0] / viewport_dimensions[1], 10.0f, 10000.0f);
	}

	RenderState::RenderState():
	rinfo(),
	world_mesh(game::get_world_mesh()),
	world_buf(tz::gl::BufferResource::from_many(this->world_mesh)),
	game_buf(tz::gl::BufferResource::from_one(GameRenderInfo{},
	{
		.access = tz::gl::ResourceAccess::DynamicFixed
	})),
	tonemapping_buf(tz::gl::BufferResource::from_one(ToneMappingInfo{},
	{
		.access = tz::gl::ResourceAccess::DynamicFixed
	})),
	stonebricks(game::get_image(game::ImageName::StoneBricks)),
	stonebricks_normal(game::get_image(game::ImageName::StoneBricks_NormalMap)),
	stonebricks_parallax(game::get_image(game::ImageName::StoneBricks_ParallaxMap)),
	stonebricks_res(make_resource(this->stonebricks)),
	stonebricks_normal_res(make_resource(this->stonebricks_normal)),
	stonebricks_parallax_res(make_resource(this->stonebricks_parallax)),
	birch(game::get_image(game::ImageName::Birch)),
	birch_normal(game::get_image(game::ImageName::Birch_NormalMap)),
	birch_parallax(game::get_image(game::ImageName::Birch_ParallaxMap)),
	birch_res(make_resource(this->birch)),
	birch_normal_res(make_resource(this->birch_normal)),
	birch_parallax_res(make_resource(this->birch_parallax)),
	wood(game::get_image(game::ImageName::Wood)),
	wood_normal(game::get_image(game::ImageName::Wood_NormalMap)),
	wood_parallax(game::get_image(game::ImageName::Wood_ParallaxMap)),
	wood_res(make_resource(this->wood)),
	wood_normal_res(make_resource(this->wood_normal)),
	wood_parallax_res(make_resource(this->wood_parallax)),
	world_buffer_handle(tz::nullhand),
	game_buffer_handle(tz::nullhand),
	tonemapping_buffer_handle(tz::nullhand)
	{
		tz_assert(stonebricks.success && birch.success && wood.success, "Failed to load one or more game images (Stonebricks = %d, Birch = %d, Wood = %d)", stonebricks.success, birch.success, wood.success);

		this->rinfo.shader().set_shader(tz::gl::ShaderStage::Vertex, ImportedShaderSource(draw, vertex));
		this->rinfo.shader().set_shader(tz::gl::ShaderStage::Fragment, ImportedShaderSource(draw, fragment));
		this->world_buffer_handle = this->rinfo.add_resource(this->world_buf);
		this->game_buffer_handle = this->rinfo.add_resource(this->game_buf);
		this->tonemapping_buffer_handle = this->rinfo.add_resource(this->tonemapping_buf);

		this->rinfo.add_resource(this->stonebricks_res);
		this->rinfo.add_resource(this->birch_res);
		this->rinfo.add_resource(this->wood_res);
		this->rinfo.add_resource(this->stonebricks_normal_res);
		this->rinfo.add_resource(this->birch_normal_res);
		this->rinfo.add_resource(this->wood_normal_res);
		this->rinfo.add_resource(this->stonebricks_parallax_res);
		this->rinfo.add_resource(this->birch_parallax_res);
		this->rinfo.add_resource(this->wood_parallax_res);
	}

	const tz::gl::RendererInfo& RenderState::info() const
	{
		return this->rinfo;
	}

	std::size_t RenderState::get_triangle_count() const
	{
		return this->world_mesh.size() / 3;
	}

	GameRenderInfo& RenderState::get_mutable_state(tz::gl::Renderer& renderer)
	{
		return renderer.get_resource(this->game_buffer_handle)->data_as<GameRenderInfo>().front();
	}

	ToneMappingInfo& RenderState::get_lighting_state(tz::gl::Renderer& renderer)
	{
		return renderer.get_resource(this->tonemapping_buffer_handle)->data_as<ToneMappingInfo>().front();
	}
}
