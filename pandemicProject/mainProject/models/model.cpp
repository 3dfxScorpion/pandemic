#include "model.h"



// Default constructor
model::model()
{
	//set default values
	numPlayers = -1;								
	currentRate = 0;
	outbreak = 0;
	infRate[0] = infRate[1] = infRate[2] = 2;
	infRate[3] = infRate[4] = 3;
	infRate[5] = infRate[6] = 4; 
	

	//initialize cube count to 24, and all diseases to uncured
	for(int i = 0; i <4; i++)
	{
		cubes[i] = 24;
		cureStatus[i] = uncured;
	}
}


void model::setNumPlayers(int num)
{
	numPlayers = num;
	return;
}

void model::incOutbreak()
{
	outbreak++;
	return;
}

// currentRate six indexes seventh and highest infection rate
// method increments if not already at six
void model::incCurrentRate()
{
	if(currentRate < 6)
		currentRate++;

	return;
}

//takes index of desired disease as parameter, changes cure status to cured
//function currently ignores improper parameter value
void model::cureDisease(int disease)
{
	if (0 <= disease && disease <= 3)
		cureStatus[disease] = cured;

	return;
	
}

//takes index of desired disease as parameter, changes cure status to erad
//function currently ignores improper parameter value
void model::eradicateDisease(int disease)
{
	if (0 <= disease && disease <= 3)
		cureStatus[disease] = eradicated;

	return;
}


//removes "count" cubes from the available amount
// possible for cubes[color] to be negative, which should be a quit condition in the controller
void model::removeCubes(int color, int count)
{
	cubes[color] = cubes[color] - count;
}

//takes index of desired disease as parameter, returns number of cubes to be played
// function currently ignores improper parameter value
int model::getCubeCount(int disease)
{
	return(cubes[disease]);
}


int model::getInfRate()
{
	return( infRate[currentRate] );
}


int model::getNumPlayers()
{
	return numPlayers;
}


int model::getOutbreak()
{
	return outbreak;
}