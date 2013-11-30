#include "Controller.h"
#include "displayOptions.h"

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
	movesUsed = 0;
    setMappedFunctions();
}

void Controller::setPlayerCount() {
    view.askNumOfPlayers();
    cin >> temp;
    
    //if improper input, loop till proper
    while (temp < 2 || temp > 4) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256,'\n');
            view.printNonNumeric();
        } else if (temp < 2 || temp > 4) {
            view.printBadPlayerCt();
        }
        view.askNumOfPlayers();
        cin >> temp;
        cin.ignore();
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
            cin.clear();
            cin.ignore(256,'\n');
        } else if (difficulty < 1 || difficulty > 3) {
            view.printBadDiff();
        }
    }
    model.setDifficulty(temp);
}

void Controller::doPlayerTurns() {
    for (int i=0; i<model.getNumPlayers(); i++) { //each players turn
        Player * currentPlayer = model.players[i];
        model.mover.setCurrentPlayer(currentPlayer);
        

        for(this->resetMovesUsed(); this->getMovesUsed()<4; incMovesUsed()) {
            
            doProcessMenu(currentPlayer);
            
        } // four moves consumed
        
        view.newLine();
        doDrawRound(i);//perform the draw round
        view.newLine();
        doInfectRound();//perform the infection round
        system("Pause");
        
        menu.updateMenu(model);
    }
}

void Controller::doDrawRound(int current)
{
    Card* card1;
    Card* card2;
    vector<Card*> playerHand;
    string ep = "EPIDEMIC";										//to avoid retyping

	if(model.playerDeck.getSize() < 2)							// if there arent enough cards
	{
		throw PandemicException("You ran out of time! Player deck empty!");//quit
	}
	else
	{
		card1 = model.playerDeck.takeCard();						//draw two cards
		card2 = model.playerDeck.takeCard();
	}
    
    //card 1 behavior
    if(card1->getCardName() == ep)
    {
		if(card2->getCardName() == ep)							//double epidemic check
		{
			model.infectedDeck.removeFirstDrawn();				//first drawn card this round is removed from play
			doEpidemic();										//do the epidemic
			doubleEpidemic(current);							//perform special circumstances
		}
		else
		{
			doEpidemic();										//otherwise just do it
		}
    }
    else
    {
        view.printDrawConfirmation(card1->getCardName());    //print add confirm
        model.players[current]->addCard(card1);              //otherwise regular card, add it to players hand
        
    }//end card1 block
    
    
    //card two behavior
    if(card2->getCardName() == ep)
    {
        doEpidemic();                                    //if epidemic card drawn, do eet
    }
    else
    {
        view.printDrawConfirmation(card2->getCardName());    //print add confirm
        model.players[current]->addCard(card2);                //otherwise regular card, add it to players hand
    }//end card2 block
    

	while(model.players[current]->getHandSize() > 7)			//enforce hand limit after draw phase
	{
		doDiscard(model.players[current]->getHand(), current);
	}
    
}

//special behavior if two epidemics drawn at the same time
void Controller::doubleEpidemic(int current)
{
		vector<int> eventID;
        model.playerDeck.findEvents(model.players[current]->getHand(), eventID); //get vector of indexes containing the players  event cards
        
        if(!eventID.empty())//if player had some event cards
        {
            menu.doubleEpEventMenu(model.players[current]->getHand(), eventID);//display user choices
            
            int temp = -1;
            while (temp < 0  || temp >eventID.size())
            {
                cin >> temp;                                //read which index value to play from the hand
                cin.clear();
                cin.ignore();
            }
            
            //play the users event card
            //needs code to handle event cards. DO ME.
            //the desired card's index into the player hand is in eventID[temp]
            
        }
}

void Controller::doDiscard(vector<Card*>playerHand, int current)
{
    int x;
    menu.discardMenu(playerHand);                    //display the hand so user can choose
    
    do
    {
        cin >> x;                                    //read x - the card to be removed
        cin.clear();
        cin.sync();
    }while(0>x || x>= playerHand.size());            //while its not inside the range
    
    if(model.playerDeck.isEventCard(playerHand[x]))    //if event card is chosen
    {
        view.printPlayOrDiscard();                    //ask user to play the card or discard it
        
        int temp=-1;
        while(temp < 0 || temp > 1)
        {
            cin >> temp;
            cin.ignore();
            cin.sync();
        }
        
        if(temp == 0)
        {
            //code to play the event card goes here
            //DO ME BITCHES
			model.players[current]->removeCard(x);            //temporary until event cards are played and removed
        }
        else
        {
            model.players[current]->removeCard(x);            //otherwise remove the card from current player
        }
        
    }//end if event card
    else
    {
        model.players[current]->removeCard(x);                //otherwise it's a city card, discard
    }
    
    return;
}

