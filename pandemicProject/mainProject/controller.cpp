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
        string tempStr = "";
        while (tempStr == "") {
            view.printNamePrompt(i);						// view prints prompt
            cin.clear();									//clear input buffer
            cin.sync();										//was being weird, but this fixed it
            getline(cin, tempStr, '\n');					//read player name
            if (tempStr == "") {
                view.printEmptyPlayerNameMessage();
            }
        }
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
                    
                    case 2: case 3: case 4: case 5: case 6: case 7: case 8:
                        //Filler for other actions until we put them there.
                        cout << "This option is not available right now and is still under development.\n\n";
                        j--;
                        break;
                        
                    case 9:
                        view.printInfectedCities(model.worldMap.infectedList());//print inf cities list
                        view.printCubeCount(model.getCubeCount(red), model.getCubeCount(yellow), model.getCubeCount(blue), model.getCubeCount(black)); //holy crap
                        j--;													//don't consume a move
                        break;
                    
					case 10:
						getSaveGame();
						j--;
						break;

					case 11:
                        cout << "Quitting game...";
						exit(0);

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

int Controller::run()
{
	bool test = false;
	
	try
	{
		view.printTitle();					//print title screen
		test = getLoadGame();				// ask to load game
		if(!test)							// skips load scenario if game loaded
			test = getLoadScenario();		// ask to load scenario
		if(!test) {							// skips game setup if loading game or scenario
			model.buildMap();				//builds map
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
	catch(PandemicException const& e)
	{
		int x = -1;
		cerr << "\nException caught: " << e.what() << "\n" << endl;		//quit condition or error occured

		while ( x < 0 || x > 1)
		{
			view.playAgain();												//prompt for new game
			cin >> x;
			cin.clear();
			cin.sync();
		}
		return x;											
	}
}

bool Controller::getLoadGame() {
	char input = 'A';
	while(1) {
		view.askLoadGame();
		cin >> input;
		cin.ignore();
		if(input == 'Y' || input == 'y') {
			//return true;
			return false;		// just until working
		}
		if(input == 'N' || input == 'n')
			return false;
	}
	return false;
}

bool Controller::getLoadScenario() {
	char input = 'A';
	while(1) {
		view.askLoadScenario();
		cin >> input;
		cin.ignore();
		if(input == 'Y' || input == 'y') {
			//return true;
			return false;		// just until working
		}
		if(input == 'N' || input == 'n')
			return false;
	}
	return false;
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
