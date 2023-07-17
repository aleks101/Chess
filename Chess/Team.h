#pragma once

#include "Piece.h"

class Team
{
private:

public:
	Team();
	~Team();

	void SelectPiece(int xMouse, int yMouse, bool mouseClick, bool pieceSelected);
	void UnSelectPieces();

	Piece* pieces[16];
	bool isInCheck;
	bool isCheckmated;
	bool hasCastled;
};