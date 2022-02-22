add_subdirectory(engine)

set(CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Topaz_Samples)

add_demo(
	TARGET 001_house
	SOURCE_FILES 001_house/main.cpp
)
