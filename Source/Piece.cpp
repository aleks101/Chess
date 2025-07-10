#include "Piece.h"

int Piece::IDs = 0;

Piece::Piece(SDL_Renderer* ren, SDL_Texture* texture, int size, Point _pos, int _type, bool _isWhite) {
	isWhite = _isWhite;
	ID = IDs;
	IDs++;
	renderer = ren;
	tex = texture;
	dest.w = size;
	dest.h = size;
	dest.x = 0; dest.y = 0;
	type = _type;
	Move(_pos);
	src.w = 426;
	src.h = 426;
	if (!_isWhite) {
		src.y = 426;
	}
	else {
		src.y = 0;
	}
	switch (type) {
	case 0:
		src.x = 426 * 0;
		break;
	case 1:
		src.x = 426 * 1;
		break;
	case 2:
		src.x = 426 * 2;
		break;
	case 3:
		src.x = 426 * 3;
		break;
	case 4:
		src.x = 426 * 4;
		break;
	case 5:
		src.x = 426 * 5;
		break;
	}
	isSelected = false;
}
Piece::Piece(const Piece& piece) {
	renderer = piece.renderer;
	tex = piece.tex;
	dest = piece.dest;
	Move(piece.point);
	src.w = 426;
	src.h = 426;
	src.x = piece.src.x;
	src.y = piece.src.y;
	isSelected = piece.isSelected;
	type = piece.type;
}
SDL_Rect Piece::GetDest() {
	return dest;
}
SDL_Rect Piece::GetSrc() {
	return src;
}
void Piece::Render() {
	SDL_RenderCopy(renderer, tex, &src, &dest);
}
void Piece::Update() {
	Render();
}
void Piece::Move(Point _point) {
	prevPoint = point;
	point = _point;
	dest.x = xStart + point.xCoord * TileSize;
	dest.y = yStart + point.yCoord * TileSize;
}
bool Piece::CheckMouseOver(int x, int y) {
	if ((x > dest.x && x < dest.x + dest.w) && (y > dest.y && y < dest.y + dest.h)) {
		return true;
	}
	return false;
}
void Piece::ChangeType(int _type) {
	type = _type;
	switch (type) {
	case 0:
		src.x = 426 * 0;
		break;
	case 1:
		src.x = 426 * 1;
		break;
	case 2:
		src.x = 426 * 2;
		break;
	case 3:
		src.x = 426 * 3;
		break;
	case 4:
		src.x = 426 * 4;
		break;
	case 5:
		src.x = 426 * 5;
		break;
	}
}
void Piece::AddHistory(PieceMove move) {
	moveHistory.push_back(move);
}
bool Piece::IsHistoryEmpty() {
	if (moveHistory.empty())
		return true;
	return false;
}