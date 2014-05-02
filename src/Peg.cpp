#include "Peg.hpp"
#include <cstdlib>
#include <iostream>

Peg::Peg(PegState state)
{
	State = state;
	adjQty = 0;
}

map<PegPosition, Peg> Peg::getAdjacentPegs()
{
	return adjacentPegs;
}

PegState Peg::getState()
{
	return State;
}

bool Peg::taken(PegPosition pos)
{
	map<PegPosition,Peg>::const_iterator it = adjacentPegs.find(pos);
	return it!=adjacentPegs.end();
}

void Peg::addAdjacentPeg(PegPosition pos, Peg &peg)
{
	//to avoid infinite recursion
	if(taken(pos))
		return;

	PegPosition inversePosition;
	switch(pos){
	case NORTH:
		inversePosition = SOUTH;
		break;
	case SOUTH:
		inversePosition = NORTH;
		break;
	case WEST:
		inversePosition = EAST;
		break;
	case EAST:
		inversePosition = WEST;
		break;
	case NORTHWEST:
		inversePosition = SOUTHEAST;
		break;
	case NORTHEAST:
		inversePosition = SOUTHWEST;
		break;
	case SOUTHWEST:
		inversePosition = NORTHEAST;
		break;
	case SOUTHEAST:
		inversePosition = NORTHWEST;
		break;
	case UP:
		inversePosition = DOWN;
		break;
	case DOWN:
		inversePosition = UP;
		break;
	default:
		exit(1);
	}       
	
	adjacentPegs.insert(pair<PegPosition, Peg>(pos,peg));
	peg.addAdjacentPeg(inversePosition, *this);
	adjQty++;
}