void Controller::doProcessMenu(Player* p) {
    const size_t NUM_COMMANDS = menu.getMenuCommands().size();
    size_t choice = NUM_COMMANDS - 1;
    
    menu.showMenu(p);
    while( !( cin >> choice ) ) {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        view.printInvalidInputMsg();
    }
    cin.ignore((numeric_limits<size_t>::max)(), '\n');
    
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
    vector<string> outbreakCities;                                            //just in case of outbreaks
    for (int i = 0; i < infCount; i++) {
        iCardP = model.infectedDeck.takeCard();
        
        view.printInfConfirmation(iCardP->getName());
        
        if (!model.QSautoContain(iCardP))
        {
            City* ptr = model.worldMap.locateCity(iCardP->getName());        //store city
            int color = iCardP->getColor();                                    //store color
            int tmp;
            
            if(color == black)													//store the current count of cubes for specified color in tmp
                tmp = ptr->getInfectedBlack();									//similar if else block used in model
            else if(color==blue)												//prime candidate for refactoring if time permits
                tmp = ptr->getInfectedBlue();									//better way would be to remove this completely
            else if(color ==red)												//and have the city method take the desired color as a parameter
                tmp = ptr->getInfectedRed();									//---may do that later - D GOOSE
            else
                tmp = ptr->getInfectedYellow();
            
            if(tmp < 3)															//if this wont cause an outbreak
            {
                model.infectCity(ptr,color, 1);									//infect the city
            }
            else
            {
                model.doOutbreak(ptr, color, outbreakCities);                //otherwise outbreak
                view.printOutbreaks(outbreakCities);                        //and display the list of cities that had them
            }
            
        }
        
    }
	//system("pause");
}

//performs necessary model/view calls to do an epidemic
void Controller::doEpidemic()
{
    int tmp, clr;
    vector<string> outbreakCities;
    model.incrementCurrentRate();                        //increment the infection rate
    iCardP = model.infectedDeck.takeBottomCard();        //draw bottom card
    clr = iCardP->getColor();                            //store its color
    cityP = model.worldMap.locateCity(iCardP->getName());//get pointer to the city
    
    
    if(clr == black)                                    //store the current count of cubes for specified color
        tmp = cityP->getInfectedBlack();
    else if(clr==blue)
        tmp = cityP->getInfectedBlue();
    else if(clr ==red)
        tmp = cityP->getInfectedRed();
    else
        tmp = cityP->getInfectedYellow();
    
    
    if(tmp == 0){
        model.infectCity(cityP, clr, 3);                //if uninfected by the disease add three cubes
    }
    else
    {
        //otherwise outbreak HOLY SHIT
        tmp = 3 - tmp;                                    //number to add is 3-current to top it off to 3
        model.infectCity(cityP, clr, tmp);                //top the infection cubes up to 3
        model.doOutbreak(cityP, clr, outbreakCities);    //play the outbreak
        view.printOutbreaks(outbreakCities);            //display the information
    }
    
	model.infectedDeck.shuffleDiscard();                //shuffle the discard to the top of iDeck
    
    return;
}

int Controller::run() {
#ifdef _WIN32
    HANDLE wHnd;    // Handle to write to the console.
    
    // Set up the handles for reading/writing:
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // Change the window title:
    SetConsoleTitle(TEXT("Pandemic"));
    
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, 119, 49};
    
    // Change the console window size:
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    
    // Create a COORD to hold the buffer size:
    COORD bufferSize = {120, 50};
    
    // Change the internal buffer size:
    SetConsoleScreenBufferSize(wHnd, bufferSize);

    // Resize the console window
//    MoveWindow(GetConsoleWindow(), 0, 0, 1000, 700, TRUE);
#endif

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
            model.initialInfect();    //perform initial infection
        }
        
        menu.setMenuCommands(mainCommands);
        menu.setMappedCommands(mainCommands);
        menu.updateMenu(model);

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

// these functions are accessible since function pointer passed into Menu Class
void Controller::do_drive_ferry() {
    Player * p = model.mover.getCurrentPlayer();
    int input = -1;
    int vSize = -1;
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
        if(!model.playerDeck.isEventCard(hand[i]))
            cout << hand[i]->ToString() << "\n";        //don't display event cards in direct flight options - does nothing to prevent their use
    }
    
    vector<int> eventID;                                //indexes of event cards in hand
    model.playerDeck.findEvents(hand, eventID);            //find the indexes of event cards (this is so much easier with a  new data field in the cards, but w/e)
    
    while(true)
    {
        view.askWhereTo();
        cin >> pick;
        cin.ignore();
        cin.sync();
        
        if(isInVector(pick, eventID))
        {
            continue;
        }
        else
        {
            break;
        }
        
    }
    
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
    char choice = 'x';
    
    for (int i = red; i <=black;i++) {    //loops and checks which disease player wants to treat
        if (model.canTreatDisease(i)) {
            view.askCanTreat(model.colorToString(i));
            
            while (choice != 'Y' && choice !='y' && choice !='n' && choice != 'N') {
                cin >> choice;    //loop for input
            }
            
            if (choice == 'Y' || choice == 'y') {
                model.treatDisease(i);
				view.printTreatDiseaseMsg();
            }
        }
    }
}

