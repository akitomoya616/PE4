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

void DisplayBoard(std::vector<std::vector<std::string>> board){
	for(std::vector<std::vector<std::string>>::size_type i = 0; i<board.size(); i++){
		for(std::vector<std::string>::size_type j = 0; j < board[i].size(); j++){
			std::cout<<board[i][j]<<"   ";
		}
		std::cout<<std::endl;
	}
}

int main(){
	std::vector<std::vector<std::string>> board=CreateBoard();
	DisplayBoard(board);
	return 0;
}