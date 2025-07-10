cmake_minimum_required(VERSION 3.15)

project(Chess)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Dependencies)
add_subdirectory(Source)
add_subdirectory(Include)