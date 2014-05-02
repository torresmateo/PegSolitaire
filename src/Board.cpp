#include "Board.hpp"
#include <iostream>
#include <cstdlib>
Board::Board(BoardType type, int width, int height)
{
	Width = width;
	Height = height;
	Type = type;
}


BoardType Board::getType()
{
	return Type;
}

int Board::getWidth()
{
	return Height;
}

int Board::getHeight()
{
	return Height;
}

//generacion de tableros

void Board::generateBoard(string configuration)
{
	switch(Type){
	case SQUARE:
		//peg allocation
		for(int i = 0; i < Height; i++){
			for(int j = 0; j < Width; j++){
				Pegs.push_back(Peg(FILLED));
			}
		}
		//peg relations
		for(int i = 0; i < Width; i++){
			for(int j = 0; j < Height; j++){
				//link north
				if(i > 0)
					Pegs[Width*i + j].addAdjacentPeg(NORTH, Pegs[ Width*(i-1) + j]);
				//link east
				if(j < Width - 1) 
					Pegs[Width*i + j].addAdjacentPeg(EAST, Pegs[ Width*i + j + 1]);
				//link south
				if(i < Height - 1) 
					Pegs[Width*i + j].addAdjacentPeg(SOUTH, Pegs[ Width*(i+1) + j]);
				//link west
				if(j > 0) 
					Pegs[Width*i + j].addAdjacentPeg(WEST, Pegs[ Width*i + j - 1]);
			}
		}
		
		break;
	case HEXAGON:
		break;
	default:
		exit(1);
	}
	cout << "iterator" << endl;
	for(vector<Peg>::iterator itPegs = Pegs.begin(); itPegs != Pegs.end(); ++itPegs){
		cout << "A=======" << endl;
		map<PegPosition, Peg> adjacentPegs = itPegs->getAdjacentPegs();
		for(map<PegPosition, Peg>::iterator itAdjacentPeg = adjacentPegs.begin(); 
			itAdjacentPeg != adjacentPegs.end(); 
			++itAdjacentPeg){
			Peg AdjacentPeg = itAdjacentPeg->second; 
			cout << "a" << Peg::getPositionName(itAdjacentPeg->first) << endl;
		}
	}
}

