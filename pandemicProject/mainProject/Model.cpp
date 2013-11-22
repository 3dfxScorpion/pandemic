#include <vector>
#include "Model.h"



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

	
 
}

// currentRate six indexes seventh and highest infection rate
// method increments if not already at six
void Model::incrementCurrentRate()
{
	if(currentRate < 6)//six is max
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
	srand((unsigned int)time(NULL));					//getting seedy
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
	//	Deal cards: 2 players-4 cards, 3players-3 cards, 4 players-2 cards
	cityP = worldMap.locateCity("Atlanta");		//find atlanta
	cityP->setResearchStation(true);			//set the station
	incResSta();								//increment ressta count
	for (int i = 0; i < getNumPlayers(); i++)	//for all players
	{
		players[i]->setPlayerRole(drawRole());			// assign a random role
		players[i]->setPlayerLocation(cityP);			//set all player locations to Atlanta
	}

	//draw inital hand:
	// players initially draw (6-numPlayers) cards
	for(int j=0; j < getNumPlayers(); j++)
	{
		for(int i=0; i < (6-getNumPlayers()); i++)					// inefficiency ignored for the moment
		{
			players[j]->addCard(playerDeck.takeCard());		//draw a card
		}
	}
}

void Model::initialInfect()
{
	//Infect nine cities:
	//  3x3, then 3x2, then 3x1
	//	
	for(int i = 3; i>0; i--)//for changing cube counts each passr
	{
		int color;
			
		for(int j=0; j<3; j++){
			ICard* iCardP;
			City* cityP;
			string s;
			iCardP = infectedDeck.takeCard();									//get a card
			s = iCardP->getName();												//store its name
			color = iCardP->getColor();											//store enumerated color
			cityP = worldMap.locateCity(s);										//get a pointer to the city based on its name
			if(cityP == NULL)
				cout << "Houston, we've had a problem.\nFailure in Model::initialInfect()\n";
			infectCity(cityP, color, i);										//infect the city 
			
		}
	}   
}


//TO DO: add outbreak checking for this method
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
    for (int i = 0; i < int(toCheck.size()); i++)
        for (int k = 0; k < getNumPlayers(); k++)
            if (players[k]->getPlayerRole() == "Quarantine Specialist" &&  //If the player is QS
                (players[k]->getPlayerLocation()->getCityName() == toCheck[i] || //and player is in an adj city
                 players[k]->getPlayerLocation()->getCityName() == icardP->getName()))// or player is on the city
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
            {
                addCubes(blue, toTreat->getInfectedBlue());//adds the amount of cubes being removed
                toTreat->setInfectedBlue(0);            //clears the city of infection
            }
            else
            {
                toTreat->setInfectedBlue(toTreat->getInfectedBlue()-1);//decrement amount of cubes by one
                addCubes(blue, 1);//add one cube back to the board.
            }
            break;
        case black:                                                     //same as blue except black
            if (mover.getCurrentPlayer()->getPlayerRole() == "Medic" ||
                status == cured )
            {
                addCubes(black, toTreat->getInfectedBlack());
                toTreat->setInfectedBlack(0);
            }
            else
            {
                toTreat->setInfectedBlack(toTreat->getInfectedBlack()-1);
                addCubes(black,1);
            }
            break;
        case yellow:                                                    //same as blue except yellow
            if (mover.getCurrentPlayer()->getPlayerRole() == "Medic" ||
                status == cured )
            {
                addCubes(yellow,toTreat->getInfectedYellow());
                toTreat->setInfectedYellow(0);
            }
            else
            {
                toTreat->setInfectedYellow(toTreat->getInfectedYellow()-1);
                addCubes(yellow,1);
            }
            break;
        case red:                                                       //same as blue except red
            if (mover.getCurrentPlayer()->getPlayerRole() == "Medic" ||
                status == cured )
            {
                addCubes(red, toTreat->getInfectedRed());
                toTreat->setInfectedRed(0);
            }
            else
            {
                toTreat->setInfectedRed(toTreat->getInfectedRed()-1);
                addCubes(red,1);
            }
    }
    if (cubes[col]==24)     //if there are no more cubes on the board then cure disease
        eradicateDisease(col);
}

