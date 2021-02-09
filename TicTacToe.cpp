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
        for(int j = 0; j < 3; j++)
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

//Function to return the position that the player chooses
Position GetPlayerChoice(std::vector<std::vector<std::string>> board) {
    int row;
    int col;
    //Keep iterating until we get a valid input
    while (1){
        std::cout << "Enter Choice:" << std::endl;
        std::cout << "Row: ";
        std::cin >> row;
        std::cout << "Col: ";
        std::cin >> col;
	//If valid postion ie not already taken space
        if (board[row-1][col-1] != "⭕" && board[row-1][col-1] != "❌") {
            Position pos{row-1,col-1};
	    return pos;
        }
	//Invalid position means we try to get input again
        else 
            std::cout << "Invalid position!" << std::endl;
    }
}


int main(){
	std::vector<std::vector<std::string>> board=CreateBoard();
	DisplayBoard(board);
	return 0;
}
