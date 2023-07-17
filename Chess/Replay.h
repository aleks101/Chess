#pragma once

#include "Tile.h"
#include "Text.h"
#include "Piece.h"
#include "Button.h"
#include "Assets.h"
#include "History.h"

class Replay
{
private:
	Tile* tiles[64];
	Text* alp[8];
	Text* num[8];

	Button* next;
	
	Piece* pieces[32];

	std::vector<PieceMove> moves;
	int moveInt;

	SDL_Renderer* renderer;
	SDL_Event* ev;
public:
	Replay(SDL_Renderer* ren, SDL_Event* _ev, std::vector<PieceMove> _moves);
	~Replay();
	void Update();
	void Render();
};

