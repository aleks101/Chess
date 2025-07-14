#pragma once

#include "Tile.h"
#include "Assets.h"
#include "Object.h"
#include "Piece.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "History.h"
#include "Text.h"
#include "Button.h"
#include "Sound.h"

#include "Calc.h"

class Board : public Object
{
private:
	Tile* tiles[64];
	Tile* flagTile[2];

	Player* white;
	Player* black;

	Text* alp[8];
	Text* num[8];
	Text* endGameText;

	Piece* promotionPieces[4];
	Piece* promotionPiece;

	Sound<Mix_Chunk>* sound;

	Button drawButton;
	Button quitButton;

	bool promotingPawn = false;
	int xMouse, yMouse;
	bool mousePressed;
	bool pieceSelected;
	bool team;
	bool draw;
	bool whiteWantsToDraw, blackWantsToDraw;
	SDL_Event* ev;
public:
	Board(SDL_Renderer* ren, SDL_Event* _ev, bool AI);
	~Board();
	void Render();
	void Update();
	void RenderPieces();
	void RenderText();
	void FlipText();

	void MovePiece(Player& playerTeam, Player& enemyTeam);
	void RotateBoard();
	void EatPiece(Player& _team, int i);
	void PromotePawn(Piece* _piece, int type);

	Tile* FindTile(Point point);
	Piece* FindPiece(Point point);

	//void CalculateValidMoves(Player& playerTeam, Player& enemyTeam, Piece* selectedPiece);

	SDL_Rect GetDest();
	SDL_Rect GetSrc();

	bool gameOver;
	bool gameQuit;
};