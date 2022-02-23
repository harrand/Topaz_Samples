#include "image_import.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <set>
#include <filesystem>

namespace samplelib
{
	std::set<stbi_uc*> read_images = {};

	ImageImportResult read_image(const char* relative_path)
	{
		tz_assert(std::filesystem::exists(relative_path), "Attempting to read image at relative path \"%s\", but couldn't find a matching file. Corrupted install?", relative_path);
		int w, h, channels;
		stbi_uc* imgdata = stbi_load(relative_path, &w, &h, &channels, 3);
		// TODO: Purge this data at some point, it leaks.
		read_images.insert(imgdata);

		return
		{
			.success = (imgdata != nullptr),
			.format = tz::gl2::ImageFormat::RGB24,
			.dimensions = {static_cast<unsigned int>(w), static_cast<unsigned int>(h)},
			.image_data = {reinterpret_cast<const std::byte*>(imgdata), static_cast<std::size_t>(4 * w * h)}
		};
	}
}
