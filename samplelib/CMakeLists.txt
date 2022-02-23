add_subdirectory(lib)

set(CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)

add_library(samplelib
	image_import.cpp
	image_import.hpp
	model_import.cpp
	model_import.hpp
)

target_link_libraries(samplelib PRIVATE assimp stb)
target_link_libraries(samplelib PUBLIC topaz)
target_include_directories(samplelib PUBLIC .)
