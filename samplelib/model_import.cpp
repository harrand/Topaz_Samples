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
		// Now go through and calculate tangent space.
		for(std::size_t i = 0; i < ret.vertices.length(); i += 3)
		{
			tz::Vec3& v0 = ret.vertices[i + 0].position;
			tz::Vec3& v1 = ret.vertices[i + 1].position;
			tz::Vec3& v2 = ret.vertices[i + 2].position;

			tz::Vec2 uv0 = ret.vertices[i + 0].texcoord;
			tz::Vec2 uv1 = ret.vertices[i + 1].texcoord;
			tz::Vec2 uv2 = ret.vertices[i + 2].texcoord;

			tz::Vec3 delta1 = v1 - v0;
			tz::Vec3 delta2 = v2 - v0;

			tz::Vec2 uvdelta1 = uv1 - uv0;
			tz::Vec2 uvdelta2 = uv2 - uv0;

			float r = 1.0f / (uvdelta1[0] * uvdelta2[1] - uvdelta1[1] * uvdelta2[0]);
			tz::Vec3 tangent = (delta1 * uvdelta2[1] - delta2 * uvdelta1[1]) * r;
			tz::Vec3 bitangent = (delta2 * uvdelta1[0] - delta1 * uvdelta2[0]) * r;

			ret.vertices[i + 0].tangent = ret.vertices[i + 1].tangent = ret.vertices[i + 2].tangent = tangent;
			ret.vertices[i + 0].bitangent = ret.vertices[i + 1].bitangent = ret.vertices[i + 2].bitangent = bitangent;
		}
		return ret;
	}
}
