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

void PlaceMarker(int *player, int *row, int *col, std::vector<std::vector<std::string>> &board){
	if(*player==0){
		board[*row][*col]="⭕";
		*player=1;
	}
	else{
		board[*row][*col]="❌";
		*player=0;
	}
	
}

Position GetPlayerChoice() {
    int row;
    int col;
    while (1){
        std::cout << "Enter Choice:" << std::endl;
        std::cout << "Row: ";
        std::cin >> row;
        std::cout << "Col: ";
        std::cin >> col;
        if (board[row-1][col-1] != "⭕" && board[row-1][col-1] != "❌") {
            Position pos{row-1,col-1};
	    return pos;
        }
        else 
            std::cout << "Invalid position!" << std::endl;
    }
}


int main(){
	std::vector<std::vector<std::string>> board=CreateBoard();
	DisplayBoard(board);
	return 0;
}
