#include "tz/core/peripherals/keyboard.hpp"
#include "tz/core/peripherals/mouse.hpp"
#include "tz/core/tz.hpp"
#include "tz/core/matrix_transform.hpp"
#include "tz/core/time.hpp"
#include "tz/dbgui/dbgui.hpp"
#include "render.hpp"

int main()
{
	// A very basic sample which draws a house in a skybox. Will probably remind you of the early 2000's. Imported shaders but all assets are loaded at runtime. Using extremely basic phong shading.
	tz::initialise
	({
		.name = "Sample 001 - House",
	});
	{
		using namespace tz::literals;
		game::RenderState state;
		// Create renderer.
		tz::gl::RendererHandle rendererh = tz::gl::device().create_renderer(state.info());
		tz::gl::Renderer& renderer = tz::gl::device().get_renderer(rendererh);
		tz::Delay fixed_update{16670_us};
		bool game_menu_enabled = false;

		tz::dbgui::game_menu().add_callback([&game_menu_enabled]()
		{
			ImGui::MenuItem("Sample Info", nullptr, &game_menu_enabled);
		});


		while(!tz::window().is_close_requested())
		{
			tz::window().begin_frame();
			renderer.render(state.get_triangle_count());

			tz::dbgui::run([&state, &renderer, &game_menu_enabled]()
			{
				if(game_menu_enabled)
				{
					ImGui::Begin("Sample Info", &game_menu_enabled);
					ImGui::DragFloat("Reinhard Constant", &state.get_lighting_state(renderer).mapping_constant, 0.01f, 0.0f, 5.0f);
					ImGui::DragFloat("Gamma", &state.get_lighting_state(renderer).gamma, 0.01f, 0.0f, 50.0f);
					ImGui::DragFloat4("Light Wattage", state.get_lighting_state(renderer).light_powers.data().data());
					ImGui::End();
				}
			});

			// Fixed update of 60 per second (16.67ms == 16670us).
			if(fixed_update)
			{
				auto is_key_down = [](tz::KeyCode code){return tz::window().get_keyboard_state().is_key_down(code);};
				game::GameRenderInfo& mutable_state = state.get_mutable_state(renderer);
				tz::Vec4 cam_pos = mutable_state.camera_pos.with_more(0.0f);
				tz::Vec3 cam_rot = mutable_state.camera_rot;
				constexpr float multiplier = 25.0f;
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
				auto mpi = static_cast<tz::Vec2i>(tz::window().get_mouse_position_state().get_mouse_position());
				if(tz::window().get_mouse_button_state().is_mouse_button_down(tz::MouseButton::Left) && !tz::dbgui::claims_mouse())
				{
					// Get mouse delta since last frame.
					tz::Vec2i mouse_delta = mpi - mouse_position;
					constexpr float rot_multiplier = 0.003f;
					cam_rot[1] -= mouse_delta[0] * rot_multiplier;
					cam_rot[0] -= mouse_delta[1] * rot_multiplier;
				}
				mouse_position = mpi;
				mutable_state.set_camera(cam_pos.swizzle<0, 1, 2>(), cam_rot);
				mutable_state.update_dimensions({tz::window().get_width(), tz::window().get_height()});
				#if TZ_DEBUG
					std::printf("Camera Pos: {%.2f, %.2f, %.2f} Rot: {%.2f, %.2f, %.2f}\r", cam_pos[0], cam_pos[1], cam_pos[2], cam_rot[0], cam_rot[1], cam_rot[2]);
				#endif
				fixed_update.reset();
			}
			tz::window().end_frame();
		}
	}
	tz::terminate();
	return 0;
}
