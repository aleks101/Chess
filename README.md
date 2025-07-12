# Requirements
## Git
Git download https://git-scm.com/downloads/win

## Cmake
CMake download https://cmake.org/download/

## Compiler
Make sure to have a compiler installed on your computer https://www.mingw-w64.org/downloads/

## Installed FreeType library
FreeType library repository https://sourceforge.net/projects/freetype/
To build freetype library you need to run make twice in the root folder of freetype, building documentation for more details https://github.com/freetype/freetype/tree/master/docs, 
after building the library you must provide a path of the lib file which is located inside objs folder to cmake(script is located in Depedencies/SDL2_ttf). 

```
set(FREETYPE_INCLUDE_DIRS "path/to/freetype/include" CACHE PATH "Path to FreeType headers")
set(FREETYPE_LIBRARY "path/to/freetype/objs/freetype.a" CACHE FILEPATH "Path to FreeType library")
```

# Building/compiling the project
If you have installed and build all the dependencies, you can now build the game. Run cmake script from the build folder and then make to compile the program, after compiling the .exe file will be generated inside build/bin folder

**To successfuly run the .exe file you will have to copy the Files folder into the folder that contains the .exe file**


cmake generators https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html

Project root folder:
```
mkdir build
cd build

cmake .. -G "set your generator"
make
```

