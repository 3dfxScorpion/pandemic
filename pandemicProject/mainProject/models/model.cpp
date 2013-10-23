#include "model.h"



// Default constructor
model::model()
{
	//set default values
	numPlayers = -1;								
	currentRate = outbreak = resSta = 0;							//inits
	infRate[0] = infRate[1] = infRate[2] = 2;
	infRate[3] = infRate[4] = 3;
	infRate[5] = infRate[6] = 4; 
	

	//initialize cube count to 24, and all diseases to uncured
	for(int i = 0; i <4; i++)
	{
		cubes[i] = 24;
		cureStatus[i] = uncured;
	}

	//set the roles vector
	rolesDeck.push_back("Contingency Planner");
	rolesDeck.push_back("Operations Expert");
	rolesDeck.push_back("Dispatcher");
	rolesDeck.push_back("Quarantine Specialist");
	rolesDeck.push_back("Medic");
	rolesDeck.push_back("Scientist");
	rolesDeck.push_back("Researcher");
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


// returns a random role as a string
string model::drawRole()
{
	int num;
	string tmp;
	srand(time_t(0));									//getting seedy
	num = rand() % rolesDeck.size();					//index into the deck;
	tmp = rolesDeck[num];								//store the role
	rolesDeck.erase(rolesDeck.begin()+num);				//erase from ze vectah

	return tmp;											//return that bad bitch
}