void Controller::do_cure_disease() {    //TODO needs a role check. Needs more testing!!!
    char input = 'x';
    
    for (int i = red; i <=black;i++) {    //loops and checks if they can cure
        if (model.canCureDisease(i)) {    //self checking since player can never have more than one cure available
            view.askCanCure(model.colorToString(i));
            
            while (input != 'Y'&& input !='y' && input !='n' && input != 'N') {
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
    int input = -1;//Input for switch
    int pInput = -1;//Input for "which player do you want to give/get to/from"
    vector<string> giveOrGet;
    if (model.canGiveKnowledge())
    {
        vector<Player*> toGive = model.getSharablePlayers("give");
        view.askGiveKnowledge(toGive);
        while (pInput < 1 || pInput > toGive.size())
        {
            cin >> pInput;
            cin.ignore();
            cin.clear();
        }
        Card * giveCard = model.mover.getCurrentPlayer()->getHand()[model.getCardIndex(model.mover.getCurrentPlayer()->getPlayerLocStr(), model.mover.getCurrentPlayer())];
        cout << "This is the give card " << giveCard->getCardName()<<endl;
        //The above statment sets giveCard to the card that is in the players hand which
        // has the same name as the location he is in. The only way to get to this point is
        // to have already confirmed this card exists.
        model.mover.shareKnowledge(model.mover.getCurrentPlayer(), toGive[pInput-1], giveCard);
    }
    else if (model.canGetKnowledge())
    {
        vector<Player*> toGet = model.getSharablePlayers("get");
        view.askGetKnowledge(toGet);
        while (pInput < 1 || pInput > toGet.size())
        {
            cin >> pInput;
            cin.ignore();
            cin.clear();
        }
        Card * getCard = toGet[pInput-1]->getHand()[model.getCardIndex(model.mover.getCurrentPlayer()->getPlayerLocStr(),toGet[pInput-1])];
            cout << "This is the get card " << getCard->getCardName()<<endl;
        model.mover.shareKnowledge(toGet[pInput-1],model.mover.getCurrentPlayer(), getCard);
    }
    
        
    
}

void Controller::do_build_station() {
    if (!model.canBuildResearchStation()) {     //Check if possible
        view.printCantBuildRS();
    } 
	else {
		int resCount = model.getResSta();
		if(resCount < 6){                                                       //if fewer than six stations are in play
		

			model.buildResearchStation();
		}
		else {                                                                  //otherwise one must be removed
			vector<string> locations =	model.getReasearchStationCities();		//get list of cities holding ressta
			menu.removeResStaMenu(locations);									//display the prompt	

			int temp = -1;
            while (temp < 0  || temp > resCount)								//read until 0<=temp<=count of res sta
            {
                cin >> temp;													//read which index value to play from the hand
                cin.clear();
                cin.ignore();
            }

			if(temp < resCount)															//if city was selected
			{
				model.removeResearchStation(model.worldMap.locateCity(locations[temp]));//find pointer to it, and remove the research station
				model.buildResearchStation();											//build station at players location
			}
			else{
				//otherwise user chose "No thanks" 
				decMovesUsed();		//so don't consume a move
			}

		}
    }
}


void Controller::do_save_game() {
    string filename = "autosave";
    string name;
    
    view.askFileName();
    getline(cin, name);            // get savegame name from user (reads whole line and discards end of line) cin will be empty after this call...
    
#ifdef __APPLE__ && __MACH__    // fix for 'certain' OSes...
    cin.ignore();
    cin.clear();
#endif
    
    if (!name.empty()) {
        filename = name;
    }
    
    model.savegame(filename);
    view.printProgressSavedMsg();
}

void Controller::do_quit_game() {
    exit(0);
}

bool Controller::isInVector(int x, vector<int>& vec)
{
    if(!vec.empty())        //if it isnt empty
    {
        int size = vec.size();
        for(int i = 0; i<size; i++)
        {
            if(x == vec[i])
                return true;
        }
    }
    
    return false;
}

void Controller::forceDiscard(Player* p){
    vector<Card*> pHand = p->getHand();
    view.askForcedDiscard(pHand);   //get the players hand
    int input = -1;
    while (input < 1 || input > pHand.size())
    {
        cin >> input;
        cin.ignore();
        cin.clear();
    }
    //Instead of simply setting p->remove card directly I'm going through this loop to use the model.
    for (int i = 0; i<=model.players.size()-1;i++)
    {
        if (model.players[i]->getPlayerName() == p->getPlayerName())
            model.players[i]->removeCard(input-1);//remove selected card.
    }
    
    
}
