#ifndef TOPAZ_SAMPLES_TILES2D_RENDER_HPP
#define TOPAZ_SAMPLES_TILES2D_RENDER_HPP
#include "resource.hpp"
#include "core/vector.hpp"
#include "core/matrix.hpp"
#include "gl/renderer.hpp"
#include "gl/resource.hpp"

#include "image_import.hpp" // samplelib
#include <array>

namespace game
{
	struct GameRenderInfo
	{
		tz::Vec2 camera_pos = {0.0f, 0.0f};
		float camera_rot = 0.0f;
		float pad0;
		tz::Mat4 view_matrix = tz::Mat4::identity();
		tz::Mat4 projection_matrix = tz::Mat4::identity();

		void set_camera(tz::Vec2 cam_pos, float cam_rot);
		void update_dimensions(tz::Vec2 viewport_dimensions);
	};

	struct TextureStorage
	{
		struct Element
		{
			Element(const char* path);

			samplelib::ImageImportResult data;
			tz::gl2::ImageResource image;
		};
		tz::BasicList<Element> textures;
	};

	class RenderState
	{
	public:
		RenderState();
		const tz::gl2::RendererInfo& info() const;
		std::size_t get_triangle_count(tz::gl2::Renderer& renderer) const;
		GameRenderInfo& get_mutable_state(tz::gl2::Renderer& renderer);
		std::span<ObjectInfo> get_scene_object_state(tz::gl2::Renderer& renderer);
	private:
		tz::gl2::RendererInfo rinfo;
		tz::gl2::BufferResource game_buf;
		tz::gl2::BufferResource object_storage_buf;
		tz::gl2::ResourceHandle game_buffer_handle;
		tz::gl2::ResourceHandle object_storage_buffer_handle;
		TextureStorage textures;
	};
}

#endif // TOPAZ_SAMPLES_TILES2D_RENDER_HPP
