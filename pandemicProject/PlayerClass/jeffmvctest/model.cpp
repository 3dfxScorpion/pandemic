#include "model.h"
#include "controller.cpp"


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



void model::CPgetEventCard(Deck* discard){
    
    viewer.opExpertEventPrompt(discard->getDeck()); //Calls view for output
    int c = getInt();                               //Calls controller for input
    mover.getCurrentPlayer()->addCard(discard->getDeck()[c]); //updates current players hand
    /*      Contingency Planer Role ability
     * I think we talked about using a deck object
     * for the discard pile. If that is the case
     * we can just pass it, search it, and pick it
     * we also have to remove the card form the game
     */
    return;
}

void model::DmovePlayerToPlayerCity(Player* toMove){
    
    viewer.otherPlayerAction(mover.getCurrentPlayer()->getPlayerName(),
                             toMove->getPlayerName());//Updates view with prompt
    /*      Dispatcher Role Ability
     * Takes the player dispatcher wants to move as param
     * Asks the other player if it is OK to move
     * sets that players location to the new city
     *
     */
    
    return;
}

void model::DmovePlayerAsYourself(Player* toMove){
    
    /*      Dispatcher Role Ability
     * Takes the player dispatcher wants to move as param
     * Asks the other player if it is OK to move
     * I think to impliment we either set the
     * requested player as the current player,
     * or make a new PlayerMove object and then
     * set the player as current player.
     * We will have to see how this effects the UI
     * and other aspects that use the current player
     * pointer
     */
    return;
}

void model::MtreatDisease(string color){
    
    /*      Medic Role Ability
     * Takes the color as a param even though
     * I am pretty sure there can only be one type of
     * disease cube per city. The actual action is simple
     * just clear all of the cubes instead of 1
     */
    
}

void model::MautoCure(){
    
    /*      Medic Role Ability
     * No parameters, conditions likely checked elsewhere.
     * This will simply remove all cubes of a cured
     * disease when a medic enters the city
     *
     */
    
}
void model::OEbuildResearchStation(Player* p){
    
    /*      Operations Expert Ability
     * Simply build an RS at the players current
     * location.
     */
    
}

void model::OEmove(City*){
    /*      Operations Expert Ability
     * This will take the city the OE wants to move
     * to as a param. Will prompt to pick a card to
     * discard.
     *
     */
    
}
bool model::QSautoContain(){
    
    /*      Quarantine Specialist Ability
     * Like the medic's Auto cure, the conditions for
     * this action (if the game attempts to add a disease)
     * will be checked elsewhere. This function will simply
     * return true if the QS is on or adjacent to the city
     * that the game trys to add a cube on to.
     */
    return false;
}
void model::RgiveCityCard(Player*){
    
    /*      Researcher Ability
     * This action can be done on anyone's turn
     * It is similar to share knowledge but without
     * needing the card to match. The recieving player will
     * be the parameter.
     */
}
void model::Scure(string){
    
    /*      scientist Ability
     * This one is pretty straight forward.
     * It is basically the cure disease function but
     * with a 4 card condition instead of 5
     */
}







