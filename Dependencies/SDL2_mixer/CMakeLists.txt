include(FetchContent)

set(SDL2MIXER_VENDORED ON CACHE BOOL "" FORCE)

FetchContent_Declare(
    SDL2_mixer
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
    GIT_TAG release-2.8.1
)

FetchContent_MakeAvailable(SDL2_mixer)