#include "Text.h"

Text::Text(SDL_Renderer* ren, int xPos, int yPos, TTF_Font* _font, std::string _text, SDL_Color _color) {
	renderer = ren;
	dest.x = xPos;
	dest.y = yPos;
	text = _text;
	color = _color;
	font = _font;

	SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), color);
	if (!surf) {
		std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
	}
	if (!renderer)
		std::cout << "renderer error" << std::endl;

	tex = SDL_CreateTextureFromSurface(renderer, surf);
	if (!tex)
		std::cout << "tex error" << std::endl;

	dest.w = surf->w;
	dest.h = surf->h;

	SDL_FreeSurface(surf);
}
Text::Text(const Text& _text) {
	renderer = _text.renderer;
	dest = _text.dest;
	text = _text.text;
	color = _text.color;
	font = _text.font;
}
Text::Text() {

}
Text::~Text() {

}
void Text::Render() {
	SDL_RenderCopy(renderer, tex, NULL, &dest);
}
void Text::Update() {
	Render();
}
SDL_Rect Text::GetDest() {
	return dest;
}
SDL_Rect Text::GetSrc() {
	return src;
}
void Text::ChangeText(std::string _text) {
	if (text != _text) {
		text = _text;
		SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), color);
		tex = SDL_CreateTextureFromSurface(renderer, surf);
		SDL_FreeSurface(surf);
		SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
	}
}