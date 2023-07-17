#pragma once

#include <iostream>
#include <vector>

#include "PieceMove.h"

class History
{
private:
	static std::vector<PieceMove> moves;
public:
	static int AddMove(char a, int x, int pieceID, bool team);
	static int AddMove(PieceMove move);
	static PieceMove GetMove(int i);
	static std::vector<PieceMove> GetMoves();
	static PieceMove Convert(int x, int y, int pieceID, bool team);
	static PieceMove Convert(char x, int y, int pieceID, bool team);
};