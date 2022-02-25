#include "core/tz.hpp"
#include "render.hpp"

int main()
{
	// A very basic sample which draws a house in a skybox. All resources and assets are loaded upfront for simplicity.
	tz::initialise
	({
		.name = "Sample 001 - House",
		.window = {.flags = {.resizeable = false}}
	});
	{
		game::RenderState state;
		// Create renderer.
		tz::gl2::Device dev;
		tz::gl2::Renderer renderer = dev.create_renderer(state.info());
		while(!tz::window().is_close_requested())
		{
			tz::window().update();
			renderer.render(state.get_triangle_count());
		}
	}
	tz::terminate();
	return 0;
}
