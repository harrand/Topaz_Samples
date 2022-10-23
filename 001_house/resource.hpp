#ifndef SAMPLE_001_HOUSE_RESOURCES_HPP
#define SAMPLE_001_HOUSE_RESOURCES_HPP
#include "image_import.hpp" // samplelib
#include "model_import.hpp" // samplelib
#include "tz/core/vector.hpp"
#include "tz/core/matrix.hpp"
#include <vector>
#include <array>

namespace game
{
	struct TriangleVertexData
	{
		tz::Vec3 position;
		float pad0;
		tz::Vec2 texcoord;
		float pad1[2];
		tz::Vec3 normal;
		float pad2;
		tz::Vec3 tangent;
		float pad3;
		tz::Vec3 bitangent;
		std::uint32_t object_id;
	};

	using NaiveMesh = std::vector<TriangleVertexData>;

	enum class ImageName
	{
		StoneBricks,
		StoneBricks_NormalMap,
		StoneBricks_ParallaxMap,
		Birch,
		Birch_NormalMap,
		Birch_ParallaxMap,
		Wood,
		Wood_NormalMap,
		Wood_ParallaxMap
	};

	samplelib::ImageImportResult get_image(ImageName name);

	NaiveMesh get_world_mesh();

	struct ObjectInfo
	{
		tz::Mat4 model;
		std::uint32_t texture_id;
		float pad0[3];
	};

	std::array<ObjectInfo, 72> get_object_data();
}

#endif // SAMPLE_001_HOUSE_RESOURCES_HPP
