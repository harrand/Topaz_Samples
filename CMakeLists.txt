add_subdirectory(engine)
add_subdirectory(samplelib)

set(CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(001_house)
add_subdirectory(002_tiles2d)

