#ifndef SAMPLE_001_HOUSE_RESOURCES_HPP
#define SAMPLE_001_HOUSE_RESOURCES_HPP
#include "core/vector.hpp"

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
		float pad4;
	};

	using NaiveMesh = std::vector<TriangleVertexData>;
}

#endif // SAMPLE_001_HOUSE_RESOURCES_HPP
