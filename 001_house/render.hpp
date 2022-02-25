#ifndef TOPAZ_SAMPLES_HOUSE_RENDER_HPP
#define TOPAZ_SAMPLES_HOUSE_RENDER_HPP 
#include "gl/renderer.hpp"
#include "gl/device.hpp"
#include "gl/resource.hpp"

#include "image_import.hpp"
#include "resource.hpp"

namespace game
{
	class RenderState
	{
	public:
		RenderState();
		tz::gl2::RendererInfo& info();
		std::size_t get_triangle_count() const;
	private:
		tz::gl2::RendererInfo rinfo;
		game::NaiveMesh world_mesh;
		tz::gl2::BufferResource world_buf;
		samplelib::ImageImportResult stonebricks;
		tz::gl2::ImageResource stonebricks_res;
		samplelib::ImageImportResult birch;
		tz::gl2::ImageResource birch_res;
		samplelib::ImageImportResult wood;
		tz::gl2::ImageResource wood_res;
		tz::gl2::ResourceHandle world_buffer_handle;
	};
}

#endif // TOPAZ_SAMPLES_HOUSE_RENDER_HPP
