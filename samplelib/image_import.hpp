#ifndef TOPAZ_SAMPLES_SAMPLELIB_IMAGE_IMPORT_HPP
#define TOPAZ_SAMPLES_SAMPLELIB_IMAGE_IMPORT_HPP
#include "tz/core/vector.hpp"
#include "tz/gl/declare/image_format.hpp"
#include <cstddef>
#include <vector>

namespace samplelib
{
	struct ImageImportResult
	{
		bool success;
		tz::gl::ImageFormat format;
		tz::Vec2ui dimensions;
		std::vector<std::byte> image_data;
	};

	ImageImportResult read_image(const char* relative_path);
}

#endif // TOPAZ_SAMPLES_SAMPLELIB_IMAGE_IMPORT_HPP
