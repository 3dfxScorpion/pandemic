#include "Controller.h"


// primary commands
string cmds01[] = {
    "Drive/Ferry",
    "Direct Flight",
    "Charter Flight",
    "Shuttle Flight",
    "Treat Disease",
    "Discover Cure",
    "Share Knowledge",
    "Build Research Station",
    "Save game"
};

// populate string vectors
vector<string> mainCommands ( cmds01, cmds01 + sizeof(cmds01) / sizeof(cmds01[0]) );
// vector<string> mainCommands ( cmds02, cmds02 + sizeof(cmds02) / sizeof(cmds02[0]) );

//Contructor -- prints title page as well (for laziness)
Controller::Controller() {
    cityP = 0;
    iCardP = 0;
    setMappedFunctions();
}

void Controller::setPlayerCount() {
    view.askNumOfPlayers();
    cin >> temp;
    cin.ignore();
    
    //if improper input, loop till proper
    while (temp < 2 || temp > 4) {
        if (cin.fail()) {
            view.printNonNumeric();
            return;
        } else if (temp < 2 || temp > 4) {
            view.printBadPlayerCt();
            view.askNumOfPlayers();
            cin >> temp;
            cin.ignore();
        }
    }
    
    model.setNumPlayers(temp);
    for ( size_t i = 0; i < temp; i++ ) {
        model.players.push_back(new Player());
    }
    return;
}

void Controller::setPlayerNames() {
    for(int i = 0; i < model.getNumPlayers(); i++) { //controller controls the flow
        string tempStr = "";
        while (tempStr == "") {
            view.printNamePrompt(i);
            cin.clear();//clear input buffer
            cin.sync();//was being weird, but this fixed it
            getline(cin, tempStr, '\n');//read player name
            if (tempStr == "") {
                view.printEmptyPlayerNameMessage();
            }
        }
        model.players[i]->setPlayerName(tempStr);//model stores data
    }
}

void Controller::setDifficulty() {
    // while (difficulty < 1 || difficulty > 3) {
    for(int difficulty = 0; cin.fail() || difficulty < 1 || difficulty > 3; ) {
        //get difficulty
        view.printDiffPrompt();
        cin >> difficulty;
        cin.ignore();
        
        if (cin.fail()) {
            view.printNonNumeric();
            return;
        } else if (difficulty < 1 || difficulty > 3) {
            view.printBadDiff();
        }
        
        cin.clear();
        cin.sync();
    }
    model.setDifficulty(temp);
}

void Controller::doPlayerTurns() {
    for (int i=0; i<model.getNumPlayers(); i++) { //each players turn
        Player * currentPlayer = model.players[i];
        model.mover.setCurrentPlayer(currentPlayer);
        
        for(int j = 0; j<4; j++) {
            
            //int option = -1;
            
            doProcessMenu(currentPlayer);
            
        } // four moves consumed
        
        doInfectRound();//perform the infection round
        
        menu.setMappedCubes("black", model.getCubeCount(black));
        menu.setMappedCubes("blue", model.getCubeCount(blue));
        menu.setMappedCubes("red", model.getCubeCount(red));
        menu.setMappedCubes("yellow", model.getCubeCount(yellow));
        
        
    }
}

void Controller::doProcessMenu(Player* p) {
    const size_t NUM_COMMANDS = menu.getMenuCommands().size();
    size_t choice = NUM_COMMANDS - 1;
    
    menu.showMenu(p);
    while( !( cin >> choice ) ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        view.printInvalidInputMsg();
    }
    cin.ignore(numeric_limits<size_t>::max(), '\n');
    
    if (choice < getMappedFunctions().size()) {
        (this->*getMappedFunctions()[choice])();
    }
    
    if (choice == 10) {
        view.printGoodbye();
        exit(0);
    }
    system("pause");  // this will go away
}

