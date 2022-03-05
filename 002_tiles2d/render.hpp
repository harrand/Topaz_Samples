#ifndef TOPAZ_SAMPLES_TILES2D_RENDER_HPP
#define TOPAZ_SAMPLES_TILES2D_RENDER_HPP
#include "resource.hpp"
#include "core/vector.hpp"
#include "core/matrix.hpp"
#include "core/time.hpp"
#include "gl/renderer.hpp"
#include "gl/resource.hpp"

#include "image_import.hpp" // samplelib
#include <array>
#include <unordered_map>

namespace game
{
	struct GameRenderInfo
	{
		tz::Vec2 camera_pos = {0.0f, 0.0f};
		float camera_rot = 0.0f;
		float pad0;
		tz::Mat4 view_matrix = tz::Mat4::identity();
		tz::Mat4 projection_matrix = tz::Mat4::identity();

		void set_camera(tz::Vec2 cam_pos, float cam_rot);
		void update_dimensions(tz::Vec2 viewport_dimensions);
	};

	struct TextureStorage
	{
		struct Element
		{
			Element(const char* path);

			samplelib::ImageImportResult data;
			tz::gl2::ImageResource image;
		};
		tz::BasicList<Element> textures;
	};

	enum class BipedalImageKeyframe
	{
		Idle,
		Dead,
		Special,
		HorizontalMove,
		Up,
		Down
	};

	class BipedalAnimation
	{
	public:
		BipedalAnimation(std::uint32_t idle_texture_id);
		void set_keyframe(BipedalImageKeyframe keyframe);
		void update();
		std::uint32_t get_texture_id() const;
	private:
		std::uint32_t idle_texture_id;
		tz::Delay delay;
		BipedalImageKeyframe key_frame = BipedalImageKeyframe::Idle;
		std::size_t anim_frame_id = 0;
	};

	class RenderState
	{
	public:
		RenderState();
		void update(tz::gl2::Renderer& renderer);
		const tz::gl2::RendererInfo& info() const;
		std::size_t get_triangle_count(tz::gl2::Renderer& renderer) const;
		GameRenderInfo& get_mutable_state(tz::gl2::Renderer& renderer);
		std::span<ObjectInfo> get_scene_object_state(tz::gl2::Renderer& renderer);
		ObjectInfo& get_player_state(tz::gl2::Renderer& renderer);
		void set_player_keyframe(BipedalImageKeyframe keyframe);
		ObjectInfo& get_orb_state(tz::gl2::Renderer& renderer);
	private:
		std::span<ObjectInfo> get_entire_object_state(tz::gl2::Renderer& renderer);
		tz::gl2::RendererInfo rinfo;
		tz::gl2::BufferResource game_buf;
		tz::gl2::BufferResource object_storage_buf;
		tz::gl2::ResourceHandle game_buffer_handle;
		tz::gl2::ResourceHandle object_storage_buffer_handle;
		TextureStorage textures;
		std::unordered_map<std::size_t, BipedalAnimation> animations{{0, BipedalAnimation{3}}};
	};
}

#endif // TOPAZ_SAMPLES_TILES2D_RENDER_HPP
