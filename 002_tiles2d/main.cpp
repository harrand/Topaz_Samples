#include "core/peripherals/keyboard.hpp"
#include "core/peripherals/mouse.hpp"
#include "core/tz.hpp"
#include "core/matrix_transform.hpp"
#include "core/time.hpp"
#include "gl/device.hpp"
#include "gl/resource.hpp"
#include "gl/renderer.hpp"

#include "render.hpp"

int main()
{
	// A very basic sample which draws a house in a skybox. Will probably remind you of the early 2000's. Imported shaders but all assets are loaded at runtime. Using extremely basic phong shading.
	tz::initialise
	({
		.name = "Sample 002 - Tiles 2D",
	});
	{
		using namespace tz::literals;

		game::RenderState state;
		// Create renderer.
		tz::gl2::Device dev;
		tz::gl2::Renderer renderer = dev.create_renderer(state.info());
		tz::Delay fixed_update{16670_us};
		while(!tz::window().is_close_requested())
		{
			tz::window().update();
			renderer.render(state.get_triangle_count(renderer));
			state.update(renderer);
			// Fixed update of 60 per second (16.67ms == 16670us).
			if(fixed_update)
			{
				auto is_key_down = [](tz::KeyCode code){return tz::window().get_keyboard_state().is_key_down(tz::peripherals::keyboard::get_key(code));};
				bool casting = tz::window().get_mouse_button_state().is_mouse_button_down(tz::peripherals::mouse::get_mouse_button(tz::MouseButton::Left));

				game::GameRenderInfo& mutable_state = state.get_mutable_state(renderer);
				static tz::Vec2 player_pos = {0.0f, 0.0f};
				constexpr float multiplier = 0.1f;
				tz::Vec4 cam_forward = mutable_state.view_matrix * tz::Vec4{0.0f, 0.0f, -1.0f, 0.0f};
				tz::Vec4 cam_right = mutable_state.view_matrix * tz::Vec4{-1.0f, 0.0f, 0.0f, 0.0f};
				bool moving = false;

				if(is_key_down(tz::KeyCode::W) && !casting)
				{
					player_pos[1] += multiplier;
					state.set_player_keyframe(game::BipedalImageKeyframe::Up);
					moving = true;
				}
				if(is_key_down(tz::KeyCode::A) && !casting)
				{
					player_pos += cam_right.swizzle<0, 1>() * multiplier;
					state.set_player_keyframe(game::BipedalImageKeyframe::HorizontalMove);
					moving = true;
				}
				if(is_key_down(tz::KeyCode::S) && !casting)
				{
					player_pos[1] -= multiplier;
					state.set_player_keyframe(game::BipedalImageKeyframe::Down);
					moving = true;
				}
				if(is_key_down(tz::KeyCode::D) && !casting)
				{
					player_pos -= cam_right.swizzle<0, 1>() * multiplier;
					state.set_player_keyframe(game::BipedalImageKeyframe::HorizontalMove);
					moving = true;
				}
				if(is_key_down(tz::KeyCode::Escape))
				{
					break;
				}
				if(casting)
				{
					state.set_player_keyframe(game::BipedalImageKeyframe::Special);
				}
				else if(!moving)
				{
					state.set_player_keyframe(game::BipedalImageKeyframe::Idle);
				}
				mutable_state.set_camera({0.0f, 0.0f}, 0.0f);
				mutable_state.update_dimensions({tz::window().get_width(), tz::window().get_height()});
				state.get_player_state(renderer).model = tz::model(player_pos.with_more(0.0f), {0.0f, 0.0f, 0.0f}, {2.5f, 2.5f, 2.5f});
				#if TZ_DEBUG
					std::printf("Camera Pos: {%.2f, %.2f}\r", player_pos[0], player_pos[1]);
				#endif
				fixed_update.reset();
			}
		}
	}
	tz::terminate();
	return 0;
}