void Model::savegame(string filename) {
	ofstream fp_out(filename, ios::out);				// open/create savegame file with name(filename)
	
	if(fp_out.is_open()) {								// test if file is open
		fp_out << "***** Game Difficulty *****" << endl;
														// save game difficulty
		fp_out << "***** Cube Counts *****" << endl;
														// save cube counts
		fp_out << "***** Outbreak & Infection Levels *****" << endl;
														// save outbreak and infection levels
		fp_out << "***** Players *****" << endl;
		for(int i = 0; i < getNumPlayers(); i++) {		// save players
			fp_out	<< players[i]->getPlayerName()	<< ","
					<< players[i]->getPlayerRole()	<< ","
					<< players[i]->getPlayerLocStr() << endl;
			vector<Card*> playerHand = players[i]->getHand();
			for(int j = 0; j < int(playerHand.size()); j++) {
				fp_out	<< playerHand[j]->getCardName()
						<< "," << playerHand[j]->getID()
						<< endl;
			}
			fp_out << endl;
		}
		fp_out << "***** Infection & Discard Decks *****" << endl;
		infectedDeck.saveGame(fp_out);					// save infection deck & discard deck
		fp_out << "***** City Deck *****" << endl;
		playerDeck.saveGame(fp_out);					// save city deck
		fp_out << "***** Map *****" << endl;
		worldMap.saveGame(fp_out);						// save map to file
		fp_out.close();									// close file
	}
	else
		cout << "Error opening file." << endl;
}

void Model::loadgame(string filename) {
	ifstream fp_in(filename, ios::in);
	
	if(fp_in.is_open()) {
		worldMap.loadGame(fp_in);
		fp_in.close();
	}
	else
		cout << "Error opening file." << endl;
}

vector<string> Model::getReasearchStationCities(){
    vector<string> ret;
    vector<City*> cities = worldMap.getWorldMap();
    vector<City*>::iterator cItr;
    for (cItr = cities.begin(); cItr != cities.end(); cItr++){ //gets a list of research stations
        City * tmp = *cItr;
        if (tmp->getResearchStationBool())
            ret.push_back(tmp->getCityName());
    }
    return ret;
}

bool Model::canBuildResearchStation(){
    Player * curr = mover.getCurrentPlayer();
    vector<Card*> hand = curr->getHand();
    vector<Card*>::iterator hItr;
    for ( hItr = hand.begin(); hItr != hand.end(); hItr++ ) {
        Card* tmp = *hItr;
        if (tmp->getCardName()==curr->getPlayerLocation()->getCityName() && !curr->getPlayerLocation()->getResearchStationBool())
            return true;// If the player has a card that matches the city they are in they can build.
    }
    return false;
    
}

void Model::buildResearchStation(){
    Player * curr = mover.getCurrentPlayer();
    int index = 0;
    vector<Card*> hand = curr->getHand();
    vector<Card*>::iterator hItr;
    for ( hItr = hand.begin(); hItr != hand.end(); hItr++ ) {
        Card* tmp = *hItr;
        if (tmp->getCardName()==curr->getPlayerLocation()->getCityName())
        {
            
            curr->getPlayerLocation()->setResearchStation(true);//builds the RS
            curr->removeCard(index);//remove card
            
        }
        index++;
    }

}

