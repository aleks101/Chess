#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

#include "Object.h"

class Text : public Object
{
private:
	std::string text;
	SDL_Color color;
	TTF_Font* font;
public:
	Text();
	Text(SDL_Renderer* ren, int xPos, int yPos, TTF_Font* _font, std::string _text, SDL_Color _color);
	Text(const Text& text);
	~Text();
	void Render();
	void Update();
	SDL_Rect GetDest();
	SDL_Rect GetSrc();

	void ChangeText(std::string _text);
};

