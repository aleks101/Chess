#include "Calc.h"

namespace calc {
	std::vector<AvailableTile> CalculatePawnMoves(Player& playerTeam, Player& enemyTeam, Piece* selectedPiece, Point eatLeft, Point eatRight, Point moveForward) {
		//izracunaj vse mozne poteze kmeta
		std::vector<AvailableTile> availableTiles;
		Point piecePoint = selectedPiece->point;
		Point moveDoubleForward(0, -2);

		if (CheckIfPointIsValid(eatLeft + piecePoint)
			&& !CheckIfPointIsFree(enemyTeam, eatLeft + piecePoint)) {
			availableTiles.push_back(AvailableTile(eatLeft + piecePoint, true));
		}
		if (CheckIfPointIsValid(eatRight + piecePoint)
			&& !CheckIfPointIsFree(enemyTeam, eatRight + piecePoint)) {
			availableTiles.push_back(AvailableTile(eatRight + piecePoint, true));
		}
		if (CheckIfPointIsValid(moveForward + piecePoint)
			&& CheckIfPointIsFree(playerTeam, moveForward + piecePoint)
			&& CheckIfPointIsFree(enemyTeam, moveForward + piecePoint)) {
			availableTiles.push_back(AvailableTile(moveForward + piecePoint, true));
		}
		if (piecePoint.yCoord == 6
			&& CheckIfPointIsFree(playerTeam, moveDoubleForward + piecePoint)
			&& CheckIfPointIsFree(enemyTeam, moveDoubleForward + piecePoint)
			&& CheckIfPointIsFree(playerTeam, moveForward + piecePoint)
			&& CheckIfPointIsFree(enemyTeam, moveForward + piecePoint)) {
			availableTiles.push_back(AvailableTile(moveDoubleForward + piecePoint, true));
		}
		return availableTiles;
	}
	std::vector<AvailableTile> CalculateRookMoves(Player& playerTeam, Player& enemyTeam, Piece* selectedPiece) {
		//izracunaj vse mozne poteze trdnjave
		std::vector<AvailableTile> availableTiles;
		Point piecePoint = selectedPiece->point;
		for (int i = piecePoint.xCoord + 1; i < 8; i++)
			if (CheckIfPointIsValid(Point(i, piecePoint.yCoord)) && CheckIfPointIsFree(playerTeam, Point(i, piecePoint.yCoord))) {
				if (CheckIfPointIsFree(enemyTeam, Point(i, piecePoint.yCoord))) {
					availableTiles.push_back(AvailableTile(Point(i, piecePoint.yCoord), true));
				}
				else {
					availableTiles.push_back(AvailableTile(Point(i, piecePoint.yCoord), true));
					break;
				}
			}
			else
				break;
		for (int i = piecePoint.xCoord - 1; i >= 0; i--)
			if (CheckIfPointIsValid(Point(i, piecePoint.yCoord)) && CheckIfPointIsFree(playerTeam, Point(i, piecePoint.yCoord))) {
				if (CheckIfPointIsFree(enemyTeam, Point(i, piecePoint.yCoord))) {
					availableTiles.push_back(AvailableTile(Point(i, piecePoint.yCoord), true));
				}
				else {
					availableTiles.push_back(AvailableTile(Point(i, piecePoint.yCoord), true));
					break;
				}
			}
			else
				break;
		for (int i = piecePoint.yCoord + 1; i < 8; i++)
			if (CheckIfPointIsValid(Point(piecePoint.xCoord, i)) && CheckIfPointIsFree(playerTeam, Point(piecePoint.xCoord, i))) {
				if (CheckIfPointIsFree(enemyTeam, Point(piecePoint.xCoord, i))) {
					availableTiles.push_back(AvailableTile(Point(piecePoint.xCoord, i), true));
				}
				else {
					availableTiles.push_back(AvailableTile(Point(piecePoint.xCoord, i), true));
					break;
				}
			}
			else
				break;
		for (int i = piecePoint.yCoord - 1; i >= 0; i--)
			if (CheckIfPointIsValid(Point(piecePoint.xCoord, i)) && CheckIfPointIsFree(playerTeam, Point(piecePoint.xCoord, i))) {
				if (CheckIfPointIsFree(enemyTeam, Point(piecePoint.xCoord, i))) {
					availableTiles.push_back(AvailableTile(Point(piecePoint.xCoord, i), true));
				}
				else {
					availableTiles.push_back(AvailableTile(Point(piecePoint.xCoord, i), true));
					break;
				}
			}
			else
				break;
		return availableTiles;
	}
	std::vector<AvailableTile> CalculateKnightMoves(Player& playerTeam, Player& enemyTeam, Piece* selectedPiece) {
		//izracunaj vse mozne poteze konja
		std::vector<AvailableTile> availableTiles;
		Point piecePoint = selectedPiece->point;
		Point leftUp1(-2, 1), leftUp2(-1, 2), leftDown1(-2, -1), leftDown2(-1, -2);
		Point rightUp1(2, 1), rightUp2(1, 2), rightDown1(2, -1), rightDown2(1, -2);
		if (CheckIfPointIsValid(piecePoint + leftUp1)
			&& CheckIfPointIsFree(playerTeam, piecePoint + leftUp1)
			|| !CheckIfPointIsFree(enemyTeam, piecePoint + leftUp1)) {
			availableTiles.push_back(AvailableTile(piecePoint + leftUp1, true));
		}
		if (CheckIfPointIsValid(piecePoint + leftUp2)
			&& CheckIfPointIsFree(playerTeam, piecePoint + leftUp2)
			|| !CheckIfPointIsFree(enemyTeam, piecePoint + leftUp2)) {
			availableTiles.push_back(AvailableTile(piecePoint + leftUp2, true));
		}
		if (CheckIfPointIsValid(piecePoint + leftDown1)
			&& CheckIfPointIsFree(playerTeam, piecePoint + leftDown1)
			|| !CheckIfPointIsFree(enemyTeam, piecePoint + leftDown1)) {
			availableTiles.push_back(AvailableTile(piecePoint + leftDown1, true));
		}
		if (CheckIfPointIsValid(piecePoint + leftDown2)
			&& CheckIfPointIsFree(playerTeam, piecePoint + leftDown2)
			|| !CheckIfPointIsFree(enemyTeam, piecePoint + leftDown2)) {
			availableTiles.push_back(AvailableTile(piecePoint + leftDown2, true));
		}
		if (CheckIfPointIsValid(piecePoint + rightUp1)
			&& CheckIfPointIsFree(playerTeam, piecePoint + rightUp1)
			|| !CheckIfPointIsFree(enemyTeam, piecePoint + rightUp1)) {
			availableTiles.push_back(AvailableTile(piecePoint + rightUp1, true));
		}
		if (CheckIfPointIsValid(piecePoint + rightUp2)
			&& CheckIfPointIsFree(playerTeam, piecePoint + rightUp2)
			|| !CheckIfPointIsFree(enemyTeam, piecePoint + rightUp2)) {
			availableTiles.push_back(AvailableTile(piecePoint + rightUp2, true));
		}
		if (CheckIfPointIsValid(piecePoint + rightDown1)
			&& CheckIfPointIsFree(playerTeam, piecePoint + rightDown1)
			|| !CheckIfPointIsFree(enemyTeam, piecePoint + rightDown1)) {
			availableTiles.push_back(AvailableTile(piecePoint + rightDown1, true));
		}
		if (CheckIfPointIsValid(piecePoint + rightDown2)
			&& CheckIfPointIsFree(playerTeam, piecePoint + rightDown2)
			|| !CheckIfPointIsFree(enemyTeam, piecePoint + rightDown2)) {
			availableTiles.push_back(AvailableTile(piecePoint + rightDown2, true));
		}
		return availableTiles;
	}
	std::vector<AvailableTile> CalculateBishopMoves(Player& playerTeam, Player& enemyTeam, Piece* selectedPiece) {
		//izracunaj vse mozne poteze tekaca
		std::vector<AvailableTile> availableTiles;
		Point piecePoint = selectedPiece->point;
		Point point1(piecePoint.xCoord - 1, piecePoint.yCoord + 1);
		while (point1.yCoord < 8 && point1.xCoord >= 0) {
			if (CheckIfPointIsValid(point1) && CheckIfPointIsFree(playerTeam, point1)) {
				if (CheckIfPointIsFree(enemyTeam, point1)) {
					availableTiles.push_back(AvailableTile(point1, true));
				}
				else {
					availableTiles.push_back(AvailableTile(point1, true));
					break;
				}
			}
			else
				break;
			point1.yCoord++;
			point1.xCoord--;
		}
		point1 = Point(piecePoint.xCoord + 1, piecePoint.yCoord - 1);
		while (point1.yCoord >= 0 && point1.xCoord < 8) {
			if (CheckIfPointIsValid(point1) && CheckIfPointIsFree(playerTeam, point1)) {
				if (CheckIfPointIsFree(enemyTeam, point1)) {
					availableTiles.push_back(AvailableTile(point1, true));
				}
				else {
					availableTiles.push_back(AvailableTile(point1, true));
					break;
				}
			}
			else
				break;
			point1.yCoord--;
			point1.xCoord++;
		}
		point1 = Point(piecePoint.xCoord + 1, piecePoint.yCoord - 1);
		while (point1.yCoord >= 0 && point1.xCoord < 8) {
			if (CheckIfPointIsValid(point1) && CheckIfPointIsFree(playerTeam, point1)) {
				if (CheckIfPointIsFree(enemyTeam, point1)) {
					availableTiles.push_back(AvailableTile(point1, true));
				}
				else {
					availableTiles.push_back(AvailableTile(point1, true));
					break;
				}
			}
			else
				break;
			point1.yCoord--;
			point1.xCoord++;
		}
		point1 = Point(piecePoint.xCoord + 1, piecePoint.yCoord + 1);
		while (point1.yCoord < 8 && point1.xCoord < 8) {
			if (CheckIfPointIsValid(point1) && CheckIfPointIsFree(playerTeam, point1)) {
				if (CheckIfPointIsFree(enemyTeam, point1)) {
					availableTiles.push_back(AvailableTile(point1, true));
				}
				else {
					availableTiles.push_back(AvailableTile(point1, true));
					break;
				}
			}
			else
				break;
			point1.yCoord++;
			point1.xCoord++;
		}
		point1 = Point(piecePoint.xCoord - 1, piecePoint.yCoord - 1);
		while (point1.yCoord >= 0 && point1.xCoord >= 0) {
			if (CheckIfPointIsValid(point1) && CheckIfPointIsFree(playerTeam, point1)) {
				if (CheckIfPointIsFree(enemyTeam, point1)) {
					availableTiles.push_back(AvailableTile(point1, true));
				}
				else {
					availableTiles.push_back(AvailableTile(point1, true));
					break;
				}
			}
			else
				break;
			point1.yCoord--;
			point1.xCoord--;
		}
		return availableTiles;
	}
	std::vector<AvailableTile> CalculateQueenMoves(Player& playerTeam, Player& enemyTeam, Piece* selectedPiece) {
		//izracunaj vse mozne poteze kraljice - vse poteze tekaca in trdnjave
		std::vector<AvailableTile> availableTiles;
		std::vector<AvailableTile>A;
		std::vector<AvailableTile>B;

		A = CalculateBishopMoves(playerTeam, enemyTeam, selectedPiece);
		B = CalculateRookMoves(playerTeam, enemyTeam, selectedPiece);

		availableTiles.reserve(A.size() + B.size());
		availableTiles.insert(availableTiles.end(), A.begin(), A.end());
		availableTiles.insert(availableTiles.end(), B.begin(), B.end());

		return availableTiles;
	}
	std::vector<AvailableTile> CalculateKingMoves(Player& playerTeam, Player& enemyTeam, Piece* selectedPiece) {
		//izracunaj vse mozne poteze kralja
		std::vector<AvailableTile> availableTiles;
		Point piecePoint = selectedPiece->point;
		Point point1 = piecePoint;
		point1.xCoord = piecePoint.xCoord + 1;
		if (CheckIfPointIsValid(point1) && (CheckIfPointIsFree(playerTeam, point1) || !CheckIfPointIsFree(enemyTeam, point1))) {
			availableTiles.push_back(AvailableTile(point1, true));
		}
		point1.xCoord = piecePoint.xCoord - 1;
		if (CheckIfPointIsValid(point1) && (CheckIfPointIsFree(playerTeam, point1) || !CheckIfPointIsFree(enemyTeam, point1))) {
			availableTiles.push_back(AvailableTile(point1, true));
		}
		point1.xCoord = piecePoint.xCoord + 1; point1.yCoord = piecePoint.yCoord + 1;
		if (CheckIfPointIsValid(point1) && (CheckIfPointIsFree(playerTeam, point1) || !CheckIfPointIsFree(enemyTeam, point1))) {
			availableTiles.push_back(AvailableTile(point1, true));
		}
		point1.xCoord = piecePoint.xCoord + 1; point1.yCoord = piecePoint.yCoord - 1;
		if (CheckIfPointIsValid(point1) && (CheckIfPointIsFree(playerTeam, point1) || !CheckIfPointIsFree(enemyTeam, point1))) {
			availableTiles.push_back(AvailableTile(point1, true));
		}
		point1.xCoord = piecePoint.xCoord - 1; point1.yCoord = piecePoint.yCoord - 1;
		if (CheckIfPointIsValid(point1) && (CheckIfPointIsFree(playerTeam, point1) || !CheckIfPointIsFree(enemyTeam, point1))) {
			availableTiles.push_back(AvailableTile(point1, true));
		}
		point1.xCoord = piecePoint.xCoord - 1; point1.yCoord = piecePoint.yCoord + 1;
		if (CheckIfPointIsValid(point1) && (CheckIfPointIsFree(playerTeam, point1) || !CheckIfPointIsFree(enemyTeam, point1))) {
			availableTiles.push_back(AvailableTile(point1, true));
		}
		point1 = piecePoint;
		point1.yCoord++;
		if (CheckIfPointIsValid(point1) && (CheckIfPointIsFree(playerTeam, point1) || !CheckIfPointIsFree(enemyTeam, point1))) {
			availableTiles.push_back(AvailableTile(point1, true));
		}
		point1.yCoord -= 2;
		if (CheckIfPointIsValid(point1) && (CheckIfPointIsFree(playerTeam, point1) || !CheckIfPointIsFree(enemyTeam, point1))) {
			availableTiles.push_back(AvailableTile(point1, true));
		}
		return availableTiles;
	}
	std::vector<AvailableTile> CalculateDefendKing(Player& playerTeam, Player& enemyTeam, Tile* tiles[], Piece* selectedPiece, Point kingPoint) {
		//izracuna vse mozne poteze za obrambo kralja pred sahom in sah matom
		std::vector<AvailableTile> availableTiles;
		std::vector<AvailableTile> tmp;

		Point originalPoint;

		int id;
		Piece* newPiece = NULL;

		originalPoint = selectedPiece->point;
		switch (selectedPiece->type) {
		case Pawn:
			tmp = calc::CalculatePawnMoves(playerTeam, enemyTeam, selectedPiece, Point(-1, -1), Point(1, -1), Point(0, -1)); break;
		case Rook:
			tmp = calc::CalculateRookMoves(playerTeam, enemyTeam, selectedPiece); break;
		case Knight:
			tmp = calc::CalculateKnightMoves(playerTeam, enemyTeam, selectedPiece); break;
		case Bishop:
			tmp = calc::CalculateBishopMoves(playerTeam, enemyTeam, selectedPiece); break;
		case Queen:
			tmp = calc::CalculateQueenMoves(playerTeam, enemyTeam, selectedPiece); break;
		case King:
			tmp = calc::CalculateKingMoves(playerTeam, enemyTeam, selectedPiece); break;
		}
		for (auto& availablePoint : tmp) {
			selectedPiece->point = availablePoint.point;
			if (selectedPiece->type == King)
				kingPoint = selectedPiece->point;
			for (int i = 0; i < 16; i++) {
				if (enemyTeam.pieces[i] != NULL && enemyTeam.pieces[i]->point == selectedPiece->point) {
					id = i;
					newPiece = new Piece(*enemyTeam.pieces[i]);
					delete enemyTeam.pieces[i];
				}
			}
			if (CalculateCheck(playerTeam, enemyTeam, kingPoint))
				FindTile(tiles, availablePoint.point)->Available(false);
			else
				availableTiles.push_back(availablePoint);
			if (newPiece != NULL) {
				enemyTeam.pieces[id] = new Piece(*newPiece);
				delete newPiece;
				newPiece = NULL;
			}
		}
		selectedPiece->point = originalPoint;

		return availableTiles;
	}
	std::vector<AvailableTile> CalculateCastle(Player& playerTeam, Player& enemyTeam, Point kingPoint, bool team) {
		std::vector<AvailableTile> availableTiles;
		int mult;
		if (team)
			mult = 1;
		else
			mult = -1;

		if (!playerTeam.hasCastled && !CalculateCheck(playerTeam, enemyTeam, kingPoint)) {
			Piece* rookPiece;
			//desna
			rookPiece = FindPiece(playerTeam, enemyTeam, Point(7, 7));
			if (rookPiece != NULL && rookPiece->IsHistoryEmpty()) {
				if (calc::CheckIfPointIsFree(playerTeam, kingPoint + Point(mult * 1, 0))
					&& calc::CheckIfPointIsFree(playerTeam, kingPoint + Point(mult * 2, 0))
					&& calc::CheckIfPointIsFree(enemyTeam, kingPoint + Point(mult * 1, 0))
					&& calc::CheckIfPointIsFree(enemyTeam, kingPoint + Point(mult * 2, 0))
					&& !CalculateCheck(playerTeam, enemyTeam, Point(kingPoint.xCoord + mult * 1, kingPoint.yCoord))
					&& !CalculateCheck(playerTeam, enemyTeam, Point(kingPoint.xCoord + mult * 2, kingPoint.yCoord)))
					availableTiles.push_back(AvailableTile(Point(kingPoint.xCoord + mult * 2, kingPoint.yCoord), true));
			}
			//leva
			rookPiece = FindPiece(playerTeam, enemyTeam, Point(0, 7));
			if (rookPiece != NULL && rookPiece->IsHistoryEmpty()) {
				if (calc::CheckIfPointIsFree(playerTeam, kingPoint + Point(-mult * 1, 0))
					&& calc::CheckIfPointIsFree(playerTeam, kingPoint + Point(-mult * 2, 0))
					&& calc::CheckIfPointIsFree(playerTeam, kingPoint + Point(-mult * 3, 0))
					&& calc::CheckIfPointIsFree(enemyTeam, kingPoint + Point(-mult * 1, 0))
					&& calc::CheckIfPointIsFree(enemyTeam, kingPoint + Point(-mult * 2, 0))
					&& calc::CheckIfPointIsFree(enemyTeam, kingPoint + Point(-mult * 3, 0))
					&& !CalculateCheck(playerTeam, enemyTeam, Point(kingPoint.xCoord - mult * 1, kingPoint.yCoord))
					&& !CalculateCheck(playerTeam, enemyTeam, Point(kingPoint.xCoord - mult * 2, kingPoint.yCoord)))
					availableTiles.push_back(AvailableTile(Point(kingPoint.xCoord - mult * 2, kingPoint.yCoord), true));
			}
		}
		return availableTiles;
	}
	bool CalculateCheck(Player& playerTeam, Player& enemyTeam, Point kingPoint) {
		//izracuna ali je kralj v sahu ali ne
		std::vector<AvailableTile> tmp;

		for (int i = 0; i < 16; i++) {
			if (enemyTeam.pieces[i] != NULL) {
				switch (enemyTeam.pieces[i]->type) {
				case Pawn: {
					tmp = calc::CalculatePawnMoves(enemyTeam, playerTeam, enemyTeam.pieces[i], Point(1, 1), Point(-1, 1), Point(0, 1));
					for (int i = 0; i < tmp.size(); i++) {
						if (tmp[i].point == kingPoint)
							return true;
					}
				}
						 break;
				case Rook: {
					tmp = calc::CalculateRookMoves(enemyTeam, playerTeam, enemyTeam.pieces[i]);
					for (int i = 0; i < tmp.size(); i++)
						if (tmp[i].point == kingPoint)
							return true;
				}
						 break;
				case Knight: {
					tmp = calc::CalculateKnightMoves(enemyTeam, playerTeam, enemyTeam.pieces[i]);
					for (int i = 0; i < tmp.size(); i++)
						if (tmp[i].point == kingPoint)
							return true;
				}
						   break;
				case Bishop: {
					tmp = calc::CalculateBishopMoves(enemyTeam, playerTeam, enemyTeam.pieces[i]);
					for (int i = 0; i < tmp.size(); i++)
						if (tmp[i].point == kingPoint)
							return true;
				}
						   break;
				case Queen: {
					tmp = calc::CalculateQueenMoves(enemyTeam, playerTeam, enemyTeam.pieces[i]);
					for (int i = 0; i < tmp.size(); i++)
						if (tmp[i].point == kingPoint)
							return true;
				}
						  break;
				case King: {
					tmp = calc::CalculateKingMoves(enemyTeam, playerTeam, enemyTeam.pieces[i]);
					for (int i = 0; i < tmp.size(); i++)
						if (tmp[i].point == kingPoint)
							return true;
				}
						 break;
				}
			}
		}
		return false;
	}
	void CalculateValidMoves(Player& team1, Player& team2, Tile* tiles[],  Piece* selectedPiece, bool team) {
		std::vector<AvailableTile> availableTiles;
		Point piecePoint;

		piecePoint.xCoord = selectedPiece->point.xCoord;
		piecePoint.yCoord = selectedPiece->point.yCoord;

		Piece* kingPiece = NULL;
		//poisce figuro kralj
		for (int i = 0; i < 16; i++)
			if (team1.pieces[i] != NULL && team1.pieces[i]->type == King) {
				kingPiece = team1.pieces[i];
			}
		//preveri ali je igralec v sahu
		if (kingPiece != NULL) {
			team1.isInCheck = calc::CalculateCheck(team1, team2, kingPiece->point);
		}
		//preveri ali je igralec v sah matu
		if (team1.isInCheck) {
			//preveri koliko moznih potez ima igralec v sahu
			for (auto& piece : team1.pieces) {
				if (piece != NULL) {
					availableTiles = calc::CalculateDefendKing(team1, team2, tiles, piece, kingPiece->point);
					if (availableTiles.size() > 0)
						break;
				}
			}
			//ce igralec nima nobenih moznih potez je igre konec
			if (availableTiles.size() == 0)
				team1.isCheckmated = true;
			else {
				//poracuna vse mozne poteze ki preprecijo sah oz. sahmat
				availableTiles = calc::CalculateDefendKing(team1, team2, tiles, selectedPiece, kingPiece->point);

				for (auto& availableTile : availableTiles)
					FindTile(tiles, availableTile.point)->Available(true);
			}
		}
		else {
			//poracunaj vse mozne poteze glede na izbrano figuro
			switch (selectedPiece->type) {
			case Pawn: {
				//kmet
				availableTiles = calc::CalculatePawnMoves(team1, team2, selectedPiece, Point(-1, -1), Point(1, -1), Point(0, -1));
				for (int i = 0; i < availableTiles.size(); i++)
					if (availableTiles[i].isAvailable)
						FindTile(tiles, availableTiles[i].point)->Available(true);
			}
					 break;
			case Rook: {
				//trdnjava
				availableTiles = calc::CalculateRookMoves(team1, team2, selectedPiece);
				for (int i = 0; i < availableTiles.size(); i++)
					if (availableTiles[i].isAvailable)
						FindTile(tiles, availableTiles[i].point)->Available(true);
			}
					 break;
			case Knight: {
				//konj
				availableTiles = calc::CalculateKnightMoves(team1, team2, selectedPiece);
				for (int i = 0; i < availableTiles.size(); i++)
					if (availableTiles[i].isAvailable)
						FindTile(tiles, availableTiles[i].point)->Available(true);
			}
					   break;
			case Bishop: {
				//tekac
				availableTiles = calc::CalculateBishopMoves(team1, team2, selectedPiece);
				for (int i = 0; i < availableTiles.size(); i++)
					if (availableTiles[i].isAvailable)
						FindTile(tiles, availableTiles[i].point)->Available(true);
			}
					   break;
			case Queen: {
				//kraljica - trdnjava in tekac
				availableTiles = calc::CalculateQueenMoves(team1, team2, selectedPiece);
				for (int i = 0; i < availableTiles.size(); i++)
					if (availableTiles[i].isAvailable)
						FindTile(tiles, availableTiles[i].point)->Available(true);
			}
					  break;
			case King: {
				//kralj
				availableTiles = calc::CalculateKingMoves(team1, team2, selectedPiece);
				std::vector<AvailableTile> tmp = calc::CalculateCastle(team1, team2, selectedPiece->point, team);
				availableTiles.insert(availableTiles.end(), tmp.begin(), tmp.end());
				for (int i = 0; i < availableTiles.size(); i++)
					if (availableTiles[i].isAvailable)
						FindTile(tiles, availableTiles[i].point)->Available(true);
			}
					 break;
			}
			//odstrani poteze ki dajo sah igralcu
			Point originalPoint = selectedPiece->point;
			Piece* tmpPiece = NULL;

			for (auto& availablePoint : availableTiles) {
				selectedPiece->point = availablePoint.point;
				if (calc::CalculateCheck(team1, team2, kingPiece->point)) {
					FindTile(tiles, availablePoint.point)->Available(false);
				}
				for (int i = 0; i < 16; i++) {
					if (team2.pieces[i] != NULL && selectedPiece->point == team2.pieces[i]->point && tmpPiece == NULL) {
						tmpPiece = new Piece(*team2.pieces[i]);
						delete team2.pieces[i];
						team2.pieces[i] = NULL;
						if (!calc::CalculateCheck(team1, team2, kingPiece->point)) {
							FindTile(tiles, availablePoint.point)->Available(true);
						}
						team2.pieces[i] = new Piece(*tmpPiece);
						delete tmpPiece;
						tmpPiece = NULL;
					}
				}
			}
			selectedPiece->point = originalPoint;
		}
	}
	bool CheckIfPointIsValid(Point point) {
		//preveri ali je polje znotraj plosce
		if (point.xCoord >= 0 && point.xCoord < 8 && point.yCoord >= 0 && point.yCoord < 8)
			return true;
		return false;
	}
	bool CheckIfPointIsFree(Player& _team, Point point) {
		//preveri ali je polje prosto
		for (int i = 0; i < 16; i++) {
			if (_team.pieces[i] != NULL)
				if (_team.pieces[i]->point == point)
					return false;
		}
		return true;
	}
	Tile* FindTile(Tile* tiles[], Point point) {
		//poisci polje glede na podano lokacijo
		for (int i = 0; i < 64; i++)
				if (tiles[i]->point == point)
					return tiles[i];
		return NULL;
	}
	Piece* FindPiece(Player& team1, Player& team2, Point point) {
		//poisci figuro glede na podano lokacijo
		Piece* piece = NULL;

		for (int i = 0; i < 16; i++)
			if (team1.pieces[i] != NULL && team1.pieces[i]->point == point)
				piece = team1.pieces[i];
		if (!piece)
			for (int i = 0; i < 16; i++)
				if (team2.pieces[i] != NULL && team2.pieces[i]->point == point)
					piece = team2.pieces[i];
		return piece;
	}
	void Castle(Player& playerTeam, Player& enemyTeam, Point kingPoint, bool team) {
		Piece* rookPiece;
		int x1 = 5, x2 = 1;
		int id = 0;
		if (team) {
			x1 = 6;
			x2 = 2;
		}
		if (kingPoint.xCoord == x1) {
			rookPiece = FindPiece(playerTeam, enemyTeam, Point(7, 7));
			rookPiece->Move(Point(kingPoint.xCoord - 1, 7));
		}
		else {
			rookPiece = FindPiece(playerTeam, enemyTeam, Point(0, 7));
			rookPiece->Move(Point(kingPoint.xCoord + 1, 7));
		}
		if (team)
			id = History::AddMove(History::Convert(rookPiece->point.xCoord, 7, rookPiece->ID, true));
		else {
			if (rookPiece->point.xCoord == 2)
				id = History::AddMove(History::Convert(5, 0, rookPiece->ID, false));
			else
				id = History::AddMove(History::Convert(3, 0, rookPiece->ID, false));
		}
		rookPiece->AddHistory(History::GetMove(id));
	}
}