#include "resource.hpp"
#include "tz/core/matrix_transform.hpp"

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
			case ImageName::StoneBricks_NormalMap:
				filename = "../../001_house/data/images/stonebricks_normal.png";
			break;
			case ImageName::StoneBricks_ParallaxMap:
				filename = "../../001_house/data/images/stonebricks_parallax.png";
			break;
			case ImageName::Birch:
				filename = "../../001_house/data/images/birch.png";
			break;
			case ImageName::Birch_NormalMap:
				filename = "../../001_house/data/images/birch_normal.png";
			break;
			case ImageName::Birch_ParallaxMap:
				filename = "../../001_house/data/images/birch_parallax.png";
			break;
			case ImageName::Wood:
				filename = "../../001_house/data/images/wood.png";
			break;
			case ImageName::Wood_NormalMap:
				filename = "../../001_house/data/images/wood_normal.png";
			break;
			case ImageName::Wood_ParallaxMap:
				filename = "../../001_house/data/images/wood_parallax.png";
			break;
			default:
				tz_error("Unrecognised image name. Please submit a bug report");
			break;

		}
		return samplelib::read_float_image(filename);
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
		add_mesh("../../001_house/data/models/cube.obj", 11);
		add_mesh("../../001_house/data/models/cube.obj", 12);
		add_mesh("../../001_house/data/models/cube.obj", 13);
		add_mesh("../../001_house/data/models/cube.obj", 14);
		add_mesh("../../001_house/data/models/cylinder.obj", 15);
		add_mesh("../../001_house/data/models/cube.obj", 16);
		add_mesh("../../001_house/data/models/cube.obj", 17);
		add_mesh("../../001_house/data/models/cube.obj", 18);
		add_mesh("../../001_house/data/models/cube.obj", 19);
		add_mesh("../../001_house/data/models/cube.obj", 20);
		add_mesh("../../001_house/data/models/cylinder.obj", 21);
		add_mesh("../../001_house/data/models/cylinder.obj", 22);
		add_mesh("../../001_house/data/models/cylinder.obj", 23);
		add_mesh("../../001_house/data/models/cylinder.obj", 24);
		add_mesh("../../001_house/data/models/cube.obj", 25);
		add_mesh("../../001_house/data/models/cube.obj", 26);
		add_mesh("../../001_house/data/models/cube.obj", 27);
		add_mesh("../../001_house/data/models/cube.obj", 28);
		add_mesh("../../001_house/data/models/cube.obj", 29);
		add_mesh("../../001_house/data/models/cube.obj", 30);
		add_mesh("../../001_house/data/models/cube.obj", 31);
		add_mesh("../../001_house/data/models/cube.obj", 32);
		add_mesh("../../001_house/data/models/cube.obj", 33);
		add_mesh("../../001_house/data/models/cube.obj", 34);
		add_mesh("../../001_house/data/models/cube.obj", 35);
		add_mesh("../../001_house/data/models/cube.obj", 36);
		add_mesh("../../001_house/data/models/cube.obj", 37);
		add_mesh("../../001_house/data/models/cube.obj", 38);
		add_mesh("../../001_house/data/models/cube.obj", 39);
		add_mesh("../../001_house/data/models/cube.obj", 40);
		add_mesh("../../001_house/data/models/cube.obj", 41);
		add_mesh("../../001_house/data/models/torus.obj", 42);
		add_mesh("../../001_house/data/models/torus.obj", 43);
		add_mesh("../../001_house/data/models/cube.obj", 44);
		add_mesh("../../001_house/data/models/cube.obj", 45);
		add_mesh("../../001_house/data/models/cube.obj", 46);
		add_mesh("../../001_house/data/models/cube.obj", 47);
		add_mesh("../../001_house/data/models/cube.obj", 48);
		add_mesh("../../001_house/data/models/cube.obj", 49);
		add_mesh("../../001_house/data/models/cube.obj", 50);
		add_mesh("../../001_house/data/models/cube.obj", 51);
		add_mesh("../../001_house/data/models/cube.obj", 52);
		add_mesh("../../001_house/data/models/cube.obj", 53);
		add_mesh("../../001_house/data/models/cube.obj", 54);
		add_mesh("../../001_house/data/models/cube.obj", 55);
		add_mesh("../../001_house/data/models/cube.obj", 56);
		add_mesh("../../001_house/data/models/cylinder.obj", 57);
		add_mesh("../../001_house/data/models/cylinder.obj", 58);
		add_mesh("../../001_house/data/models/cylinder.obj", 59);
		add_mesh("../../001_house/data/models/cylinder.obj", 60);
		add_mesh("../../001_house/data/models/cube.obj", 61);
		add_mesh("../../001_house/data/models/cube.obj", 62);
		add_mesh("../../001_house/data/models/cube.obj", 63);
		add_mesh("../../001_house/data/models/cube.obj", 64);
		add_mesh("../../001_house/data/models/cube.obj", 65);
		add_mesh("../../001_house/data/models/cube.obj", 66);
		add_mesh("../../001_house/data/models/cube.obj", 67);
		add_mesh("../../001_house/data/models/cube.obj", 68);
		add_mesh("../../001_house/data/models/cube.obj", 69);
		add_mesh("../../001_house/data/models/cube.obj", 70);
		add_mesh("../../001_house/data/models/cylinder.obj", 71);
		return ret;
	}

	std::array<ObjectInfo, 72> get_object_data()
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
			}, // next is object11
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 0.0f, 1200.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 0.0f, -1200.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 470.0f, 1600.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 470.0f, -1600.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 900.0f, 0.0f}, {1.5708f, 0.0f, 0.0f}, {1400.0f, 1000.0f, 1400.0f}),
				.texture_id = 2
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 1400.0f, 800.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 1400.0f, -800.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 1400.0f, 1600.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 1400.0f, -1600.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 1400.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 935.0f, 2000.0f}, {0.0f, 0.0f, 0.0f}, {1300.0f, 450.0f, 1300.0f}),
				.texture_id = 2
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 935.0f, -2000.0f}, {0.0f, 0.0f, 0.0f}, {1300.0f, 450.0f, 1300.0f}),
				.texture_id = 2
			},
			ObjectInfo
			{
				.model = tz::model({-2300.0f, 900.0f, 2000.0f}, {1.5708f, 1.5708f, 0.0f}, {1400.0f, 450.0f, 1400.0f}),
				.texture_id = 2
			},
			ObjectInfo
			{
				.model = tz::model({-2300.0f, 900.0f, -2000.0f}, {1.5708f, 1.5708f, 0.0f}, {1400.0f, 450.0f, 1400.0f}),
				.texture_id = 2
			},
			ObjectInfo
			{
				.model = tz::model({-1800.0f, 470.0f, -2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-2600.0f, 470.0f, -2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-1800.0f, 1400.0f, -2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			}, // next is object28
			ObjectInfo
			{
				.model = tz::model({-2600.0f, 1400.0f, -2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-1800.0f, 470.0f, 2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-2600.0f, 470.0f, 2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-1800.0f, 1400.0f, 2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-2600.0f, 1400.0f, 2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 0.0f, -2400.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-2600.0f, 0.0f, -2400.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-3800.0f, 0.0f, -2400.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 0.0f, 2400.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-2600.0f, 0.0f, 2400.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-3800.0f, 0.0f, 2400.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-3800.0f, 0.0f, 1200.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-3800.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-3800.0f, 0.0f, -1200.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 200.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {70.0f, 70.0f, 70.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-1400.0f, 600.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {70.0f, 70.0f, 70.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-5000.0f, 0.0f, 2400.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-5000.0f, 0.0f, 1200.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-5000.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-5000.0f, 0.0f, -1200.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-5000.0f, 0.0f, -2400.0f}, {0.0f, 0.0f, 0.0f}, {600.0f, 40.0f, 600.0f}),
				.texture_id = 1
			},
			ObjectInfo
			{
				.model = tz::model({-3400.0f, 470.0f, -2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-3400.0f, 1400.0f, -2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4200.0f, 470.0f, -2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4200.0f, 1400.0f, -2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-3400.0f, 470.0f, 2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-3400.0f, 1400.0f, 2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4200.0f, 470.0f, 2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4200.0f, 1400.0f, 2000.0f}, {0.0f, 0.0f, 0.0f}, {400.0f, 430.0f, 100.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-3700.0f, 900.0f, 2000.0f}, {1.5708f, 1.5708f, 0.0f}, {1400.0f, 450.0f, 1400.0f}),
				.texture_id = 2
			},
			ObjectInfo
			{
				.model = tz::model({-3700.0f, 900.0f, -2000.0f}, {1.5708f, 1.5708f, 0.0f}, {1400.0f, 450.0f, 1400.0f}),
				.texture_id = 2
			},
			ObjectInfo
			{
				.model = tz::model({-4600.0f, 935.0f, -2000.0f}, {0.0f, 0.0f, 0.0f}, {1300.0f, 450.0f, 1300.0f}),
				.texture_id = 2
			},
			ObjectInfo
			{
				.model = tz::model({-4600.0f, 935.0f, 2000.0f}, {0.0f, 0.0f, 0.0f}, {1300.0f, 450.0f, 1300.0f}),
				.texture_id = 2
			},
			ObjectInfo
			{
				.model = tz::model({-4600.0f, 470.0f, 800.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4600.0f, 470.0f, -800.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4600.0f, 1400.0f, 800.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4600.0f, 1400.0f, -800.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4600.0f, 1400.0f, 1600.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4600.0f, 1400.0f, -1600.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4600.0f, 470.0f, 1600.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4600.0f, 470.0f, -1600.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4600.0f, 470.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4600.0f, 1400.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {100.0f, 430.0f, 400.0f}),
				.texture_id = 0
			},
			ObjectInfo
			{
				.model = tz::model({-4600.0f, 900.0f, 0.0f}, {1.5708f, 0.0f, 0.0f}, {1400.0f, 1400.0f, 1400.0f}),
				.texture_id = 2
			}



		};
	}
}
