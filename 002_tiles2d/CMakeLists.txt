add_demo(
	TARGET 002_tiles2d
	SOURCE_FILES
		main.cpp
		render.cpp
		render.hpp
		resource.cpp
		resource.hpp
	SHADER_SOURCES
		002_tiles2d/draw.vertex.tzsl
		002_tiles2d/draw.fragment.tzsl
)
target_link_libraries(002_tiles2d samplelib)
