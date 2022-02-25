#include "resource.hpp"
#include "core/matrix_transform.hpp"

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
		NaiveMesh ret;
		auto add_mesh = [&ret](const char* mesh_relative_path, std::uint32_t object_id)
		{
			samplelib::Mesh mesh = samplelib::load_mesh(mesh_relative_path);
			std::transform(mesh.vertices.begin(), mesh.vertices.end(), std::back_inserter(ret),
			[object_id](const samplelib::Vertex& v) -> TriangleVertexData
			{
				return
				{
					.position = v.position,
					.texcoord = v.texcoord,
					.normal = v.normal,
					.tangent = v.tangent,
					.bitangent = v.bitangent,
					.object_id = object_id
				};
			});
		};
		add_mesh("../../001_house/data/models/cube.obj", 0);
		add_mesh("../../001_house/data/models/cube.obj", 1);
		add_mesh("../../001_house/data/models/cube.obj", 2);
		add_mesh("../../001_house/data/models/cylinder.obj", 3);
		add_mesh("../../001_house/data/models/cube.obj", 4);
		add_mesh("../../001_house/data/models/cube.obj", 5);
		add_mesh("../../001_house/data/models/cube.obj", 6);
		add_mesh("../../001_house/data/models/cube.obj", 7);
		add_mesh("../../001_house/data/models/cube.obj", 8);
		add_mesh("../../001_house/data/models/cube.obj", 9);
		add_mesh("../../001_house/data/models/cube.obj", 10);
		return ret;
	}

	std::array<ObjectInfo, 11> get_object_data()
	{
		return
		{
			ObjectInfo
			{
				.model = tz::model({0.0f, -100.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {800.0f, 100.0f, 800.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-2600.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 400.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {800.0f, 200.0f, 800.0f}),
				.texture_id = 2
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 800.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 100.0f, 400.0f}),
				.texture_id = 2
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 470.0f, 800.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 470.0f, -800.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({0.0f, -100.0f, 1600.0f}, {0.0f, 0.0f, 0.0f}, {800.0f, 100.0f, 800.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({0.0f, -100.0f, -1600.0f}, {0.0f, 0.0f, 0.0f}, {800.0f, 100.0f, 800.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-2600.0f, 0.0f, 1200.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-2600.0f, 0.0f, -1200.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			} // next is object11
		};
	}
}
