#include <iostream>
#include<vector>
struct Position {
	int row;
	int col;
	bool operator==(const Position &other) {
		return row == other.row && col == other.col;
	}
};


std::vector<std::vector<std::string>> CreateBoard(){
	std::vector<std::vector<std::string>> board(3, std::vector<std::string> (3, "⬜"));
	return board;
}



int main(){
	std::vector<std::vector<std::string>> board=CreateBoard();
	return 0;
}