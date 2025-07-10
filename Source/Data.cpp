#include "Data.h"

const std::string Data::filePath = "Files/Save/";

void Data::CreateFile(std::string fileName) {
	std::string fullPath = filePath + fileName;
	std::ofstream data(fullPath, std::ios::out | std::ios::binary);
	data.close();
}
void Data::DeleteFile(std::string fileName) {
	std::string fullPath = fileName;
	std::cout << "FILEPATH: " << filePath << std::endl;
	std::cout << "FILENAME: " << fileName << std::endl;
	std::cout << "FULLPATH: " << fullPath << std::endl;
	if (remove(fullPath.c_str()) == 0)
		printf("Deleted successfully");
	else
		printf("Unable to delete the file");
}
void Data::WriteToFile(std::string fileName, std::vector<PieceMove> moves) {
	std::string fullPath = filePath + fileName;

	std::ofstream data(fullPath, std::ios::out | std::ios::binary);
	if (!data) {
		std::cout << "WRITE: cannot open file " << fullPath << std::endl;
	}
	else {
		for (auto& piece : moves) {
			data.write((char*)&piece, sizeof(PieceMove));
		}
	}
	data.close();
}
std::vector<PieceMove> Data::ReadFromFile(std::string fileName) {
	std::string fullPath = fileName;
	std::vector<PieceMove> moves;
	std::ifstream data(fullPath, std::ios::binary);
	if (!data) {
		std::cout << "READ: cannot open file " << fullPath << std::endl;
	}
	else {
		PieceMove move;
		while (data.read((char*) & move, sizeof(PieceMove))) {
			std::cout << move.alp << " : " << move.num << " : " << move.pieceID << " : " << move.team << std::endl;
			moves.push_back(move);
		}
	}
	data.close();

	return moves;
}