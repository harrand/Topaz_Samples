#include "core/peripherals/keyboard.hpp"
#include "core/peripherals/mouse.hpp"
#include "core/tz.hpp"
#include "core/matrix_transform.hpp"
#include "core/time.hpp"
#include "render.hpp"

int main()
{
	// A very basic sample which draws a house in a skybox. All resources and assets are loaded upfront for simplicity.
	tz::initialise
	({
		.name = "Sample 001 - House",
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
			renderer.render(state.get_triangle_count());
			// Fixed update of 60 per second (16.67ms == 16670us).
			if(fixed_update)
			{
				auto is_key_down = [](tz::KeyCode code){return tz::window().get_keyboard_state().is_key_down(tz::peripherals::keyboard::get_key(code));};

				game::GameRenderInfo& mutable_state = state.get_mutable_state(renderer);
				tz::Vec4 cam_pos = {mutable_state.camera_pos[0], mutable_state.camera_pos[1], mutable_state.camera_pos[2], 0.0f};
				tz::Vec3 cam_rot = mutable_state.camera_rot;
				constexpr float multiplier = 10.0f;
				tz::Vec4 cam_forward = mutable_state.view_matrix * tz::Vec4{0.0f, 0.0f, -1.0f, 0.0f};
				tz::Vec4 cam_right = mutable_state.view_matrix * tz::Vec4{-1.0f, 0.0f, 0.0f, 0.0f};
				if(is_key_down(tz::KeyCode::W))
				{
					cam_pos += cam_forward * multiplier;
				}
				if(is_key_down(tz::KeyCode::A))
				{
					cam_pos += cam_right * multiplier;
				}
				if(is_key_down(tz::KeyCode::S))
				{
					cam_pos -= cam_forward * multiplier;
				}
				if(is_key_down(tz::KeyCode::D))
				{
					cam_pos -= cam_right * multiplier;
				}
				if(is_key_down(tz::KeyCode::Space))
				{
					cam_pos[1] += multiplier;
				}
				if(is_key_down(tz::KeyCode::LeftShift))
				{
					cam_pos[1] -= multiplier;
				}
				if(is_key_down(tz::KeyCode::Escape))
				{
					break;
				}
				static tz::Vec2i mouse_position;
				tz::Vec2ui mp = tz::window().get_mouse_position_state().get_mouse_position();
				tz::Vec2i mpi{static_cast<int>(mp[0]), static_cast<int>(mp[1])};
				if(tz::window().get_mouse_button_state().is_mouse_button_down(tz::peripherals::mouse::get_mouse_button(tz::MouseButton::Left)))
				{
					// Get mouse delta since last frame.
					tz::Vec2i mouse_delta = mpi - mouse_position;
					constexpr float rot_multiplier = 0.003f;
					cam_rot[1] -= mouse_delta[0] * rot_multiplier;
					cam_rot[0] -= mouse_delta[1] * rot_multiplier;
				}
				mouse_position = mpi;
				mutable_state.set_camera({cam_pos[0], cam_pos[1], cam_pos[2]}, cam_rot);
				mutable_state.update_dimensions({tz::window().get_width(), tz::window().get_height()});
				#if TZ_DEBUG
					std::printf("Camera Pos: {%.2f, %.2f, %.2f} Rot: {%.2f, %.2f, %.2f}\r", cam_pos[0], cam_pos[1], cam_pos[2], cam_rot[0], cam_rot[1], cam_rot[2]);
				#endif
				fixed_update.reset();
			}
		}
	}
	tz::terminate();
	return 0;
}
