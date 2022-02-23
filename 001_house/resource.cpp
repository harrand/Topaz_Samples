#include "resource.hpp"

namespace game
{

	samplelib::ImageImportResult get_image(ImageName name)
	{
		const char* filename;
		switch(name)
		{
			case ImageName::StoneBricks:
				filename = "../../001_house/data/images/stonebricks.png";
			break;
			case ImageName::Birch:
				filename = "../../001_house/data/images/birch.png";
			break;
			case ImageName::Wood:
				filename = "../../001_house/data/images/wood.png";
			break;
			default:
				tz_error("Unrecognised image name. Please submit a bug report");
			break;

		}
		return samplelib::read_image(filename);
	}

	NaiveMesh get_world_mesh()
	{
		samplelib::Mesh mesh = samplelib::load_mesh("../../001_house/data/models/cube.obj");

		NaiveMesh ret;
		ret.resize(mesh.vertices.length());
		std::transform(mesh.vertices.begin(), mesh.vertices.end(), ret.begin(),
		[](const samplelib::Vertex& v) -> TriangleVertexData
		{
			return
			{
				.position = v.position,
				.texcoord = v.texcoord,
				.normal = v.normal,
				.tangent = v.tangent,
				.bitangent = v.bitangent
			};
		});
		return ret;
	}
}
