//
// Implements Controller.h
#include "Controller.h"


//Contructor -- prints title page as well (for laziness)
Controller::Controller()
{
	cityP = 0;
	iCardP = 0;
}

//Prompts for input, reads input, error checks input
void Controller::setPlayerCount()
{
	//get num players
	view.askNumOfPlayers();
	cin >> temp;
	cin.ignore();
    
	//if improper input, loop till proper
    while (temp < 2 || temp > 4) {
        if (cin.fail()) {
            view.printNonNumeric();//print quit error
			return;
        } else if (temp < 2 || temp > 4) {
            view.printBadPlayerCt();
			view.askNumOfPlayers();
			cin >> temp;
			cin.ignore();
        }
    }
    
	model.setNumPlayers(temp);							//set player count in model
    
	return;
}

//prompts for names, reads them
void Controller::setPlayerNames()
{
	// Read in player names
	for(int i = 0; i < model.getNumPlayers(); i++)		//controller controls the flow
	{
		view.printNamePrompt(i);						// view prints prompt
		cin.clear();									//clear input buffer
		cin.sync();										//was being weird, but this fixed it
		getline(cin, tempStr, '\n');					//read player name
		model.players[i].setPlayerName(tempStr);		//model stores data
	}
    
}

//prompts for difficulty, reads it, sets it
void Controller::setDifficulty()
{
	// while (difficulty < 1 || difficulty > 3) {
	for(int difficulty = 0; cin.fail() || difficulty < 1 || difficulty > 3; ) {
        //get difficulty
        view.printDiffPrompt();
        cin >> difficulty;
        cin.ignore();
      
		//error checking
        if (cin.fail()) {
            view.printNonNumeric();
            return;
        } else if (difficulty < 1 || difficulty > 3) {
            view.printBadDiff();
        }
        cin.clear();
        cin.sync();
    }
	model.setDifficulty(temp);			//set difficulty in model
}

void Controller::doPlayerTurns()
{
	for (int i=0; i<model.getNumPlayers(); i++)			//each players turn
    {
        Player * currentPlayer = &model.players[i];
        model.mover.setCurrentPlayer(currentPlayer);
        
        for(int j = 0; j<4; j++) {
            
            int option = -1;
            
            while (option < 0 || option > 2) {
                view.displayPlayerInfo(model.players[i].getPlayerName(), model.players[i].getPlayerRole(), model.players[i].getPlayerLocStr());
                view.printMenu();
                cin >> option;
                cin.ignore();
                string cityInput;
                
                switch (option) {
                    case 1:
                        cityP = model.worldMap.locateCity(model.players[i].getPlayerLocStr());
                        view.printAdj(cityP->getAdjCity());
                        getline(cin,cityInput,'\n');
                        
                        model.mover.moveAdjacent(model.worldMap.locateCity(cityInput));
                        model.checkMedicSpecial();	//Handles medic AutoTreatment ability.
                        break;
                        
                    case 2:
                        view.printInfectedCities(model.worldMap.infectedList());//print inf cities list
                        view.printCubeCount(model.getCubeCount(red), model.getCubeCount(yellow), model.getCubeCount(blue), model.getCubeCount(black)); //holy crap
                        j--;													//don't consume a move
                        break;
                    
					case 3:
						getSaveGame();
						j--;
						break;


                    default:
                        view.printBadTurnChoice();
                        
                }
            }
        } // four moves consumed
        
        doInfectRound();//perform the infection round
        
        
        //This will be removed when Derricks UI is up and running
        view.printInfectedCities(model.worldMap.infectedList());//print inf cities list after update
        view.printCubeCount(model.getCubeCount(red), model.getCubeCount(yellow), model.getCubeCount(blue), model.getCubeCount(black)); //holy crap
        
        
	}
}

void Controller::doInfectRound()
{
	for(int i=0; i<2; i++){
        //infect cities
        iCardP = model.infectedDeck.takeCard();//draw a card
        
        view.printInfConfirmation(iCardP->getName());//print confirmation of it
        if (!model.QSautoContain(iCardP))
        model.infectCity(model.worldMap.locateCity(iCardP->getName()),iCardP->getColor(), 1);//infect the city
	}
    
}

void Controller::run()
{
	bool test = false;

	view.printTitle();					//print title screen
	test = getLoadGame();				// ask to load game
	if(!test)							// skips load scenario if game loaded
		test = getLoadScenario();		// ask to load scenario
	if(!test) {							// skips game setup if loading game or scenario
		setPlayerCount();				//read and set count of players
		setPlayerNames();				//read and set player names
		setDifficulty();				//read and set difficulty
		model.prepareGame();			//assigns roles, draws initial player hands based on player count, sets resSta and player location to atlanta
		model.initialInfect();			//perform the initial infection of nine cities
	}
    
	while(true)							//play until quit condition reached
	{
		doPlayerTurns();
	}
}

bool Controller::getLoadGame() {
	char input = 'A';
	while(input != 'Y' || input != 'N') {
		view.askLoadGame();
		cin >> input;
		cin.ignore();
		if(input == 'Y') {
			//return true;
			return false;		// just until working
		}
		if(input == 'N')
			return false;
	}
}

bool Controller::getLoadScenario() {
	char input = 'A';
	while(input != 'Y' || input != 'N') {
		view.askLoadScenario();
		cin >> input;
		cin.ignore();
		if(input == 'Y') {
			//return true;
			return false;		// just until working
		}
		if(input == 'N')
			return false;
	}
}

void Controller::getSaveGame() {
	string filename = "autosave";
	string name;

	view.askFileName();
	getline(cin, name);		// get savegame name from user

	if(!name.empty()) {
		filename = name;
	}

	model.savegame(filename);
	cout << endl;
}
