#include "History.h"

std::vector<PieceMove> History::moves;

int History::AddMove(char a, int x, int pieceID, bool team) {
	moves.push_back(PieceMove(a, x, pieceID, team));
	return moves.size() - 1;
}
std::vector<PieceMove> History::GetMoves() {
	return moves;
}
int History::AddMove(PieceMove move) {
	moves.push_back(move);
	return moves.size() - 1;
}
PieceMove History::GetMove(int i) {
	return moves[i];
}
PieceMove History::Convert(int x, int y, int pieceID, bool team) {
	char A = 65 + x;
	int Y = 8 - y;

	return PieceMove(A, Y, pieceID, team);
}
PieceMove History::Convert(char x, int y, int pieceID, bool team) {
	char A = x - 65;
	int Y = 8 - y;

	return PieceMove(A, Y, pieceID, team);
}