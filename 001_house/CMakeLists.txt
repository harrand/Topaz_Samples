add_demo(
	TARGET 001_house
	SOURCE_FILES
		main.cpp
		render.cpp
		render.hpp
		resource.cpp
		resource.hpp
	SHADER_SOURCES
		001_house/draw.vertex.tzsl
		001_house/draw.fragment.tzsl
)
target_link_libraries(001_house samplelib)
