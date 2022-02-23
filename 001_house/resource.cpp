#include "resource.hpp"

namespace game
{
	NaiveMesh get_world_mesh()
	{
		return {{}};
	}

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
}
