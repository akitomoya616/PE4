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


void DisplayBoard(std::vector<std::vector<std::string>> board) {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; col++)
            std::cout<<board[i][j]<<" ";
        std::cout << std::endl;
    }

}

void PlaceMarker(int *player, Position new_position, std::vector<std::vector<std::string>> &board){
	if(*player==0){
		board[new_position.row][new_position.col]="⭕";
		*player=1;
	}
	else{
		board[new_position.row][new_position.col]="❌";
		*player=0;
	}
	
}

int main(){
	std::vector<std::vector<std::string>> board=CreateBoard();
	DisplayBoard(board);
	return 0;
}
