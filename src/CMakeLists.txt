cmake_minimum_required(VERSION 2.6)

SET (CMAKE_CXX_COMPILER  "/usr/bin/clang++")
#SET (CMAKE_CXX_FLAGS     "-fno-omit-frame-pointer -pedantic -Werror -Wall  -std=c++11 -g")

find_package(GLEW REQUIRED)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})


add_executable(PegSolitaire display shader mesh stb_image texture main Peg Board )

target_link_libraries(PegSolitaire ${SDL2_LIBRARIES} GLEW GL)

FILE(COPY ${CMAKE_SOURCE_DIR}/src/res DESTINATION ${CMAKE_BINARY_DIR}/src)
