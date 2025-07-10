#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

#include "PieceMove.h"

class Data
{
private:
	const static std::string filePath;
public:
	static void CreateFile(std::string fileName);
	static void WriteToFile(std::string fileName, std::vector<PieceMove> moves);
	static std::vector<PieceMove> ReadFromFile(std::string fileName);
	static void DeleteFile(std::string fileName);
};

