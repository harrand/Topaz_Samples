#ifndef TOPAZ_SAMPLES_SAMPLELIB_MODEL_IMPORT_HPP
#define TOPAZ_SAMPLES_SAMPLELIB_MODEL_IMPORT_HPP
#include "tz/core/vector.hpp"
#include "tz/core/containers/basic_list.hpp"

namespace samplelib
{
	struct Vertex
	{
		tz::Vec3 position;
		tz::Vec2 texcoord;
		tz::Vec3 normal;
		tz::Vec3 tangent;
		tz::Vec3 bitangent;
	};

	struct Mesh
	{
		tz::BasicList<Vertex> vertices;
	};

	Mesh load_mesh(const char* relative_path);
}

#endif // TOPAZ_SAMPLES_SAMPLELIB_MODEL_IMPORT_HPP
