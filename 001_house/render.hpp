#ifndef TOPAZ_SAMPLES_HOUSE_RENDER_HPP
#define TOPAZ_SAMPLES_HOUSE_RENDER_HPP 
#include "gl/renderer.hpp"
#include "gl/device.hpp"
#include "gl/resource.hpp"
#include "core/matrix.hpp"

#include "image_import.hpp"
#include "resource.hpp"
#include <array>

namespace game
{

	struct GameRenderInfo
	{
		tz::Vec3 camera_pos = {0.0f, 60.0f, 0.0f};
		float pad0;
		tz::Vec3 camera_rot = {0.0f, 1.5708f, 0.0f};
		float pad1;
		std::array<ObjectInfo, 72> object_data = get_object_data();
		tz::Mat4 view_matrix = tz::Mat4::identity();
		tz::Mat4 projection_matrix = tz::Mat4::identity();

		void set_camera(tz::Vec3 cam_pos, tz::Vec3 cam_rot);
		void update_dimensions(tz::Vec2 viewport_dimensions);
	};

	class RenderState
	{
	public:
		RenderState();
		const tz::gl::RendererInfo& info() const;
		std::size_t get_triangle_count() const;
		GameRenderInfo& get_mutable_state(tz::gl::Renderer& renderer);
	private:
		tz::gl::RendererInfo rinfo;
		game::NaiveMesh world_mesh;
		tz::gl::BufferResource world_buf;
		tz::gl::BufferResource game_buf;
		samplelib::ImageImportResult stonebricks;
		samplelib::ImageImportResult stonebricks_normal;
		samplelib::ImageImportResult stonebricks_parallax;
		tz::gl::ImageResource stonebricks_res;
		tz::gl::ImageResource stonebricks_normal_res;
		tz::gl::ImageResource stonebricks_parallax_res;
		samplelib::ImageImportResult birch;
		samplelib::ImageImportResult birch_normal;
		samplelib::ImageImportResult birch_parallax;
		tz::gl::ImageResource birch_res;
		tz::gl::ImageResource birch_normal_res;
		tz::gl::ImageResource birch_parallax_res;
		samplelib::ImageImportResult wood;
		samplelib::ImageImportResult wood_normal;
		samplelib::ImageImportResult wood_parallax;
		tz::gl::ImageResource wood_res;
		tz::gl::ImageResource wood_normal_res;
		tz::gl::ImageResource wood_parallax_res;
		tz::gl::ResourceHandle world_buffer_handle;
		tz::gl::ResourceHandle game_buffer_handle;
	};
}

#endif // TOPAZ_SAMPLES_HOUSE_RENDER_HPP
