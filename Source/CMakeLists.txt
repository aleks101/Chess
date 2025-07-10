set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Build/bin")

file(GLOB_RECURSE SRC_FILES *.cpp)

add_executable(Chess ${SRC_FILES})

target_link_libraries(Chess
    SDL2::SDL2main
    SDL2::SDL2
    SDL2_image::SDL2_image
    ${FREETYPE}
    SDL2_ttf::SDL2_ttf
    SDL2_mixer::SDL2_mixer
)