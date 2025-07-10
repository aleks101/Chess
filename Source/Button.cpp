#include "Button.h"

Button::Button(SDL_Renderer* ren, SDL_Event* _ev, Text _text) : ev(_ev)
{
	renderer = ren;
	xMouse = 0;
	yMouse = 0;

	text = _text;
	dest = text.GetDest();
}
void Button::Update() {
	SDL_GetMouseState(&xMouse, &yMouse);
	Render();
}
void Button::Render() {
	SDL_RenderCopy(renderer, text.GetTex(), NULL, &dest);
}
SDL_Rect Button::GetDest() {
	return dest;
}
SDL_Rect Button::GetSrc() {
	return src;
}
bool Button::CheckMouseOver(int x, int y) {
	if ((x > dest.x && x < dest.x + dest.w) && (y > dest.y && y < dest.y + dest.h)) {
		return true;
	}
	return false;
}
bool Button::CheckMouseClick() {
	if (CheckMouseOver(xMouse, yMouse)) {
		if (ev->type == SDL_MOUSEBUTTONDOWN) {
			if (ev->button.button == SDL_BUTTON_LEFT) {
				return true;
			}
		}
	}
	return false;
}