cmake_minimum_required( VERSION 3.10 )

project(RayTracingRenderer)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(program src/vector3.cpp src/main.cpp)