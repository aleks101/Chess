# Requirements
## Cmake
CMake download https://cmake.org/download/

## Compiler
Make sure to have a compiler installed on your computer

## Installed FreeType library
FreeType library repository https://github.com/freetype/freetype/tree/master
To build freetype library you need to run make twice in the root folder of freetype, building documentation for more details https://github.com/freetype/freetype/tree/master/docs, 
after building the library you must provide a path of the lib file which is located inside objs folder to cmake(script is located in Depedencies/SDL2_ttf). 

```
set(FREETYPE_INCLUDE_DIRS "C:/Developer/Libraries/ft2133/freetype-2.13.3/include" CACHE PATH "Path to FreeType headers")
set(FREETYPE_LIBRARY "C:/Developer/Libraries/ft2133/freetype-2.13.3/objs/freetype.a" CACHE FILEPATH "Path to FreeType library")
```

# Building/compiling the project
If you have installed and build all the dependencies, you can now build the game. Run cmake script from the build folder and then make to compile the program, after compiling the .exe file will be generated inside build/bin folder

cmake generators https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html

Project root folder:
```
mkdir build
cd build

cmake .. -G "generator"
make
```