void Controller::doInfectRound() {
	int infCount = model.getInfRate();
	vector<string> outbreakCities;											//just in case of outbreaks
    for (int i = 0; i < infCount; i++) {
        iCardP = model.infectedDeck.takeCard();
        
        view.printInfConfirmation(iCardP->getName());
        
        if (!model.QSautoContain(iCardP)) 
		{
			City* ptr = model.worldMap.locateCity(iCardP->getName());		//store city
			int color = iCardP->getColor();									//store color
			int tmp;

			if(color == black)												//store the current count of cubes for specified color in tmp
				tmp = ptr->getInfectedBlack();								//similar if else block used in model
			else if(color==blue)											//prime candidate for refactoring if time permits
				tmp = ptr->getInfectedBlue();								//better way would be to remove this completely
			else if(color ==red)											//and have the city method take the desired color as a parameter
				tmp = ptr->getInfectedRed();								//---may do that later - D GOOSE
			else
				tmp = ptr->getInfectedYellow();

			if(tmp < 3)														//if this wont cause an outbreak
			{
				model.infectCity(ptr,color, 1);								//infect the city
			}
			else
			{
				model.doOutbreak(ptr, color, outbreakCities);				//otherwise outbreak
				view.printOutbreaks(outbreakCities);						//and display the list of cities that had them
			}

		}
       
   }
}

//performs necessary model/view calls to do an epidemic
void Controller::doEpidemic()
{
	int tmp, clr;
	vector<string> outbreakCities;
	iCardP = model.infectedDeck.takeBottomCard();		//draw bottom card
	clr = iCardP->getColor();							//store its color
	cityP = model.worldMap.locateCity(iCardP->getName());//get pointer to the city


	if(clr == black)									//store the current count of cubes for specified color
		tmp = cityP->getInfectedBlack();
	else if(clr==blue)
		tmp = cityP->getInfectedBlue();
	else if(clr ==red)
		tmp = cityP->getInfectedRed();
	else
		tmp = cityP->getInfectedYellow();


	if(tmp == 0){
		model.infectCity(cityP, clr, 3);				//if uninfected by the disease add three cubes
	}
	else
	{
														//otherwise outbreak HOLY SHIT	
		tmp = 3 - tmp;									//number to add is 3-current to top it off to 3
		model.infectCity(cityP, clr, tmp);				//top the infection cubes up to 3
		model.doOutbreak(cityP, clr, outbreakCities);	//play the outbreak
		view.printOutbreaks(outbreakCities);			//display the information
	}

	model.infectedDeck.shuffleDiscard();				//shuffle the discard to the top of iDeck	

	return;
}


int Controller::run() {
    bool test = false;
    
    try {
        view.printTitle();
	test = getLoadGame();
        
        if(!test) {    // skips load scenario if game loaded
            test = getLoadScenario();   // ask to load scenario
        }
        
        if(!test) {    // skips game setup if loading game or scenario
            model.buildMap();
            setPlayerCount();
            setPlayerNames();
            setDifficulty();
            model.prepareGame();    //assigns roles, draws initial player hands based on player count, sets resSta and player location to atlanta
            model.initialInfect();	//perform initial infection
        }
        
        menu.setMenuMap(model.worldMap);
        menu.setMenuPlayers(model.players);
        menu.setMenuCommands(mainCommands);
        menu.setMappedCommands(mainCommands);
        menu.setMappedCubes("black", model.getCubeCount(black));
        menu.setMappedCubes("blue", model.getCubeCount(blue));
        menu.setMappedCubes("red", model.getCubeCount(red));
        menu.setMappedCubes("yellow", model.getCubeCount(yellow));
        
        while(true) {  //play until quit condition reached
            doPlayerTurns();
        }
    }//end try
    catch(PandemicException const& e) {
        int x = -1;
        cerr << "\nGame Over! " << e.what() << "\n\n";   //quit condition or error occured
        
        while ( x < 0 || x > 1) {
            view.playAgain();   //prompt for new game
            cin >> x;
            cin.clear();
            cin.sync();
        }
        return x;
    }
}

bool Controller::getLoadGame() {
    char input = 'A';
    while(true) {
        view.askLoadGame();
        cin >> input;
        cin.ignore();
        
        if (input == 'Y' || input == 'y') {
            //return true;
            return false;// just until working
        }
        
        if (input == 'N' || input == 'n') {
            return false;
        }
    }
    return false;
}

