#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(SDL_Event& _ev, Tile* _tiles[64], int& _xMouse, int& _yMouse) :
	ev(&_ev), Player(_tiles), xMouse(&_xMouse), yMouse(&_yMouse), mouseClick(false) { }
HumanPlayer::~HumanPlayer() {}
void HumanPlayer::SelectPiece() {
	hasPieceMoved = false;
	for (int i = 0; i < 16; i++) {
		if (pieces[i] != NULL && pieces[i]->CheckMouseOver(*xMouse, *yMouse) && mouseClick && isPieceSelected) {
			pieces[i]->isSelected = true;
			for (int j = 0; j < 16; j++) {
				if (j != i && pieces[j] != NULL)
					pieces[j]->isSelected = false;
			}
			break;
		}
	}
}
Piece* HumanPlayer::MovePiece() {
	int id;
	int cnt = 0;
	for (int i = 0; i < 16; i++)
		if (pieces[i] != NULL && pieces[i]->isSelected)
			id = i;
	for (int j = 0; j < 8; j++) {
		for (int k = 0; k < 8; k++) {
			if (tiles[cnt]->isAvailable && tiles[cnt]->CheckMouseOver(*xMouse, *yMouse) && !isPieceSelected) {
				pieces[id]->Move(Point(k, j));
				tiles[cnt]->Available(false);
				hasPieceMoved = true;
				return pieces[id];
			}
			cnt++;
		}
	}
	return NULL;
}
void HumanPlayer::MouseDown() {
	mouseClick = false;
	if (ev->type == SDL_MOUSEBUTTONDOWN) {
		if (ev->button.button == SDL_BUTTON_LEFT) {
			mouseClick = true;
			isPieceSelected = !(isPieceSelected);
		}
	}
}
void HumanPlayer::MouseUp() {
	if (ev->type == SDL_MOUSEBUTTONUP) {
		if (ev->button.button == SDL_BUTTON_LEFT) {
			mouseClick = false;
		}
	}
}
int HumanPlayer::SelectPromotionPiece(Piece* proPieces[4]) {
	if (mouseClick) {
		for (int i = 0; i < 4;i++) {
			if (proPieces[i]->CheckMouseOver(*xMouse, *yMouse))
				return i;
		}
	}
	return -1;
}