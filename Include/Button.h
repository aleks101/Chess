#pragma once

#include "Object.h"
#include "Text.h"

class Button : public Object
{
private:
	SDL_Event* ev;
	Text text;
	int yMouse, xMouse;
public:
	Button(SDL_Renderer* ren, SDL_Event* _ev, Text _text);
	Button(const Button& button) {
		renderer = button.renderer;
		ev = button.ev;
		text = button.text;
		dest = button.dest;
	}
	Button() : ev(NULL), yMouse(0), xMouse(0)
	{

	}
	void Render();
	void Update();
	SDL_Rect GetDest();
	SDL_Rect GetSrc();
	bool CheckMouseOver(int x, int y);
	bool CheckMouseClick();
};

