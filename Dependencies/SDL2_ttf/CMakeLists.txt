include(FetchContent)

# Paths to your FreeType build
set(FREETYPE_INCLUDE_DIRS "C:/Developer/Libraries/ft2133/freetype-2.13.3/include" CACHE PATH "Path to FreeType headers")
set(FREETYPE_LIBRARY "C:/Developer/Libraries/ft2133/freetype-2.13.3/objs/freetype.a" CACHE FILEPATH "Path to FreeType library")


#find_library(FREETYPE freetype PATHS C:/Developer/Libraries/ft2133/freetype-2.13.3/objs)
#message(STATUS "Found freetype: ${FREETYPE}")

#target_link_libraries(Chess PUBLIC ${FREETYPE})

# Now fetch SDL2_ttf
FetchContent_Declare(
    SDL2_ttf
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
    GIT_TAG release-2.24.0
)
FetchContent_MakeAvailable(SDL2_ttf)
