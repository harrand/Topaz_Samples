#include "core/peripherals/keyboard.hpp"
#include "core/tz.hpp"
#include "core/matrix_transform.hpp"
#include "render.hpp"

int main()
{
	// A very basic sample which draws a house in a skybox. All resources and assets are loaded upfront for simplicity.
	tz::initialise
	({
		.name = "Sample 001 - House",
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

			{
				auto is_key_down = [](tz::KeyCode code){return tz::window().get_keyboard_state().is_key_down(tz::peripherals::keyboard::get_key(code));};

				game::GameRenderInfo& mutable_state = state.get_mutable_state(renderer);
				tz::Vec4 cam_pos = {mutable_state.camera_pos[0], mutable_state.camera_pos[1], mutable_state.camera_pos[2], 0.0f};
				tz::Vec3 cam_rot = mutable_state.camera_rot;
				constexpr float multiplier = 0.2f;
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
				if(is_key_down(tz::KeyCode::X))
				{
					cam_pos[1] -= multiplier;
				}
				if(is_key_down(tz::KeyCode::Z))
				{
					cam_pos[1] += multiplier;
				}
				mutable_state.set_camera({cam_pos[0], cam_pos[1], cam_pos[2]}, cam_rot);
				mutable_state.update_dimensions({tz::window().get_width(), tz::window().get_height()});
				#if TZ_DEBUG
					std::printf("Camera Pos: {%.2f, %.2f, %.2f} Rot: {%.2f, %.2f, %.2f}\r", cam_pos[0], cam_pos[1], cam_pos[2], cam_rot[0], cam_rot[1], cam_rot[2]);
				#endif
			}
		}
	}
	tz::terminate();
	return 0;
}
