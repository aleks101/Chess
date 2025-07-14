include(FetchContent)

# Disable optional dependencies that are not needed or not linked
set(FT_DISABLE_ZLIB TRUE CACHE BOOL "Disable ZLIB support in FreeType" FORCE)
set(FT_DISABLE_PNG TRUE CACHE BOOL "Disable PNG support in FreeType" FORCE)
set(FT_DISABLE_BZIP2 TRUE CACHE BOOL "Disable BZip2 support in FreeType" FORCE)
set(FT_DISABLE_HARFBUZZ TRUE CACHE BOOL "Disable HarfBuzz support in FreeType" FORCE)
set(FT_DISABLE_BROTLI TRUE CACHE BOOL "Disable Brotli support in FreeType" FORCE)

# Now fetch FreeType
FetchContent_Declare(
    FreeType
    GIT_REPOSITORY https://github.com/freetype/freetype.git
    GIT_TAG VER-2-13-3
)
FetchContent_MakeAvailable(FreeType)

# Tell SDL2_ttf where FreeType is
set(FREETYPE_INCLUDE_DIRS
    "${freetype_SOURCE_DIR}/include"
    "${freetype_BINARY_DIR}/include"
    CACHE PATH "Path to FreeType headers" FORCE
)

set(FREETYPE_LIBRARY
    "${freetype_BINARY_DIR}/libfreetype.a"
    CACHE FILEPATH "Path to FreeType library" FORCE
)