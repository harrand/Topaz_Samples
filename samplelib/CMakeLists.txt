add_subdirectory(lib)

set(CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)

add_library(samplelib
	image_import.cpp
	image_import.hpp
)

target_link_libraries(samplelib PUBLIC assimp stb topaz)
target_include_directories(samplelib PUBLIC .)
