#include "image_import.hpp"
#define STB_IMAGE_IMPLEMENTATION
// Fixes a crash locally, must have some weird bug or my compiler is borked (something something pthreads)
#define STBI_NO_THREAD_LOCALS
#include "stb_image.h"
#include <set>
#include <filesystem>
#include <cstring>

namespace samplelib
{
	ImageImportResult read_image(const char* relative_path)
	{
		tz_assert(std::filesystem::exists(relative_path), "Attempting to read image at relative path \"%s\", but couldn't find a matching file. Corrupted install?", relative_path);
		int w, h, channels;
		stbi_uc* imgdata = stbi_load(relative_path, &w, &h, &channels, 4);

		ImageImportResult res =
		{
			.success = (imgdata != nullptr),
			.format = tz::gl2::ImageFormat::RGBA32,
			.dimensions = {static_cast<unsigned int>(w), static_cast<unsigned int>(h)},
		};
		res.image_data.resize(w * h * channels);
		std::memcpy(res.image_data.data(), imgdata, w * h * channels);
		stbi_image_free(imgdata);
		return res;
	}
}
