#include "AIPlayer.h"

AIPlayer::AIPlayer(Tile* tiles[64], int _depthLevel) : 
	Player(tiles), depthLevel(0), pieceToMoveID(0) {
	evaluation.score = 0;
	evaluation.moveID = 0;
	isPieceSelected = false;
	srand(time(NULL));
}
AIPlayer::~AIPlayer() {}
void AIPlayer::SelectPiece() {
	hasPieceMoved = false;
	if (!isPieceSelected) {
		int id = rand() % 16;
		while (pieces[id] == NULL) {
			id = rand() % 16;
		}
		pieces[id]->isSelected = true;
		pieceToMoveID = id;
		isPieceSelected = true;
		for (int i = 0; i < 16; i++)
			if (i != id && pieces[i] != NULL)
				pieces[i]->isSelected = false;
		/*std::vector<Tile*> availableTiles = GetAvailableTiles();

		if (pieces[depthLevel] != NULL && depthLevel < 16) {
			pieces[depthLevel]->isSelected = true;
			calc::CalculateValidMoves(*this, *enemyPlayer, tiles, FindSelectedPiece(), false);
			Eval eval = EvaluateMove();
			std::cout << eval.score << std::endl;
			if (eval.score > evaluation.score) {
				evaluation = eval;
				std::cout << "TOP SCORE: " << eval.score << std::endl;
			}
			depthLevel++;
		}
		else if(depthLevel>=16){
			std::cout << "BEST POSSIBLE PIECE SELECTED " << pieces[evaluation.pieceID]->type << std::endl;
			pieces[evaluation.pieceID]->isSelected = true;
			pieceToMoveID = evaluation.pieceID;
			isPieceSelected = true;
			for (int i = 0; i < 16; i++)
				if (i != depthLevel && pieces[i] != NULL)
					pieces[i]->isSelected = false;
		}*/
	}
}
Piece* AIPlayer::MovePiece() {
	if (isPieceSelected) {
		isPieceSelected = false;
		if (pieces[pieceToMoveID] != NULL) {
			//int id;
			std::vector<Tile*> availableTiles = GetAvailableTiles();
			if (availableTiles.size() > 0) {
				/*id = rand() % availableTiles.size();
				//pieces[pieceToMoveID]->Move(availableTiles[id]->point);
				//availableTiles[id]->Available(false);
				hasPieceMoved = true;
				return pieces[pieceToMoveID];*/
				Eval eval = EvaluateMove();
				pieces[pieceToMoveID]->Move(availableTiles[eval.moveID]->point);
				availableTiles[eval.moveID]->Available(false);
				hasPieceMoved = true;
				depthLevel = 0;
				return pieces[pieceToMoveID];
			}
		}
	}
	return nullptr;
}
Eval AIPlayer::EvaluateMove() {
	Eval eval(0,0,0);

	std::vector<Tile*> availableTiles = GetAvailableTiles();
	for (int j = 0; j < availableTiles.size(); j++) {
		for (int i = 0; i < 16;i++) {
			if (enemyPlayer->pieces[i]!=NULL && enemyPlayer->pieces[i]->point == availableTiles[j]->point) {
				if (GetPieceScore(enemyPlayer->pieces[i]->type) > eval.score) {
					eval.score = GetPieceScore(enemyPlayer->pieces[i]->type);
					eval.moveID = j;
					eval.pieceID = depthLevel;
				}
			}
		}
	}
	std::cout << eval.score << std::endl;
	return eval;
}
Eval AIPlayer::EvaluatePos() {
	Eval eval(0,0,0);

	return eval;
}
int AIPlayer::GetPieceScore(int type) {
	switch (type) {
	case King:
		return KingV;
		break;
	case Queen:
		return QueenV;
		break;
	case Bishop:
		return BishopV;
		break;
	case Knight:
		return KnightV;
		break;
	case Rook:
		return RookV;
		break;
	case Pawn:
		return PawnV;
		break;
	default:
		return 0;
	}
}
void AIPlayer::MouseDown() {

}
void AIPlayer::MouseUp() {

}
int AIPlayer::SelectPromotionPiece(Piece* proPieces[4]) {
	return 0;
}
std::vector<Tile*> AIPlayer::GetAvailableTiles() {
	std::vector<Tile*> availableTiles;
	for (auto& tile : tiles)
		if (tile->isAvailable)
			availableTiles.push_back(tile);
	return availableTiles;
}