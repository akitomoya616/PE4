CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: main

clean:
	rm  main

main:  TicTacToe.cpp
	$(CXX) $(CXXFLAGS) TicTacToe.cpp -o main

