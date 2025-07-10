#pragma once

#include <iostream>

#include "Object.h"
#include "Point.h"

class Tile : public Object
{
public:
	Tile();
	Tile(SDL_Renderer* ren, int size, Point _point, SDL_Texture* texture, SDL_Texture* avaTex, bool _white);
	~Tile();
	void Render();
	void Update();
	void Available(bool _isAvailable);
	bool CheckMouseOver(int x, int y);
	SDL_Rect GetSrc();
	SDL_Rect GetDest();

	Point point;
	bool isAvailable;
	bool white;
	SDL_Texture* originalTex, *availableTex;
};

struct AvailableTile {
	Point point;
	bool isAvailable;
	AvailableTile(Point _point, bool _isAvailable) {
		point = _point;
		isAvailable = _isAvailable;
	}
};