bool Model::canCureDisease(int col){//This will be updated later when we have a bit more user input.
   
   string color = colorToString(col);
    int colorNum=0;
    CityCard * cityCaster;
    if (!mover.getCurrentPlayer()->getPlayerLocation()->getResearchStationBool()) //if player isnt on research station
        return false;
    for (int i = 0; i <= mover.getCurrentPlayer()->getHandSize()-1;i++){
        cityCaster=(CityCard*)mover.getCurrentPlayer()->getHand()[i];   
        if (color == cityCaster->getColor())                 //wtb instanceof
        {
            colorNum++;
        }
        if (colorNum>=5){
            cureDisease(col);
            return true;
        }
    }
    return false;
}


void Model::doCureDisease(int col){
    
    string color = colorToString(col);
    int colorNum=0;                        //We will need to ask which 5 cards a player wants to discard
    vector<int> toRemove;                   //if they have more than 5 cards of the same color.
    CityCard * cityCaster;
    if (!mover.getCurrentPlayer()->getPlayerLocation()->getResearchStationBool()) //if player isnt on research station
        return;
    for (int i = 0; i <= mover.getCurrentPlayer()->getHandSize()-1;i++){
        cityCaster=(CityCard*)mover.getCurrentPlayer()->getHand()[i];
        if (color == cityCaster->getColor())                 //wtb instanceof
        {
            toRemove.push_back(i);
            colorNum++;
        }
        if (colorNum>=5){
            cureDisease(col);
            for (int k =0;k<=int(toRemove.size()-1);k++)
                mover.getCurrentPlayer()->removeCard(toRemove[k]);//discard the 5 city cards.
        }
    }
}

string Model::colorToString(int col){//Just to make life easier
    string color;
switch (col)
{
    case red:
        color = "red";
        break;
    case blue:
        color = "blue";
        break;
    case yellow:
        color = "yellow";
        break;
    case black:
        color = "black";
        break;
    default:
        cout << "error in model::cureDisease\n";
        }
    return color;
}


//Does an outbreak
//Function uses a reference to a vector to store the list of cities outbreaks occurred in during gameplay - controller uses this to pass to view
void Model::doOutbreak(City* Cptr, int color, vector<string>&prevOB)
{
	int size, tmp;
	City* currentAdj;
	string cities;
	vector<string> adjCities;											//stores vector of adjacent cities

	if(!alreadyOutbreak(Cptr->getCityName(), prevOB))					//do if city hasnt already had outbreak this round
	{
		incrementOutbreak();											//increment count of outbreaks
		prevOB.push_back(Cptr->getCityName());							//add current city to list of cities that had an outbreak this round
		adjCities = Cptr->getAdjCity();									//get vector of adjacent city names
		size = adjCities.size();										//store the size of the vector
		
		for(int i=0; i<size; i++)										//for each adjacent city in the list
		{
			currentAdj = worldMap.locateCity(adjCities[i]);				//save pointer to current adjacent city
			
			if(color == black)												//store the current count of cubes for specified color in tmp
				tmp = currentAdj->getInfectedBlack();						//similar if else block used in controller
			else if(color==blue)											//prime candidate for refactoring if time permits
				tmp = currentAdj->getInfectedBlue();						//better way would be to remove this completely
			else if(color ==red)											//and have the city method take the desired color as a parameter
				tmp = currentAdj->getInfectedRed();							//---may do that later - D GOOSE
			else
				tmp = currentAdj->getInfectedYellow();


			if(tmp<3)														//if infecting the city doesnt cause an outbreak
			{
				infectCity(currentAdj, color, 1);							//infect this city with a single cube of the specified color
			}
			else                                                            //otherwise a C-C-COMBO OUTBREAK OCCURS
			{
				doOutbreak(currentAdj, color, prevOB);						//C-C-C-COMBO
			}
		}

	}
	return;
}


//checks vector of city names to see if its there
bool Model::alreadyOutbreak(string current, vector<string> previous)
{
	bool tmp = false;
	int size = previous.size();

	if(!previous.empty())					//if vector isnt empty
	{
		for(int i = 0; i<size; i++){       
			if(current == previous[i]){     //tmp = true if this city name is in the vector
				tmp = true;
			}				
		}
	}
	
	return tmp;
}