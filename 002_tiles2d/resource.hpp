#include "core/matrix.hpp"
#include "core/matrix_transform.hpp"
#include "core/vector.hpp"
#include <vector>

namespace game
{
	struct ObjectInfo
	{
		tz::Mat4 model = tz::model({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f});
		std::uint32_t texture_id = 0;
		float pad0[3];
	};
}
