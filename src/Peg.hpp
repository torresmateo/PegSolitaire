#ifndef PEG_HPP
#define PEG_HPP

#include <map>
#include <cstdlib>
#include <string>
using namespace std;

enum PegState{
	FILLED,
	EMPTY
};

enum PegPosition{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	NORTHWEST,
	NORTHEAST,
	SOUTHWEST,
	SOUTHEAST,
	UP,
	DOWN
};

//Individual Peg
class Peg
{

	PegState State;
	//all possible adjacent pegs
	map<PegPosition, Peg> adjacentPegs;

	//adjacent peg counter
	int adjQty;

	//utilitarios
	bool taken(PegPosition pos);
	
public:
	
	Peg(PegState state);
	//getters
	map<PegPosition, Peg> getAdjacentPegs();
	PegState getState();
	
	//setters
	void setState(PegState state);
	void addAdjacentPeg(PegPosition pos, Peg &peg);

	static string getPositionName(PegPosition pos)
	{
		switch(pos){
		case NORTH:
			return "SOUTH";
		case SOUTH:
			return "NORTH";
		case WEST:
			return "EAST";
		case EAST:
			return "WEST";
		case NORTHWEST:
			return "SOUTHEAST";
		case NORTHEAST:
			return "SOUTHWEST";
		case SOUTHWEST:
			return "NORTHEAST";
		case SOUTHEAST:
			return "NORTHWEST";
		case UP:
			return "DOWN";
		case DOWN:
			return "UP";
		default:
			exit(1);
		}       
	}
};

#endif


