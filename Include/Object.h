#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

int const TileSize = 50;
int const PieceSize = 50;
int const xStart = 400;
int const yStart = 100;

class Object
{
public:
	virtual void Render() = 0;
	virtual void Update() = 0;
	virtual SDL_Rect GetSrc() = 0;
	virtual SDL_Rect GetDest() = 0;
	virtual SDL_Texture* GetTex() {
		return tex;
	}
	virtual void SetDest(SDL_Rect newDest) {
		dest = newDest;
	}
protected:
	SDL_Rect src;
	SDL_Rect dest;
	SDL_Renderer* renderer;
	SDL_Texture* tex;
};

