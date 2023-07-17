#pragma once

#include <iostream>
#include <vector>

#include "Point.h"
#include "Player.h"
#include "Tile.h"
#include "History.h"

namespace calc {
	std::vector<AvailableTile> CalculatePawnMoves(Player& playerTeam, Player& enemyTeam, Piece* selectedPiece, Point eatLeft, Point eatRight, Point moveForward);
	std::vector<AvailableTile> CalculateRookMoves(Player& playerTeam, Player& enemyTeam, Piece* selectedPiece);
	std::vector<AvailableTile> CalculateKnightMoves(Player& playerTeam, Player& enemyTeam, Piece* selectedPiece);
	std::vector<AvailableTile> CalculateBishopMoves(Player& playerTeam, Player& enemyTeam, Piece* selectedPiece);
	std::vector<AvailableTile> CalculateQueenMoves(Player& playerTeam, Player& enemyTeam, Piece* selectedPiece);
	std::vector<AvailableTile> CalculateKingMoves(Player& playerTeam, Player& enemyTeam, Piece* selectedPiece);
	std::vector<AvailableTile> CalculateDefendKing(Player& playerTeam, Player& enemyTeam, Tile* tiles[], Piece* selectedPiece, Point kingPoint);
	std::vector<AvailableTile> CalculateCastle(Player& playerTeam, Player& enemyTeam, Point kingPoint, bool team);
	bool CalculateCheck(Player& playerTeam, Player& enemyTeam, Point kingPoint);
	void CalculateValidMoves(Player& playerTeam, Player& enemyTeam, Tile* tiles[], Piece* selectedPiece, bool team);

	bool CheckIfPointIsValid(Point point);
	bool CheckIfPointIsFree(Player& _team, Point point);
	void Castle(Player& playerTeam, Player& enemyTeam, Point kingPoint, bool team);

	Tile* FindTile(Tile* tiles[], Point point);
	Piece* FindPiece(Player& team1, Player& team2, Point point);
}