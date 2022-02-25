#ifndef TOPAZ_SAMPLES_HOUSE_RENDER_HPP
#define TOPAZ_SAMPLES_HOUSE_RENDER_HPP 
#include "gl/renderer.hpp"
#include "gl/device.hpp"
#include "gl/resource.hpp"
#include "core/matrix.hpp"

#include "image_import.hpp"
#include "resource.hpp"

// TEMP
#include "core/matrix_transform.hpp"

#include <array>

namespace game
{

	struct GameRenderInfo
	{
		tz::Vec3 camera_pos = {0.0f, 0.0f, 0.0f};
		float pad0;
		tz::Vec3 camera_rot = {0.0f, 0.0f, 0.0f};
		float pad1;
		std::array<tz::Mat4, 1> model_matrices = {{tz::Mat4::identity()}};
		tz::Mat4 view_matrix = tz::Mat4::identity();
		tz::Mat4 projection_matrix = tz::Mat4::identity();

		void set_camera(tz::Vec3 cam_pos, tz::Vec3 cam_rot);
		void update_dimensions(tz::Vec2 viewport_dimensions);
	};

	class RenderState
	{
	public:
		RenderState();
		tz::gl2::RendererInfo& info();
		std::size_t get_triangle_count() const;
		GameRenderInfo& get_mutable_state(tz::gl2::Renderer& renderer);
	private:
		tz::gl2::RendererInfo rinfo;
		game::NaiveMesh world_mesh;
		tz::gl2::BufferResource world_buf;
		tz::gl2::BufferResource game_buf;
		samplelib::ImageImportResult stonebricks;
		tz::gl2::ImageResource stonebricks_res;
		samplelib::ImageImportResult birch;
		tz::gl2::ImageResource birch_res;
		samplelib::ImageImportResult wood;
		tz::gl2::ImageResource wood_res;
		tz::gl2::ResourceHandle world_buffer_handle;
		tz::gl2::ResourceHandle game_buffer_handle;
	};
}

#endif // TOPAZ_SAMPLES_HOUSE_RENDER_HPP
