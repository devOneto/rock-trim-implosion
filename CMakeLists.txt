cmake_minimum_required( VERSION 3.10 )

project(RockTrimImplosion)

find_package(SDL2 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(program src/sphere.cpp src/ray.cpp src/color.cpp src/vector3.cpp src/main.cpp)

target_link_libraries(program SDL2::SDL2)