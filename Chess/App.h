#pragma once

#include <iostream>
#include <SDL.h>

using namespace std;

#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720

class App
{
private:

public:
	static SDL_Window* window;
	static SDL_Renderer* renderer;

	static void ApplicationStart();
	static void ApplicationQuit();
	static bool ApplicationCheckQuit(SDL_Event event);
	static void ApplicationRender();
};