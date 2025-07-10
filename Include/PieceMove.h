#pragma once
class PieceMove
{
public:
	PieceMove(char a, int x, int _pieceID, bool _team) { num = x; alp = a; pieceID = _pieceID; team = _team; }
	PieceMove(const PieceMove& pieceMove){
		num = pieceMove.num;
		alp = pieceMove.alp;
		pieceID = pieceMove.pieceID;
		team = pieceMove.team;
	}
	PieceMove() { num = 0; alp = 0; pieceID = 0; team = 0; }

	int num;
	char alp;
	int pieceID;
	bool team;
};

