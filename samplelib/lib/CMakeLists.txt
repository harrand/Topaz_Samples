# add_subdirectory(stb)
# add_subdirectory(tinyobjloader)

add_library(stb INTERFACE)
target_include_directories(stb INTERFACE stb)

add_library(tinyobjloader INTERFACE)
target_include_directories(tinyobjloader INTERFACE tinyobjloader)