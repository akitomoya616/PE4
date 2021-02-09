#include <iostream>
#include<vector>

struct Position {
	int row;
	int col;
	bool operator==(const Position &other) {
		return row == other.row && col == other.col;
	}
};

//create a board using a 2d vector, a vector that contains another vector which stores string values
std::vector<std::vector<std::string>> CreateBoard(){
	std::vector<std::vector<std::string>> board(3, std::vector<std::string> (3, "⬜"));
	return board;
}

void DisplayBoard(std::vector<std::vector<std::string>> board) {
	//print the vector in three lines to form a board
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            std::cout<<board[i][j]<<" ";
        std::cout << std::endl;
    }

}

void PlaceMarker(int *player, Position new_position, std::vector<std::vector<std::string>> &board){
	//update board information based on the given position and the current player's pointer
	//then switch to the next player
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
Position GetPlayerChoice(std::vector<std::vector<std::string>> &board) {
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
	//initialize a board and print it on the screen
	std::vector<std::vector<std::string>> board=CreateBoard();
	DisplayBoard(board);
	//initialize a position, player number, and turn counter
	Position new_position;
	int player=0;
	int turn=0;
	//do the following steps for each player for 9 turns until the board is full
	while(turn<9){
		new_position=GetPlayerChoice(board);
		PlaceMarker(&player,new_position,board);
		DisplayBoard(board);
		turn++;
	}
	return 0;
}
