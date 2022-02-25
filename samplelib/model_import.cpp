#include "model_import.hpp"
#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

namespace samplelib
{
	Mesh load_mesh(const char* relative_path)
	{
		tinyobj::attrib_t attrib;
		std::vector<tinyobj::shape_t> shapes;
		std::vector<tinyobj::material_t> materials;
		std::string warn, err;

		auto res = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, relative_path);
		tz_assert(res, "Failed to load mesh from file \"%s\": %s", relative_path, (warn + err).c_str());
		Mesh ret;
		for(const tinyobj::shape_t& shape : shapes)
		{
			for(const tinyobj::index_t& index : shape.mesh.indices)
			{
				ret.vertices.add
				({
					.position =
					{
						attrib.vertices[3 * index.vertex_index + 0],
						attrib.vertices[3 * index.vertex_index + 1],
						attrib.vertices[3 * index.vertex_index + 2]
					},
					.texcoord =
					{
						attrib.texcoords[2 * index.texcoord_index + 0],
						attrib.texcoords[2 * index.texcoord_index + 1]
					},
					.normal =
					{
						attrib.normals[3 * index.normal_index + 0],
						attrib.normals[3 * index.normal_index + 1],
						attrib.normals[3 * index.normal_index + 2]
					},
					.tangent = {0.0f, 0.0f, 0.0f},
					.bitangent = {0.0f, 0.0f, 0.0f}
				});
			}
		}
		return ret;
	}
}
