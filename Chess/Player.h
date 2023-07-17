#pragma once

#include "Piece.h"
#include "Tile.h"

class Player {
protected:

public:
	Player(Tile* _tiles[64]) {
		isInCheck = false;
		isCheckmated = false;
		hasCastled = false;
		for (int i = 0; i < 16; i++)
			pieces[i] = NULL;
		for (int i = 0; i < 64; i++)
			tiles[i] = &*_tiles[i];
		hasPieceMoved = false;
		isPieceSelected = false;
		enemyPlayer = NULL;
	}
	virtual ~Player() {
		for (int i = 0; i < 16; i++)
			if (pieces[i] != NULL)
				delete pieces[i];
	}
	virtual void SelectPiece() = 0;
	virtual void UnSelectPieces() {
		for (int i = 0; i < 16; i++)
			if (pieces[i] != NULL)
				pieces[i]->isSelected = false;
	}
	virtual Piece* MovePiece() { return nullptr; }
	virtual int SelectPromotionPiece(Piece* proPieces[4]) { return -1; }
	virtual void MouseUp() {}
	virtual void MouseDown() {}
	Piece* FindSelectedPiece() {
		for (auto piece : pieces)
			if (piece != NULL && piece->isSelected)
				return piece;
		return NULL;
	}
	void SetEnemyPlayer(Player& _enemyPlayer) {
		enemyPlayer = &_enemyPlayer;
	}

	Piece* pieces[16];
	bool isInCheck;
	bool isCheckmated;
	bool hasCastled;
	bool hasPieceMoved;
	bool isPieceSelected;
	//nasprotni igralec
	Player* enemyPlayer;
	//polja
	Tile* tiles[64];
};