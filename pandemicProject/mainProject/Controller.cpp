//
// Implements Controller.h
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

//Prompts for input, reads input, error checks input
void Controller::setPlayerCount() {
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
    
    model.setNumPlayers(temp);//set player count in model
    for ( size_t i = 0; i < temp; i++ ) {
        model.players.push_back(new Player());
    }
    return;
}

//prompts for names, reads them
void Controller::setPlayerNames() {
// Read in player names
    for(int i = 0; i < model.getNumPlayers(); i++) { //controller controls the flow
        string tempStr = "";
        while (tempStr == "") {
            view.printNamePrompt(i);// view prints prompt
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

//prompts for difficulty, reads it, sets it
void Controller::setDifficulty() {
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
    model.setDifficulty(temp);//set difficulty in model
}

void Controller::doPlayerTurns() {
    for (int i=0; i<model.getNumPlayers(); i++)//each players turn
    {
        Player * currentPlayer = model.players[i];
        model.mover.setCurrentPlayer(currentPlayer);
        
        for(int j = 0; j<4; j++) {
            
            int option = -1;
            
            doProcessMenu(currentPlayer);
/*
            while (option < 0 || option > 2) {
                view.displayPlayerInfo(model.players[i]->getPlayerName(), model.players[i]->getPlayerRole(), model.players[i]->getPlayerLocStr());
                view.printMenu();
                cin >> option;
                cin.ignore();
                string cityInput;
                
                switch (option) {
                    case 1:
                        cityP = model.worldMap.locateCity(model.players[i]->getPlayerLocStr());
                        view.printAdj(cityP->getAdjCity());
                        getline(cin,cityInput,'\n');
                        
                        model.mover.moveAdjacent(model.worldMap.locateCity(cityInput));
                        model.checkMedicSpecial();//Handles medic AutoTreatment ability.
                        break;
                    
                    case 2: case 3: case 4: case 5: case 6: case 7: case 8:
                        //Filler for other actions until we put them there.
                        cout << "This option is not available right now and is still under development.\n\n";
                        j--;
                        break;
                        
                    case 9:
                        view.printInfectedCities(model.worldMap.infectedList());//print inf cities list
                        view.printCubeCount(model.getCubeCount(red), model.getCubeCount(yellow), model.getCubeCount(blue), model.getCubeCount(black)); //holy crap
                        j--;//don't consume a move
                        break;
                    
                    case 10:
                        getSaveGame();
                        j--;
                        break;
                    case 11:
                        char quittingAnswer;
                        cout << "Are you sure you want to quit? (Y/N): ";
                        cin >> quittingAnswer;
                        cin.ignore();
                        if (quittingAnswer == 'Y' || quittingAnswer == 'y') {
                            char saveAnswer;
                            cout << "\nWould you like to save your progress? (Y/N): ";
                            cin >> saveAnswer;
                            cin.ignore();
                            
                            if (saveAnswer == 'Y' || saveAnswer == 'y') {
                                getSaveGame();
                            }
                        } else if (quittingAnswer == 'N' || quittingAnswer == 'n') {
                            cout << "Resuming game...\n\n";
                            j--;
                            break;
                        }
                        cout << "Quitting game...";
                        exit(0);

                    default:
                        view.printBadTurnChoice();
                        
                }
            }
*/
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
        cout << "Invalid input.  Try again: ";
    }
    cin.ignore(numeric_limits<size_t>::max(), '\n');
    if ( choice < getMappedFunctions().size() )
        (this->*getMappedFunctions()[choice])();
    if  (choice == 10 ) {
        cout << "\nGoodbye...\n"; exit(0);
    }
    system("pause");  // this will go away
}

void Controller::doInfectRound() {
    for(int i=0; i<2; i++){
        //infect cities
        iCardP = model.infectedDeck.takeCard();//draw a card
        
        view.printInfConfirmation(iCardP->getName());//print confirmation of it
        if (!model.QSautoContain(iCardP))
            model.infectCity(model.worldMap.locateCity(iCardP->getName()),iCardP->getColor(), 1);//infect the city
    }
}

int Controller::run() {
    bool test = false;

    try {
        view.printTitle();//print title screen
        test = getLoadGame();// ask to load game
        if(!test)// skips load scenario if game loaded
            test = getLoadScenario();// ask to load scenario
        if(!test) {// skips game setup if loading game or scenario
            model.buildMap();//builds map
            setPlayerCount();//read and set count of players
            setPlayerNames();//read and set player names
            setDifficulty();//read and set difficulty
            model.prepareGame();//assigns roles, draws initial player hands based on player count, sets resSta and player location to atlanta
            model.initialInfect();//perform the initial infection of nine cities
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
    }
    catch(PandemicException const& e) {
        int x = -1;
        cerr << "\nException caught: " << e.what() << "\n" << endl;//quit condition or error occured

        while ( x < 0 || x > 1) {
            view.playAgain();//prompt for new game
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
            return false;// just until working
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
            return false;// just until working
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
    getline(cin, name);// get savegame name from user

    if(!name.empty()) {
        filename = name;
    }

    model.savegame(filename);
    cout << "\nYour progress has been saved.\n";
    cout << endl;
}

// these functions are accessible snce function pointer passed into Menu Class
void Controller::do_drive_ferry() {
    Player * p = model.mover.getCurrentPlayer();
    int input, vSize;
    vector<string> adjs = p->getPlayerLocation()->getAdjCity();
    vSize = adjs.size();
    view.printAdjCities(p->getPlayerLocation());
    while (input < 1 || input > vSize)
    {
        cin >> input;
    }
    if (input == 10)
        return;
    model.mover.moveAdjacent(model.worldMap.locateCity(adjs[input-1]));// minus one to get synced with menu.
}

void Controller::do_direct_flight() {
    Player * p = model.mover.getCurrentPlayer();
    size_t num = 0, pick;
    vector<Card*> hand = p->getHand();
    for ( size_t i = 0; i < hand.size(); i++ )
        cout << hand[i]->ToString() << "\n";
    cout << "Where to (\"10\" to return to main menu) ? ";
    cin >> pick;
    if ( pick == 10 )
        return;

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

void Controller::do_charter_flight() {
    Player * p = model.mover.getCurrentPlayer();
    cout << "charter flight to city...\n";
    cout << menuAdjCities(p->getPlayerLocation()) << "\n";
}

void Controller::do_shuttle_flight() {
    Player * p = model.mover.getCurrentPlayer();
    view.askLocationShuttleFlight();
    vector <string> RScities = model.getReasearchStationCities();
    view.printReasearchStations(RScities);
    int input = 0;
    cin >> input;
    if ( input == 10 )
        return;
    cin.ignore();
    City* toMove = model.worldMap.locateCity(RScities[input-1]);
    model.mover.shuttleFlight(toMove);
}

void Controller::do_treat_disease() {
    cout << "treat disease...\n";
}

void Controller::do_cure_disease() {
    
}

void Controller::do_share_knowledge() {
    cout << "share knowledge, are you crazy???\n";
}

void Controller::do_build_station() {
    if (!model.canBuildResearchStation())
        view.printCantBuildRS();
    else
        model.buildResearchStation();
}

void Controller::do_save_game() {
    cout << "save game...\n";
}


