#include "core/tz.hpp"
#include "core/window.hpp"
#include "core/containers/grid_view.hpp"
#include "gl/device.hpp"
#include "gl/resource.hpp"
#include "gl/renderer.hpp"
#include "gl/imported_shaders.hpp"

#include ImportedShaderHeader(draw, vertex)
#include ImportedShaderHeader(draw, fragment)

int main()
{
	tz::initialise
	({
		.name = "Sample 003 - Paint",
		.window =
		{
			.flags = {.resizeable = false}
		}
	});
	{
		using namespace tz::literals;
		tz::gl::Device dev;

		tz::gl::RendererInfo rinfo;
		rinfo.shader().set_shader(tz::gl::ShaderStage::Vertex, ImportedShaderSource(draw, vertex));
		rinfo.shader().set_shader(tz::gl::ShaderStage::Fragment, ImportedShaderSource(draw, fragment));
		rinfo.set_options({tz::gl::RendererOption::NoDepthTesting});
		const auto dims = static_cast<tz::Vec2ui>(tz::Vec2{tz::window().get_width(), tz::window().get_height()});
		tz::gl::ImageResource img = tz::gl::ImageResource::from_uninitialised
		(
			tz::gl::ImageFormat::RGBA32,
			dims,
			tz::gl::ResourceAccess::DynamicFixed
		);
		tz::gl::ResourceHandle ires = rinfo.add_resource(img);

		tz::gl::Renderer renderer = dev.create_renderer(rinfo);

		while(!tz::window().is_close_requested())
		{
			tz::window().update();
			renderer.render(1);

			{
				const tz::MousePositionState& mouse_pos = tz::window().get_mouse_position_state();
				const tz::MouseButtonState& mouse_but = tz::window().get_mouse_button_state();
				tz::gl::IResource* r = renderer.get_resource(ires);
				tz::GridView<std::byte, 4> image_view{r->data(), dims};
				std::array<std::byte, 4> red_pixel{(std::byte)0xff, (std::byte)0x00, (std::byte)0x00, (std::byte)0xff};
				if(mouse_but.is_mouse_button_down(tz::MouseButton::Left))
				{
					auto mouse_safe = [](tz::Vec2ui mpos)->bool
					{
						return mpos[0] > 0 && mpos[0] < tz::window().get_width() &&
							mpos[1] > 0 && mpos[1] < tz::window().get_height();
					};
					
					tz::Vec2ui mpos = mouse_pos.get_mouse_position();
					mpos[1] = tz::window().get_height() - mpos[1];
					if(!mouse_safe(mpos))
						continue;
					auto pixel = image_view(mpos[0], mpos[1]);
					std::copy(red_pixel.begin(), red_pixel.end(), pixel.begin());
				}
			}
		}
	}
	tz::terminate();
}
