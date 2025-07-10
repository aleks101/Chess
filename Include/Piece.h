#pragma once

#include <iostream>
#include <vector>

#include "Object.h"
#include "Point.h"
#include "PieceMove.h"

class Piece: public Object
{
private:
	std::vector<PieceMove> moveHistory;
public:
	Piece(SDL_Renderer* ren, SDL_Texture* texture, int size, Point _pos, int _type, bool _isWhite);
	Piece(const Piece& piece);
	Piece(){
		isSelected = false;
		type = -1;
		ID = 0;
		isWhite = false;
	}

	void Move(Point _point);
	void Update();
	void Render();
	bool CheckMouseOver(int x, int y);
	void ChangeType(int _type);

	SDL_Rect GetDest();
	SDL_Rect GetSrc();

	std::vector<PieceMove> GetMoves()const { return moveHistory; }
	void AddHistory(PieceMove move);
	bool IsHistoryEmpty();

	bool isSelected;
	int type;
	Point point, prevPoint;
	static int IDs;
	int ID;
	bool isWhite;
};
enum PieceTypes {
	King,
	Queen,
	Bishop,
	Knight,
	Rook,
	Pawn
};
enum PieceValue {
	KingV=900,
	QueenV=9,
	BishopV=3,
	KnightV=3,
	RookV=5,
	PawnV=1
};