#include "model.h"



// Default constructor
Model::Model()
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

	// Populate World Map
	if (worldMap.populateMap("Cities.txt") != 0 ) {
        cout << "Please make sure file is located in working directory...\n";    //update later to throw exception
        
    }
}




// currentRate six indexes seventh and highest infection rate
// method increments if not already at six
void Model::incrementCurrentRate()
{
	if(currentRate < 6)
		currentRate++;

	return;
}

//takes index of desired disease as parameter, changes cure status to cured
//function currently ignores improper parameter value
void Model::cureDisease(int disease)
{
	if (0 <= disease && disease <= 3)
		cureStatus[disease] = cured;

	return;
	
}

//takes index of desired disease as parameter, changes cure status to erad
//function currently ignores improper parameter value
void Model::eradicateDisease(int disease)
{
	if (0 <= disease && disease <= 3)
		cureStatus[disease] = eradicated;

	return;
}


// returns a random role as a string
string Model::drawRole()
{
	int num;
	string tmp;
	srand(time(NULL));									//getting seedy
	num = rand() % rolesDeck.size();					//index into the deck;
	tmp = rolesDeck[num];								//store the role
	rolesDeck.erase(rolesDeck.begin()+num);				//erase from ze vectah

	return tmp;											//return that bad bitch
}




void Model::prepareGame()
{
	City* cityP;
	//Set up the game:
	//	Place research  and players in atlantastation in Atlanta
	//	Assign roles to players
	//	Shuffle deck, distribute epidemic cards evenly (4, 5, or 6 epids for easy med hard)
	//	Deal cards: 2 players-4 cards, 3players-3 cards, 4 players -2 cards
	cityP = worldMap.locateCity("Atlanta");//find atlanta
	cityP->setResearchStation(true);//set the station
	incResSta();//increment ressta count
	for (int i = 0; i < getNumPlayers(); i++)  //for all players
	{
		players[i].setPlayerRole(drawRole());	// assign a random role
		players[i].setPlayerLocation(cityP);			//set all player locations to Atlanta
	}

	//draw inital hand:
	// players initially draw (6-numPlayers) cards
	for(int j=0; j < getNumPlayers(); j++)
	{
		for(int i=0; i < (6-getNumPlayers()); i++)					// inefficiency ignored for the moment
		{
			players[j].addCard(playerDeck.takeCard());		//draw a card
		}
	}
}


void Model::initialInfect()
{
	ICard* iCardP;
	City* cityP;
	//Infect nine cities:
	//  3x3, then 3x2, then 3x1
	//	
	for(int i = 3; i>0; i--)//for changing cube counts each passr
	{
		int color;
		string s;
								
		for(int j=0; j<3; j++){
		
			iCardP = infectedDeck.takeCard();									//get a card
			s = iCardP->getName();												//store its name
			color = iCardP->getColor();											//store enumerated color
			cityP = worldMap.locateCity(s);										//get a pointer to the city based on its name

			infectCity(cityP, color, i);										//infect the city 
			
		}
	}   
}


void Model::infectCity(City* cityP, int color, int count)
{
	if (color == red){
				cityP->setInfectedRed(cityP->getInfectedRed() + (count));					//For the appropriate color increase their cubes, remove them from the
				removeCubes(red,(count));												//stock of available cubes.  Would be more straightforward if setInfected... was addInfected
			}
			else if (color == yellow){
				cityP->setInfectedYellow(cityP->getInfectedYellow() + (count));
				removeCubes(yellow,(count));
			}
			else if (color == blue){
				cityP->setInfectedBlue(cityP->getInfectedBlue() + (count));
				removeCubes(blue,(count));
			}
			else if (color == black){
				cityP->setInfectedBlack(cityP->getInfectedBlack() + (count));
				removeCubes(black,(count));
			}
}