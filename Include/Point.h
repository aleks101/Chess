#pragma once

class Point
{
public:
	int xCoord, yCoord;
	Point() : xCoord(0), yCoord(0) { }
	Point(int x, int y) { xCoord = x; yCoord = y; }
	Point(const Point& _point) { xCoord = _point.xCoord; yCoord = _point.yCoord; }
	Point operator+(Point point) {
		Point tmp(xCoord, yCoord);
		tmp.xCoord += point.xCoord;
		tmp.yCoord += point.yCoord;
		return tmp;
	}
	bool operator==(Point point) {
		if (xCoord == point.xCoord && yCoord == point.yCoord)
			return true;
		return false;
	}
};

