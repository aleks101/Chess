#pragma once

#include "Player.h"

#include <iostream>

class HumanPlayer : public Player
{
private:
	int* xMouse, * yMouse;
	bool mouseClick;
	SDL_Event* ev;
public:
	HumanPlayer(SDL_Event& _ev, Tile* _tiles[64], int& _xMouse, int& _yMouse);
	~HumanPlayer();
	void SelectPiece();
	Piece* MovePiece();
	void MouseDown();
	void MouseUp();
	int SelectPromotionPiece(Piece* proPieces[4]);
};

