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
	worldMap.populateMap("Cities.txt");				//populate the map
 
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

			//Check for out of cubes game over state
			if(cubes[color] < 0){
				throw PandemicException("A disease has spread too much! Game over!");
			}
}

bool Model::QSautoContain(ICard* icardP){
    vector<string> toCheck = worldMap.locateCity(icardP->getName())->getAdjCity();
    for (int i = 0; i < toCheck.size(); i++)
        for (int k = 0; k < getNumPlayers(); k++)
            if (players[k].getPlayerRole() == "Quarantine Specialist" &&  //If the player is QS
                (players[k].getPlayerLocation()->getCityName() == toCheck[i] || //and player is in an adj city
                 players[k].getPlayerLocation()->getCityName() == icardP->getName()))// or player is on the city
                return true;                            //return true so that city wont be infected.
    // end of both looops.
    
    return false;//otherwise return false so the city will be infected.
}

void Model::checkMedicSpecial(){
    Player* toCheck = mover.getCurrentPlayer();
    if (mover.getCurrentPlayer()->getPlayerRole() == "Medic")
    {
        if (getCureStatus(red) == cured &&
            toCheck->getPlayerLocation()->getInfectedRed() > 0)//If red is cured
            toCheck->getPlayerLocation()->setInfectedRed(0);//Auto treat red on move
        
        if (getCureStatus(red) == cured &&
            toCheck->getPlayerLocation()->getInfectedYellow() > 0)//if yellow...
            toCheck->getPlayerLocation()->setInfectedYellow(0);// the same...
        
        if (getCureStatus(red) == cured &&
            toCheck->getPlayerLocation()->getInfectedBlue() > 0)
            toCheck->getPlayerLocation()->setInfectedBlue(0);
        
        if (getCureStatus(red) == cured &&
            toCheck->getPlayerLocation()->getInfectedBlack() > 0)
            toCheck->getPlayerLocation()->setInfectedBlack(0);
    }
}

void Model::treatDisease(int col, int status){
    City* toTreat = mover.getCurrentPlayer()->getPlayerLocation();
    switch(col){
        case blue:
            if (mover.getCurrentPlayer()->getPlayerRole() == "Medic" ||
                status == cured ) //if medic or disease is cured, remove all cubes.
                toTreat->setInfectedBlue(0);
            else
                toTreat->setInfectedBlue(toTreat->getInfectedBlue()-1);//decrement by 1
            break;
        case black:
            if (mover.getCurrentPlayer()->getPlayerRole() == "Medic" ||
                status == cured )
                toTreat->setInfectedBlack(0);
            else
                toTreat->setInfectedBlack(toTreat->getInfectedBlack()-1);
            break;
        case yellow:
            if (mover.getCurrentPlayer()->getPlayerRole() == "Medic" ||
                status == cured )
                toTreat->setInfectedYellow(0);
            else
                toTreat->setInfectedYellow(toTreat->getInfectedYellow()-1);
            break;
        case red:
            if (mover.getCurrentPlayer()->getPlayerRole() == "Medic" ||
                status == cured )
                toTreat->setInfectedRed(0);
            else
                toTreat->setInfectedRed(toTreat->getInfectedRed()-1);
    }
}