# Assimp is just ginourmous so we're going to disable a bunch of stuff we don't use for quicker iteration.
set(ASSIMP_NO_EXPORT ON)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
set(ASSIMP_BUILD_TESTS OFF)


add_subdirectory(assimp)
# add_subdirectory(stb)

add_library(stb INTERFACE)
target_include_directories(stb INTERFACE stb)