bool Controller::getLoadScenario() {
    char input = 'A';
    while(true) {
        view.askLoadScenario();
        cin >> input;
        cin.ignore();
        
        if (input == 'Y' || input == 'y') {
            //return true;
            return false;// just until working
        }
        
        if (input == 'N' || input == 'n') {
            return false;
        }
    }
    return false;
}

void Controller::getSaveGame() {
    string filename = "autosave";
    string name;
    
    view.askFileName();
    getline(cin, name);    // get savegame name from user
    
    if (!name.empty()) {
        filename = name;
    }
    
    model.savegame(filename);
    view.printProgressSavedMsg();
}

// these functions are accessible since function pointer passed into Menu Class
void Controller::do_drive_ferry() {
    Player * p = model.mover.getCurrentPlayer();
    int input = -1; 
	int vSize;
    vector<string> adjs = p->getPlayerLocation()->getAdjCity();
    vSize = adjs.size();
    view.printAdjCities(p->getPlayerLocation());
    while (input < 1 || input > vSize) //loop until proper input
    {
        cin >> input;
        cin.clear();
        cin.ignore();
        if (input == 10) {
            return;
        }
    }
    model.mover.moveAdjacent(model.worldMap.locateCity(adjs[input-1]));    // minus one to get synced with menu.
}

void Controller::do_direct_flight() {   //If it aint broke
    Player * p = model.mover.getCurrentPlayer();
    size_t num = 0, pick;
    vector<Card*> hand = p->getHand();
    
    for ( size_t i = 0; i < hand.size(); i++ ) {
        cout << hand[i]->ToString() << "\n";
    }
    
    view.askWhereTo();
    cin >> pick;
    
    if ( pick == 10 ) {
        return;
    }
    
    vector<Card*>::iterator hItr;
    for ( hItr = hand.begin(); hItr != hand.end(); hItr++ ) {
        Card* tmp = *hItr;
        if ( pick == tmp->getID() ) {
            string s = tmp->getCardName();
            cout << num << " - Flying to " << s << "\n";
            cityP = model.worldMap.locateCity(s);
            p->setPlayerLocation(cityP);
            p->removeCard(num);
        }
        ++num;
    }
}

void Controller::do_charter_flight() {    //Need a menu to list all cities or let character enter input :S
    Player * p = model.mover.getCurrentPlayer();
    view.printCharterFlightMsg();
    cout << menuAdjCities(p->getPlayerLocation()) << "\n";
}

void Controller::do_shuttle_flight() {
    view.askLocationShuttleFlight();
    vector <string> RScities = model.getReasearchStationCities();   //Get all cities with RSs
    int vSize = RScities.size();
    view.printReasearchStations(RScities);
    int input = 0;
    while (input < 1 || input > vSize)  //Get user input, loop till good input
    {
        cin >> input;
        cin.clear();
        cin.ignore();
        if ( input == 10 ) {
            return;
        }
    }
    cin.ignore();
    City* toMove = model.worldMap.locateCity(RScities[input-1]);
    model.mover.shuttleFlight(toMove);
}

void Controller::do_treat_disease() {
    view.printTreatDiseaseMsg();
}

void Controller::do_cure_disease() {    //TODO needs a role check. Needs more testing!!!
    char input = 'x';
    
    for (int i = red; i <=black;i++) {    //loops and checks if they can cure
        if (model.canCureDisease(i)) {    //self checking since player can never have more than one cure available
            view.askCanCure(model.colorToString(i));
            
            while (input != 'Y'|| input !='y' || input !='n' || input != 'N') {
                cin >> input;    //loop for input
                cin.clear();
                cin.ignore();
            }
            
            if (input == 'Y' || input == 'y') {
                model.doCureDisease(i);
            } else {
                return;
            }
        }
    }
}

void Controller::do_share_knowledge() {
    view.printShareKnowledgeMsg();
}

void Controller::do_build_station() {
    if (!model.canBuildResearchStation()) {     //Check if possible
        view.printCantBuildRS();
    } else {
        model.buildResearchStation();
    }
}

void Controller::do_save_game() {
    view.printSaveGameMsg();
}


