#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>
#include "Peg.hpp"

using namespace std;

enum BoardType{
	SQUARE,
	HEXAGON
};

//Bidimensional Board
class Board
{
	BoardType Type;
	int Width;
	int Height;
	vector<Peg> Pegs;
public:

	Board(BoardType type, int width, int height);
	BoardType getType();
    int getHeight();
    int getWidth();
	
	//generacion de tableros
	void generateBoard(string configuration);
	
};

#endif


