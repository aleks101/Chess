# Requirements
## Git
Git download https://git-scm.com/downloads/win

## Cmake
CMake download https://cmake.org/download/

## Compiler
Make sure to have a compiler installed on your computer https://www.mingw-w64.org/downloads/

# Building/compiling the project
Run cmake script from the build folder and then make to compile the program, after compiling the .exe file will be generated inside build/bin folder

**To successfuly run the .exe file you will have to copy the Files folder and the SDL2 dlls into the folder that contains the .exe file**

**In the Files folder create a Save folder, so the game doesn't crash!!!**


cmake generators https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html

Project root folder:
```
mkdir build
cd build

cmake .. -G "set your generator"
make
```

