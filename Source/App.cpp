#include "App.h"

SDL_Window* App::window = NULL;
SDL_Renderer* App::renderer = NULL;

void App::ApplicationStart() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
}
void App::ApplicationQuit() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
bool App::ApplicationCheckQuit(SDL_Event event) {
	if (event.type == SDL_QUIT) {
		return 0;
	}
	return 1;
}
void App::ApplicationRender() {
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}