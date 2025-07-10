#include "Replay.h"

Replay::Replay(SDL_Renderer* ren, SDL_Event* _ev, std::vector<PieceMove> _moves)
	: renderer(ren), ev(_ev)
{
	moves.assign(_moves.begin(), _moves.end());
	moveInt = -1;
	for (int i = 0; i < moves.size(); i++)
		std::cout << moves[i].alp << " : " << moves[i].num << std::endl;
	bool blackOrWhite = false;
	int cnt = 1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (!blackOrWhite)
				tiles[cnt - 1] = new Tile(ren, 50, Point(j, i),
					Assets::GetTexture("Files/Images/white.jpg"), Assets::GetTexture("Files/Images/green.jpg"), true);
			else
				tiles[cnt - 1] = new Tile(ren, 50, Point(j, i),
					Assets::GetTexture("Files/Images/black.jpg"), Assets::GetTexture("Files/Images/green.jpg"), false);
			if (cnt % 8 == 0)
				blackOrWhite = blackOrWhite;
			else
				blackOrWhite = !blackOrWhite;
			cnt++;
		}
	}
	int tmpPos = 0;
	int tmpType = 0;
	cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 8; j++) {
			switch (j) {
			case 0:
				tmpType = 4; break;
			case 1:
				tmpType = 3; break;
			case 2:
				tmpType = 2; break;
			case 3:
				tmpType = 1; break;
			case 4:
				tmpType = 0; break;
			case 5:
				tmpType = 2; break;
			case 6:
				tmpType = 3; break;
			case 7:
				tmpType = 4; break;
			}
			if (i == 0) {
				tmpPos = 0;
			}
			if (i == 1) {
				tmpPos = 8;
				tmpType = 5;
			}
			pieces[cnt] = new Piece(ren, Assets::GetTexture("Files/Images/pieces.png"), PieceSize, Point(j, i), tmpType, false);
			cnt++;
		}
	}
	for (int i = 6; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			switch (j) {
			case 0:
				tmpType = 4; break;
			case 1:
				tmpType = 3; break;
			case 2:
				tmpType = 2; break;
			case 3:
				tmpType = 1; break;
			case 4:
				tmpType = 0; break;
			case 5:
				tmpType = 2; break;
			case 6:
				tmpType = 3; break;
			case 7:
				tmpType = 4; break;
			}
			if (i == 6) {
				tmpPos = 48;
				tmpType = 5;
			}
			if (i == 1) {
				tmpPos = 56;
			}
			pieces[cnt] = new Piece(ren, Assets::GetTexture("Files/Images/pieces.png"), PieceSize, Point(j, i), tmpType, true);
			cnt++;
		}
	}
	alp[0] = new Text(renderer, xStart + TileSize / 2 - 3, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "A", { 255, 255, 255 });
	alp[1] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 1, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "B", { 255, 255, 255 });
	alp[2] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 2, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "C", { 255, 255, 255 });
	alp[3] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 3, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "D", { 255, 255, 255 });
	alp[4] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 4, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "E", { 255, 255, 255 });
	alp[5] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 5, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "F", { 255, 255, 255 });
	alp[6] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 6, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "G", { 255, 255, 255 });
	alp[7] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 7, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "H", { 255, 255, 255 });

	num[0] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 1 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "8", { 255, 255, 255 });
	num[1] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 2 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "7", { 255, 255, 255 });
	num[2] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 3 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "6", { 255, 255, 255 });
	num[3] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 4 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "5", { 255, 255, 255 });
	num[4] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 5 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "4", { 255, 255, 255 });
	num[5] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 6 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "3", { 255, 255, 255 });
	num[6] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 7 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "2", { 255, 255, 255 });
	num[7] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 8 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "1", { 255, 255, 255 });

	next = new Button(renderer, ev, Text(renderer, xStart + 9 * TileSize, yStart + 4 * TileSize, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "Naprej", { 255, 255, 255 }));
}
Replay::~Replay() {
	for (auto& tile : tiles)
		delete tile;
	for (int i = 0; i < 8; i++) {
		delete alp[i];
		delete num[i];
	}
	delete next;
}
void Replay::Render() {
	for (auto& tile : tiles)
		tile->Render();
	for (auto& piece : pieces)
		if(piece!=NULL)
			piece->Update();
	for (int i = 0; i < 8; i++) {
		alp[i]->Render();
		num[i]->Render();
	}
	next->Update();
	//back->Update();
}
void Replay::Update() {
	Render();
	int moveIntPrevious = moveInt;
	if (next->CheckMouseClick()) {
		std::cout << moveInt << " " << moves.size() << std::endl;
		if (moveInt != moves.size()-1) {
			moveInt++;
			std::cout << moveInt << " " << moves.size() << std::endl;
		}
	}
	if (moveInt != moveIntPrevious) {
		PieceMove move = moves[moveInt];
		move = History::Convert(move.alp, move.num, move.pieceID, move.team);
		pieces[move.pieceID]->Move(Point((int)move.alp, move.num));
		for (int i = 0; i < 32; i++) {
			if (pieces[i] != NULL) {
				if (pieces[i]->point == pieces[move.pieceID]->point && i!=move.pieceID) {
					delete pieces[i];
					pieces[i] = NULL;
				}
			}
		}
	}
}