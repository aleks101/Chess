#include "Team.h"

Team::Team() {
	isInCheck = false;
	isCheckmated = false;
	hasCastled = false;
	for (int i = 0; i < 16; i++)
		pieces[i] = NULL;
}
Team::~Team() {
	for (int i = 0; i < 16; i++) {
		delete pieces[i];
	}
}
void Team::SelectPiece(int xMouse, int yMouse, bool mouseClick, bool pieceSelected) {
	for (int i = 0; i < 16; i++) {
		if (pieces[i] != NULL && pieces[i]->CheckMouseOver(xMouse, yMouse) && mouseClick && pieceSelected) {
			pieces[i]->isSelected = true;
			for (int j = 0; j < 16; j++) {
				if (j != i && pieces[j] != NULL)
					pieces[j]->isSelected = false;
			}
			break;
		}
	}
}
void Team::UnSelectPieces() {
	for (int i = 0; i < 16; i++) {
		if (pieces[i] != NULL)
			pieces[i]->isSelected = false;
	}
}