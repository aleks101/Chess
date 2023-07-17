#include "Board.h"

Board::Board(SDL_Renderer* ren, SDL_Event* _ev, bool AI) {
	renderer = ren;
	ev = _ev;
	gameOver = false;

	draw = false;
	pieceSelected = false;
	xMouse = yMouse = 0;
	int cnt = 1;
	bool blackOrWhite = false;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if(!blackOrWhite)
				tiles[cnt-1] = new Tile(ren, 50, Point(j, i),
					Assets::GetTexture("Files/Images/white.jpg"), Assets::GetTexture("Files/Images/green.jpg"), true);
			else
				tiles[cnt-1] = new Tile(ren, 50, Point(j, i),
					Assets::GetTexture("Files/Images/black.jpg"), Assets::GetTexture("Files/Images/green.jpg"), false);
			if (cnt % 8 == 0)
				blackOrWhite = blackOrWhite;
			else
				blackOrWhite = !blackOrWhite;
			cnt++;
		}
	}
	white = new HumanPlayer(*ev, tiles, xMouse, yMouse);
	if(AI)
		black = new AIPlayer(tiles, 2);
	else
		black = new HumanPlayer(*ev, tiles, xMouse, yMouse);
	white->SetEnemyPlayer(*black);
	black->SetEnemyPlayer(*white);
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
			black->pieces[cnt] = new Piece(ren, Assets::GetTexture("Files/Images/pieces.png"), PieceSize, Point(j, i), tmpType, false);
			cnt++;
		}
	}
	cnt = 0;
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
			white->pieces[cnt] = new Piece(ren, Assets::GetTexture("Files/Images/pieces.png"), PieceSize, Point(j, i), tmpType, true);
			cnt++;
		}
	}
	alp[0] = new Text(renderer, xStart + TileSize/2-3, 10 * TileSize + TileSize/4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "A", {255, 255, 255});
	alp[1] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 1, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "B", { 255, 255, 255 });
	alp[2] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 2, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "C", { 255, 255, 255 });
	alp[3] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 3, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "D", { 255, 255, 255 });
	alp[4] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 4, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "E", { 255, 255, 255 });
	alp[5] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 5, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "F", { 255, 255, 255 });
	alp[6] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 6, 10 * TileSize + TileSize / 4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "G", { 255, 255, 255 });
	alp[7] = new Text(renderer, xStart + TileSize / 2 - 3 + TileSize * 7, 10 * TileSize + TileSize/4, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "H", { 255, 255, 255 });

	num[0] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 1 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "8", { 255, 255, 255 });
	num[1] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 2 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "7", { 255, 255, 255 });
	num[2] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 3 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "6", { 255, 255, 255 });
	num[3] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 4 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "5", { 255, 255, 255 });
	num[4] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 5 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "4", { 255, 255, 255 });
	num[5] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 6 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "3", { 255, 255, 255 });
	num[6] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 7 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "2", { 255, 255, 255 });
	num[7] = new Text(renderer, xStart - TileSize / 2, yStart + TileSize * 8 - TileSize / 2, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "1", { 255, 255, 255 });
	
	promotionPieces[0] = new Piece(renderer, Assets::GetTexture("Files/Images/pieces.png"), PieceSize, Point(2, -1), Knight, true);
	promotionPieces[1] = new Piece(renderer, Assets::GetTexture("Files/Images/pieces.png"), PieceSize, Point(3, -1), Rook, true);
	promotionPieces[2] = new Piece(renderer, Assets::GetTexture("Files/Images/pieces.png"), PieceSize, Point(4, -1), Bishop, true);
	promotionPieces[3] = new Piece(renderer, Assets::GetTexture("Files/Images/pieces.png"), PieceSize, Point(5, -1), Queen, true);

	flagTile[0] = new Tile(renderer, TileSize, Point(8, 0), Assets::GetTexture("Files/Images/flag.png"), NULL, false);
	flagTile[1] = new Tile(renderer, TileSize, Point(8, 8), Assets::GetTexture("Files/Images/flag.png"), NULL, false);
	flagTile[0]->Available(true);
	flagTile[1]->Available(true);

	endGameText = new Text(renderer, xStart+TileSize*3, yStart-50, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "???", { 255, 255, 255 });

	drawButton = Button(renderer, ev, Text(renderer, xStart+9*TileSize, yStart+4*TileSize, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "Predaja", { 255, 255, 255 }));
	quitButton = Button(renderer, ev, Text(renderer, xStart + 9 * TileSize, yStart + 5 * TileSize, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "Zakljuci igro", { 255, 255, 255 }));

	sound = new Sound<Mix_Chunk>(Assets::GetSound("Files/Audio/move-self.mp3"), 80);

	mousePressed = false;
	team = true;
	whiteWantsToDraw = false;
	blackWantsToDraw = false;
}
Board::~Board() {
	for (auto& tile : tiles) {
		delete tile;
	}
	for (int i = 0; i < 8; i++) {
		delete num[i];
		delete alp[i];
	}
	for (auto& piece : promotionPieces) {
		delete piece;
	}
	delete promotionPiece;
	delete endGameText;
	delete flagTile[0];
	delete flagTile[1];
	delete white;
	delete black;
}
SDL_Rect Board::GetDest() {
	return dest;
}
SDL_Rect Board::GetSrc() {
	return src;
}
void Board::Render() {
	for (int i = 0; i < 64; i++) {
		tiles[i]->Update();
	}
	if(gameOver)
		endGameText->Update();
	drawButton.Update();
	flagTile[0]->Update();
	flagTile[1]->Update();
}
void Board::Update() {
	//preveri klik miske
	SDL_GetMouseState(&xMouse, &yMouse);
	//preveri dvig/klik miske
	if (team) {
		white->MouseDown();
		white->MouseUp();
	}
	else {
		black->MouseDown();
		black->MouseUp();
	}
	//preveri za sah mat
	if (!white->isCheckmated && !black->isCheckmated && !draw) {
		if (team) {
			if (drawButton.CheckMouseClick())
				flagTile[1]->Available(!flagTile[1]->isAvailable);
		}
		else {
			if (drawButton.CheckMouseClick())
				flagTile[0]->Available(!flagTile[0]->isAvailable);
		}
			
		if (!flagTile[0]->isAvailable && !flagTile[1]->isAvailable)
			draw = true;

		//preveri za remi
		int cntW = 0, cntB = 0;
		//prestej stevilo figur
		for (auto& piece : white->pieces)
			if(piece!=NULL)
				cntW++;
		for (auto& piece : black->pieces)
			if (piece != NULL)
				cntB++;
		if (cntW == 1 && cntB == 1)
			draw = true;
		//preveri ali je zadnja figura konj ali tekac
		else if (cntW == 2 && cntB == 1) {
			for (auto& piece : white->pieces) {
				if(piece!=NULL)
					if (piece->type == Knight || piece->type == Bishop) {
						draw = true; break;
					}
			}

		}
		else if (cntW == 1 && cntB == 2) {
			for (auto& piece : black->pieces) {
				if (piece != NULL)
					if (piece->type == Knight || piece->type == Bishop) {
						draw = true; break;
					}
			}
		}
		//premakni figuro
		if (promotingPawn) {
			for(auto& piece : promotionPieces)
				piece->Update();
			int id;
			if (team)
				id = white->SelectPromotionPiece(promotionPieces);
			else
				id = black->SelectPromotionPiece(promotionPieces);
			if (id != -1) {
				promotingPawn = true;
				PromotePawn(promotionPiece, promotionPieces[id]->type);
			}
		}
		else {
			//preveri za klik figure
			if (team) {
				white->SelectPiece();
			}
			else {
				black->SelectPiece();
			}
			//izracunaj vse mozne poteze igralca
			if (team) {
				if (white->FindSelectedPiece()) {
					calc::CalculateValidMoves(*white, *black, tiles, white->FindSelectedPiece(), team);
				}
			}
			else {
				if (black->FindSelectedPiece()) {
					calc::CalculateValidMoves(*black, *white, tiles, black->FindSelectedPiece(), team);
				}
			}
			//premakni figuro
			if (team) {
				MovePiece(*white, *black);
			}
			else {
				MovePiece(*black, *white);
			}
			//ce ni nc izbrano nastavi vse figure za neizbrane
			if (team && !white->isPieceSelected) {
				white->UnSelectPieces();
				//black->UnSelectPieces();
				for (int i = 0; i < 64; i++)
					tiles[i]->Available(false);
			}
			else if(!team && !black->isPieceSelected) {
				black->UnSelectPieces();
				for (int i = 0; i < 64; i++)
					tiles[i]->Available(false);
			}
		}
		if (draw)
			endGameText->ChangeText("Remi");
		else if (white->isCheckmated)
			endGameText->ChangeText("Crn je zmagal");
		else
			endGameText->ChangeText("Beli je zmagal");

	}
	else {
		quitButton.Update();
		if (quitButton.CheckMouseClick())
			gameQuit = true;
		gameOver = true;
	}
	
	//renderi plosco
	Render();
	//renderi figure
	RenderPieces();
	//renderi tekst
	RenderText();
}
void Board::RenderPieces() {
	//rendera vse figure
	for (int i = 0; i < 16; i++) {
		if(white->pieces[i]!=NULL)
			white->pieces[i]->Update();
		if(black->pieces[i]!=NULL)
			black->pieces[i]->Update();
	}
}
void Board::RenderText() {
	//rendere tekst
	for (int i = 0; i < 8; i++) {
		alp[i]->Update();
		num[i]->Update();
	}
}
void Board::MovePiece(Player& playerTeam, Player& enemyTeam) {
	//premakne figuro
	Piece* ptPiece = playerTeam.MovePiece();
	if (ptPiece != NULL) {
		int cnt = 0;
		int id = 0;
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				if (ptPiece->point.xCoord == k && ptPiece->point.yCoord == j) {
					sound->ChangeAudio(Assets::GetSound("Files/Audio/move-self.mp3"));
					sound->Play();
					if (ptPiece->type == King && !playerTeam.hasCastled) {
						int x1 = 6, x2 = 2;
						if (!team) {
							x1 = 5;
							x2 = 1;
						}
						if (ptPiece->point == Point(x1, 7) || ptPiece->point == Point(x2, 7)) {
							calc::Castle(playerTeam, enemyTeam, ptPiece->point, team);
							//sound->ChangeAudio(Assets::GetSound("Files/Audio/castle.mp3"));
						}
						playerTeam.hasCastled = true;
					}
					if (team) {
						PieceMove prevPoint = History::Convert(ptPiece->prevPoint.xCoord, ptPiece->prevPoint.yCoord, ptPiece->ID, team);
						id = History::AddMove(History::Convert(k, j, ptPiece->ID, team));
						std::cout << std::endl;
						std::cout << char(prevPoint.alp) << " : " << prevPoint.num << std::endl;
						std::cout << char(History::GetMove(id).alp) << " : " << History::GetMove(id).num << std::endl;
					}
					else {
						PieceMove prevPoint = History::Convert(7-ptPiece->prevPoint.xCoord, 7-ptPiece->prevPoint.yCoord, ptPiece->ID, team);
						id = History::AddMove(History::Convert(7 - k, 7 - j, ptPiece->ID, team));
						std::cout << std::endl;
						std::cout << char(prevPoint.alp) << " : " << prevPoint.num << std::endl;
						std::cout << char(History::GetMove(id).alp) << " : " << History::GetMove(id).num << std::endl;
					}
					ptPiece->AddHistory(History::GetMove(id));
					for (int l = 0; l < 16; l++) {
						//preveri ce je igralec pojedel nasprotnikovo figuro
						if (enemyTeam.pieces[l] != NULL && enemyTeam.pieces[l]->point.xCoord == ptPiece->point.xCoord &&
							enemyTeam.pieces[l]->point.yCoord == ptPiece->point.yCoord) {
							EatPiece(enemyTeam, l);
							//sound->ChangeAudio(Assets::GetSound("Files/Audio/capture.mp3"));
							break;
						}
					}
					tiles[cnt]->Available(false);
					if (ptPiece->type == Pawn && ptPiece->point.yCoord == 0) {
						promotingPawn = true;
						promotionPiece = ptPiece;
						return;
					}
					else {
						promotingPawn = false;
						team = !team;
						//obrni plosco
						RotateBoard();
						return;
					}
				}
				cnt++;
			}
		}
	}
}
//void Board::CalculateValidMoves(Player& team1, Player& team2, Piece* selectedPiece) {
//	std::vector<AvailableTile> availableTiles;
//	Point piecePoint;
//
//	piecePoint.xCoord = selectedPiece->point.xCoord;
//	piecePoint.yCoord = selectedPiece->point.yCoord;
//
//	Piece* kingPiece = 0;
//	//poisce figuro kralj
//	for (int i = 0; i < 16; i++)
//		if (team1.pieces[i] != NULL && team1.pieces[i]->type == King) {
//			kingPiece = team1.pieces[i];
//		}
//	//preveri ali je igralec v sahu
//	if (kingPiece != NULL) {
//		team1.isInCheck = calc::CalculateCheck(team1, team2, kingPiece->point);
//	}
//	//preveri ali je igralec v sah matu
//	if (team1.isInCheck) {
//		//preveri koliko moznih potez ima igralec v sahu
//		for (auto& piece : team1.pieces) {
//			if (piece != NULL) {
//				availableTiles = calc::CalculateDefendKing(team1, team2, tiles, piece, kingPiece->point);
//				if (availableTiles.size() > 0)
//					break;
//			}
//		}
//		//ce igralec nima nobenih moznih potez je igre konec
//		if (availableTiles.size() == 0)
//			team1.isCheckmated = true;
//		else {
//			//poracuna vse mozne poteze ki preprecijo sah oz. sahmat
//			availableTiles = calc::CalculateDefendKing(team1, team2, tiles, selectedPiece, kingPiece->point);
//
//			for (auto& availableTile : availableTiles)
//				FindTile(availableTile.point)->Available(true);
//		}
//	}
//	else {
//		//poracunaj vse mozne poteze glede na izbrano figuro
//		switch (selectedPiece->type) {
//			case Pawn: {
//				//kmet
//				availableTiles = calc::CalculatePawnMoves(team1, team2, selectedPiece, Point(-1, -1), Point(1, -1), Point(0, -1));
//				for (int i = 0; i < availableTiles.size(); i++)
//					if (availableTiles[i].isAvailable)
//						FindTile(availableTiles[i].point)->Available(true);
//			}
//			break;
//			case Rook: {
//				//trdnjava
//				availableTiles = calc::CalculateRookMoves(team1, team2, selectedPiece);
//				for (int i = 0; i < availableTiles.size(); i++)
//					if (availableTiles[i].isAvailable)
//						FindTile(availableTiles[i].point)->Available(true);
//			}
//			break;
//			case Knight: {
//				//konj
//				availableTiles = calc::CalculateKnightMoves(team1, team2, selectedPiece);
//				for (int i = 0; i < availableTiles.size(); i++)
//					if (availableTiles[i].isAvailable)
//						FindTile(availableTiles[i].point)->Available(true);
//			}
//			break;
//			case Bishop: {
//				//tekac
//				availableTiles = calc::CalculateBishopMoves(team1, team2, selectedPiece);
//				for (int i = 0; i < availableTiles.size(); i++)
//					if (availableTiles[i].isAvailable)
//						FindTile(availableTiles[i].point)->Available(true);
//			}
//			break;
//			case Queen: {
//				//kraljica - trdnjava in tekac
//				availableTiles = calc::CalculateQueenMoves(team1, team2, selectedPiece);
//				for (int i = 0; i < availableTiles.size(); i++)
//					if (availableTiles[i].isAvailable)
//						FindTile(availableTiles[i].point)->Available(true);
//			}
//			break;
//			case King: {
//				//kralj
//				availableTiles = calc::CalculateKingMoves(team1, team2, selectedPiece);
//				std::vector<AvailableTile> tmp = calc::CalculateCastle(team1, team2, selectedPiece->point, team);
//				availableTiles.insert(availableTiles.end(), tmp.begin(), tmp.end());
//				for (int i = 0; i < availableTiles.size(); i++)
//					if (availableTiles[i].isAvailable)
//						FindTile(availableTiles[i].point)->Available(true);
//			}
//			break;
//		}
//		//odstrani poteze ki dajo sah igralcu
//		Point originalPoint = selectedPiece->point;
//		Piece* tmpPiece=NULL;
//
//		for (auto& availablePoint : availableTiles) {
//			selectedPiece->point = availablePoint.point;
//			if (calc::CalculateCheck(team1, team2, kingPiece->point)) {
//				FindTile(availablePoint.point)->Available(false);
//			}
//			for (int i = 0; i < 16;i++) {
//				if (team2.pieces[i]!=NULL && selectedPiece->point == team2.pieces[i]->point && tmpPiece==NULL) {
//					tmpPiece = new Piece(*team2.pieces[i]);
//					delete team2.pieces[i];
//					team2.pieces[i] = NULL;
//					if (!calc::CalculateCheck(team1, team2, kingPiece->point)) {
//						FindTile(availablePoint.point)->Available(true);
//					}
//					team2.pieces[i] = new Piece(*tmpPiece);
//					delete tmpPiece;
//					tmpPiece = NULL;
//				}
//			}
//		}
//		selectedPiece->point = originalPoint;
//	}
//}
void Board::EatPiece(Player& _team, int i) {
	//brisanje figure
	std::cout << "PIECE EATEN " << _team.pieces[i]->type << std::endl;
	delete _team.pieces[i];
	_team.pieces[i] = NULL;
}
void Board::RotateBoard() {
	//rotacije plosce
	int x, y;
	for (int i = 0; i < 16; i++) {
		if (white->pieces[i] != NULL) {
			x = 7 - white->pieces[i]->point.xCoord;
			y = 7 - white->pieces[i]->point.yCoord;
			white->pieces[i]->Move(Point(x, y));
		}
		if (black->pieces[i] != NULL) {
			x = 7 - black->pieces[i]->point.xCoord;
			y = 7 - black->pieces[i]->point.yCoord;
			black->pieces[i]->Move(Point(x, y));
		}
	}
	FlipText();
}
Tile* Board::FindTile(Point point) {
	//poisci polje glede na podano lokacijo
	for (int i = 0; i < 64; i++) {
		if (tiles[i]->point.xCoord == point.xCoord && tiles[i]->point.yCoord == point.yCoord)
			return tiles[i];
	}
	return NULL;
}
Piece* Board::FindPiece(Point point) {
	//poisci figuro glede na podano lokacijo
	Piece* piece=NULL;

	for (int i = 0; i < 16; i++)
		if (white->pieces[i] != NULL && white->pieces[i]->point == point)
			piece = white->pieces[i];
	if(!piece)
		for (int i = 0; i < 16; i++)
			if (black->pieces[i] != NULL && black->pieces[i]->point == point)
				piece = black->pieces[i];
	return piece;
}
void Board::PromotePawn(Piece* _piece, int type) {
	_piece->ChangeType(type);

	RotateBoard();
	team = !team;

	promotingPawn = false;
	sound->ChangeAudio(Assets::GetSound("Files/Audio/promote.mp3"));
	sound->Play();
}
void Board::FlipText() {
	SDL_Rect tmpPos;
	int j = 7;
	for (int i = 0; i < 4; i++) {
		tmpPos = alp[i]->GetDest();
		alp[i]->SetDest(alp[j]->GetDest());
		alp[j]->SetDest(tmpPos);

		tmpPos = num[i]->GetDest();
		num[i]->SetDest(num[j]->GetDest());
		num[j]->SetDest(tmpPos);
		j--;
	}
}