#include "Tile.h"

Tile::Tile() {

}
Tile::Tile(SDL_Renderer* ren, int size, Point _point, SDL_Texture* texture, SDL_Texture* avaTex, bool _white) {
	renderer = ren;
	tex = texture;
	dest.w = size;
	dest.h = size;
	point = _point;
	dest.x = xStart + point.xCoord * TileSize;
	dest.y = yStart + point.yCoord * TileSize;
	isAvailable = false;
	originalTex = tex;
	availableTex = avaTex;
	white = _white;
}
Tile::~Tile() {
	SDL_DestroyTexture(tex);
}
void Tile::Render() {
	SDL_RenderCopy(renderer, tex, NULL, &dest);
}
void Tile::Update() {

	Render();
}
SDL_Rect Tile::GetSrc() {
	return src;
}
SDL_Rect Tile::GetDest() {
	return dest;
}
void Tile::Available(bool _isAvailable) {
	if (_isAvailable) {
		tex = availableTex;
		isAvailable = true;
	}
	else{
		tex = originalTex;
		isAvailable = false;
	}
}
bool Tile::CheckMouseOver(int x, int y) {
	if ((x > dest.x && x < dest.x + dest.w) && (y > dest.y && y < dest.y + dest.h)) {
		return true;
	}
	return false;
}