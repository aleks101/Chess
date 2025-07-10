#pragma once

#include <time.h>

#include "Player.h"
#include "Calc.h"

struct Eval {
	int moveID;
	int score;
	int pieceID;
	Eval() {
		moveID = 0;
		score = 0;
		pieceID = 0;
	}
	Eval(int _moveID, int _pieceID, int _score) :
		moveID(_moveID), pieceID(_pieceID), score(_score) { }
	Eval(const Eval& eval) {
		this->moveID = eval.moveID;
		this->score = eval.score;
		this->pieceID = eval.pieceID;
	}
};
class AIPlayer : public Player
{
private:
	Eval EvaluateMove();
	Eval EvaluatePos();
	std::vector<Tile*> GetAvailableTiles();
	int GetPieceScore(int type);
	int pieceToMoveID;
	int depthLevel;
	Eval evaluation;
public:
	AIPlayer(Tile* tiles[64], int _depthLevel);
	~AIPlayer();
	Piece* MovePiece();
	void SelectPiece();
	void MouseUp();
	void MouseDown();
	int SelectPromotionPiece(Piece* proPieces[4]);
};

