#include "core/tz.hpp"
#include "gl/device.hpp"
#include "gl/resource.hpp"
#include "gl/renderer.hpp"
#include "gl/imported_shaders.hpp"

#include "resource.hpp"

#include ImportedShaderHeader(draw, vertex)
#include ImportedShaderHeader(draw, fragment)

int main()
{
	tz::initialise
	({
		.name = "Sample 001 - House",
		.window = {.flags = {.resizeable = false}}
	});
	{
		std::size_t triangle_count;
		// Create mesh for game world
		// TODO: Give it data!
		game::NaiveMesh world_mesh = game::get_world_mesh();
		const std::size_t world_size_bytes = world_mesh.size() * sizeof(game::TriangleVertexData);
		triangle_count = world_mesh.size() / 3;

		tz::gl2::BufferResource world_buffer = tz::gl2::BufferResource::from_many(world_mesh);

		// Create renderer.
		tz::gl2::Device dev;
		tz::gl2::RendererInfo rinfo;
		rinfo.shader().set_shader(tz::gl2::ShaderStage::Vertex, ImportedShaderSource(draw, vertex));
		rinfo.shader().set_shader(tz::gl2::ShaderStage::Fragment, ImportedShaderSource(draw, fragment));
		rinfo.add_resource(world_buffer);
		tz::gl2::Renderer renderer = dev.create_renderer(rinfo);
		while(!tz::window().is_close_requested())
		{
			tz::window().update();
			renderer.render(triangle_count);
		}
	}
	tz::terminate();
	return 0;
}
