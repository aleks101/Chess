#include "Data.h"

const string Data::filePath = "Files/Save/";

void Data::CreateFile(string fileName) {
	string fullPath = filePath + fileName;
	ofstream data(fullPath, ios::out | ios::binary);
	data.close();
}
void Data::DeleteFile(string fileName) {
	string fullPath = filePath + fileName;
	if (remove(fullPath.c_str()) == 0)
		printf("Deleted successfully");
	else
		printf("Unable to delete the file");
}
void Data::WriteToFile(string fileName, vector<PieceMove> moves) {
	string fullPath = filePath + fileName;

	ofstream data(fullPath, ios::out | ios::binary);
	if (!data) {
		cout << "WRITE: cannot open file " << fullPath << endl;
	}
	else {
		for (auto& piece : moves) {
			data.write((char*)&piece, sizeof(PieceMove));
		}
	}
	data.close();
}
vector<PieceMove> Data::ReadFromFile(string fileName) {
	string fullPath = fileName;
	vector<PieceMove> moves;
	ifstream data(fullPath, ios::binary);
	if (!data) {
		cout << "READ: cannot open file " << fullPath << endl;
	}
	else {
		PieceMove move;
		while (data.read((char*) & move, sizeof(PieceMove))) {
			cout << move.alp << " : " << move.num << " : " << move.pieceID << " : " << move.team << endl;
			moves.push_back(move);
		}
	}
	data.close();

	return moves;
}