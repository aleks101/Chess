#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "PieceMove.h"

using namespace std;

class Data
{
private:
	const static string filePath;
public:
	static void CreateFile(string fileName);
	static void WriteToFile(string fileName, vector<PieceMove> moves);
	static vector<PieceMove> ReadFromFile(string fileName);
	static void DeleteFile(string fileName);
};

