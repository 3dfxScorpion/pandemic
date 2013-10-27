#include <iostream>

using namespace std;

//Signatures/Prototypes

//These may not even be the real names for the functions but they are place holders.
//Most are void as well for now, and will definitely change when we know what they return.

void printIntro();
int getNumOfPlayers();
int getDifficulty();
void setUpBoard();
void infectCities();
void dealRoleCards(int playerCount);
void placePawns();
void dealPlayerCards(int playerCount);
void shuffleEpidemicsIn(int difficultyLevel);
void checkWhoGoesFirst();
void displayGameState(int infectRate, int outbreakNum);
void displayPlayerHand();
void displayOptions();
void drawTwoCards();
void infectTwoCities();
void moveToNextPlayer();
bool outbreakTest(int,int);		//int params for simplicity, tailor to actual types when headers included
void doOutbreak(int, int);
bool validMove(int);
void moveCurrentPlayer(int);
void buildResearch(int);
void treatDisease(int);
void shareKnowledge(int, int);
void performAnAction();
void performDirectFlight(int);
void performCharterFlight(int);
void performShuttleFlight(int);
void discoverCure();
void passTurn();
int quitGame();


int main()
{
    printIntro();
    
    int numOfPlayers = getNumOfPlayers();
    int difficulty = getDifficulty();
    bool didTheyWin = false;
    
    setUpBoard();
    infectCities();
    
    dealRoleCards(numOfPlayers);
    placePawns();
    dealPlayerCards(numOfPlayers);
    
    shuffleEpidemicsIn(difficulty);
    checkWhoGoesFirst();
    
    int infectionRate[7] = {2, 2, 2, 3, 3, 4, 4};
    int outbreakNumber = 0; //Does this start at one? I have to double check!  Array values were the offset, int seems more appropriate.
    
    //Main menu of the game
    while (didTheyWin != true) {
        displayGameState(infectionRate[0], outbreakNumber); //probably some while loops here
        displayPlayerHand();
        
        int moveCount = 0;
        
        while (moveCount != 4) {
            cout << "Player X: Move number " << moveCount+1 << "\n\n";
            performAnAction();
            moveCount++;
        }
        
        //After the players' turns
        
        drawTwoCards();
        infectTwoCities();
        
        int numToAdd = 2;
        int cityP = 2;
        int cityP2 = 1;
        
        if (outbreakTest(cityP, numToAdd)) {
            doOutbreak(cityP2, 0);
        }
        
        moveToNextPlayer();
    }
    
    /*
     
     If the players have lost:
     
     Display the reason the players lost and say they lost, asking if they’d like to play again or quit.
     
     If the players won:
     
     Just display that they have won and congratulate them…then asks if they’d like to play again.
     
     */
    
    return 0;
}

//Functions

void printIntro() {
    cout << "******************************\n";
    cout << "*    Welcome to Pandemic     *\n";
    cout << "******************************\n\n\n";
}

int getNumOfPlayers() {
    int answer;
    
    while (answer < 2 || answer > 4) {
        cout << "How many players will be playing? (2-4): ";
        cin >> answer;
        
        if (answer < 2 || answer > 4) {
            cout << "\nYou cannot play with less than two, or more than four players. Please try again...\n\n";
        }
    }
    return answer;
}

int getDifficulty() {
    int diff = 0; //For some reason, not setting this to 0 skipped the function if we answered 4 for the 1st question.
    
    while (diff < 4 || diff > 6) {
        cout << "\nWhat difficulty would you like to play in? (Introductory – 4, Standard – 5, Heroic – 6): ";
        cin >> diff;
        
        if (diff < 4 || diff > 6) {
            cout << "\nYou must enter in a difficulty from 4 through 6. Please try again...\n\n";
        }
    }
    return diff;
}

void setUpBoard() {
    cout << "\nSetting up game...\n\n";
    
    //This would set the outbreak markers, infection rate, disease statuses, place the decks where they needed to be after
    //shuffling, and the # of cubes/stations.
}

void infectCities() {
    cout << "Infecting Cities...\n\n";
    
    /*This is where the game will set up the infection of each city, 3 cubes to the first 3 cards off the infection deck, 2
     to the next 3, and then 1 on the last 3. So NINE cities will be infected at the start with whatever colors were
     chosen.
     
     Maybe something like: */
    
    for (int i = 3; i > 0; i--) {
        for (int j = 3; j > 0; j--) {
            cout << i << " blue disease cubes were placed on city X!\n"; //grammar changed to "cube" if 1 :P
        }
        cout << "\n";
    }
}

void dealRoleCards(int playerCount) {
    cout << "Dealing Player Roles...\n\n";
    
    //Some shuffling of the role cards and dealing of cards is done here.
    
    for (int pCount = 1; pCount <= playerCount; pCount++) {
        cout << "Player " << pCount << " is assigned the role: [random assigned role]!\n\n";
    }
    
}

void placePawns() {
    //Places the respective player pawns on Atlanta. Maybe this can be included in dealRoleCards? Once these are placed,
    //remove all other pawns from the game.
}

void dealPlayerCards(int playerCount) {
    cout << "Dealing hands to the players...\n\n";
}

void shuffleEpidemicsIn(int difficultyLevel) {
    cout << "Setting up player deck...\n\n";
    //shuffles the # of epidemics in the deck. The # depends on the difficulty. The remaining player deck will be split by
    //the # of epidemics, then one card will be placed in each stack and shuffled. THEN these n stacks will be …stacked on
    //top of one another to make 1 complete player deck stack.
}

void checkWhoGoesFirst(/*I guess whatever the dealing card function returns can go here?*/) {
    //checks which player’s hand has the city player card with the highest population. So basically a search algorithm for
    //the highest value. That player goes first.
    
    cout << "Player X has the card with the highest population. You may begin.\n\n";
}

void displayGameState(int infectRate, int outbreakNum) {
    //Something to display the status of each city, what’s infected, what’s the infection rate/outbreak marker value so
    //maybe something like this:
    
    cout << "--------------------------------------------------------------------------\n";
    cout << "                 State of the World\n\n";
    cout << "Infected Cities:\n";
    cout << "City	Red	  Blue	Yellow  Black\n"; //obviously some setw stuff to be done here
    cout << "City:           Blk: Blu: Red: Yel:    City:           Blk: Blu: Red: Yel:\n";
    cout << "San Francisco    1    0    1    0      Algiers          1    0    1    0  \n";
    cout << "Chicago          1    1    0    0      Cairo            0    0    1    1  \n";
    cout << "Atlanta          0    1    1    0      Istanbul         0    1    1    0  \n";
    cout << "Montreal         1    1    0    1      Moscow           0    1    0    1  \n";
    cout << "New York         0    1    1    1      Tehran           1    0    1    1  \n";
    cout << "Washington       1    0    1    1      Baghdad          1    1    1    0  \n";
    cout << "London           0    1    0    1      Riyadh           1    0    1    0  \n";
    cout << "Madrid           0    1    1    0      Karachi          1    1    0    0  \n";
    cout << "Paris            0    1    1    1      Mumbai           0    0    1    1  \n";
    cout << "Essen            1    0    1    0      Delhi            1    0    0    1  \n";
    cout << "Milan            0    1    1    1      Kolkata          0    1    1    0  \n";
    cout << "St. Petersburg   1    0    0    0      Chennai          1    1    1    0  \n";
    cout << "Los Angeles      0    1    0    1      Bangkok          0    1    1    0  \n";
    cout << "Mexico City      1    1    0    0      Jakarta          1    0    1    0  \n";
    cout << "Miami            0    1    1    0      Beijing          0    1    1    1  \n";
    cout << "Bogota           1    0    0    1      Shanghai         1    0    0    1  \n";
    cout << "Lima             1    1    0    0      Hong Kong        0    1    1    0  \n";
    cout << "Santiago         1    1    0    0      Ho Chi Minh City 1    1    1    0  \n";
    cout << "Sao Paulo        1    1    0    0      Seoul            0    1    1    0  \n";
    cout << "Buenos Aires     0    1    1    1      Taipei           0    1    0    1  \n";
    cout << "Lagos            1    1    0    0      Manila           1    0    0    0  \n";
    cout << "Kinshasa         1    0    1    0      Sydney           0    0    1    0  \n";
    cout << "Khartoum         1    0    1    0      Tokyo            1    1    1    1  \n";
    cout << "Johannesburg     1    0    1    0      Osaka            1    0    1    0  \n";
    cout << "--------------------------------------------------------------------------\n";
    cout << "Infection rate: " << infectRate << "\n";
    cout << "Outbreak number: " << outbreakNum << "\n\n";
    cout << "Number of remaining player cards: 30\n";
}

void displayPlayerHand() {
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "   Player1                 Player2                 Player3                 Player4     \n";
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "(0)Cairo                (1)Taipei               (2)Washington           (3)Mexico City:\n";
    cout << "(4)Mexico City          (5)Washington           (6)Khartoum             (7)Tokyo\n";
    cout << "(8)Bangkok              (9)Paris                (10)Kolkata             (11)Milan\n";
    cout << "!!-Epidemic-!!          (12)Seoul               (13)Shanghai            (14)Johannesburg\n";
    cout << "-----------------------------------------------------------------------------------------\n";
}

void displayOptions() {
     
    cout << "1. Drive/Ferry\n";
    cout << "2. Direct Flight\n";
    cout << "3. Charter Flight\n";
    cout << "4. Shuttle Flight\n";
    cout << "5. Treat Disease\n";
    cout << "6. Share Knowledge\n";
    cout << "7. Discover Cure\n";
    cout << "8. Build Research Station\n";
    cout << "9. Pass\n";
    cout << "10. Quit Game\n\n";
}

void drawTwoCards() {
    //Player draws 2 cards and adds it to their hand. There is NO limit as long as the first epidemic has not been drawn
    //yet. This function should be able to handle what happens when epidemics are drawn and if so, perform some
    //performEpidemic() function. If the player cannot draw any cards, the players LOSE!
    cout << "It is the end of your turn. Drawing two Player cards...\n\n";
    cout << "You have drawn: cityX!\n";
    cout << "You have drawn: cityY!\n\n";
    
}

void infectTwoCities() {
    //Player draws 2 infection cards and places 1 disease cube of such color on that drawn city. This function must handle
    //what happens when outbreaks occur as well. If there are no more cubes to distribute, OR if the outbreak number
    //reaches 8, the players LOSE!
    cout << "Now infecting two cities...\n\n";
    cout << "City Z has been infected with 1 [color here] cube!!\n";
    cout << "City A has been infected with 1 [color here] cube!!\n";
}

void moveToNextPlayer() {
    //Just move to the next player. How we decide who goes next is up to us I guess…since this is text based. This assumes
    //everything is okay and no one has caused the game to end.
    
    cout << "It is now Player F's turn!\n\n";
}

bool outbreakTest(int city, int cubesToAdd)
{
	//recieves pointer to a city, and the number of cubes being added (1 if infect cities round, 3 if epidemic)
	//tests to see if doing other would cause an outbreak and returns bool
    
	return false;
}

void doOutbreak(int city, int alreadyDone)
{
	//recieves pointer to a city, performs an outbreak;
	//will recurse if additional outbreaks occur, second parameter is a list of cities that
	// have already experienced an outbreak in this chain to avoid repeats
    
	return;
}

bool validMove(int cityP)
{
	//checks conditions necessary for a move (adjacency, requisite number of cards) ignoring event cards
	//returns true if the move is possible
	return true;
}


void moveCurrentPlayer(int cityP)
{
	//gets pointer to city, sets player location to that city
    
    int choice;
    
    cout << "Where would you like to move to?:\n";
    cout << "1. adjacentCity1\n";
    cout << "2. adjacentCity2\n";
    cout << "3. adjacentCity3\n\n";
    
    cin >> choice;
    cout << "You have chosen choice " << choice << " and moved to city X.\n\n";
}


void buildResearch(int cityP)
{
	//checks number of stations built
	// if less than six, places one at pointer cityP and increments number in play
	// if six, calls displayResearch to list them, and lets user choose which to relocate
    
	cout << "You have built a research station on CityP!\n\n";
}

void treatDisease(int cityP)
{
	//reduces the number of disease cubes by 1, or more if medic
	// gets pointer to players current city
	//
    
	cout << "Treating blue disease cube!\n\n";
}

void shareKnowledge(int cardP, int playerID)
{
	//transfers the card pointed to to the player player pointed to
	//
    
    cout << "Sharing knowledge with Player 4\n\n";
}

void performDirectFlight(int cityP) {
    int choice;
    
    cout << "Where would you like to directly fly to?:\n";
    cout << "1. adjacentCity1\n";
    cout << "2. adjacentCity2\n";
    cout << "3. adjacentCity3\n\n";
    
    cin >> choice;
    cout << "You have chosen choice " << choice << " and moved to city X.\n\n";
    
}

void performCharterFlight(int cityP) {
    int choice;
    
    cout << "Where would you like to charter fly to?:\n";
    cout << "1. adjacentCity1\n";
    cout << "2. adjacentCity2\n";
    cout << "3. adjacentCity3\n\n";
    
    cin >> choice;
    cout << "You have chosen choice " << choice << " and moved to city X.\n\n";
}

void performShuttleFlight(int cityP) {
    int choice;
    
    cout << "Where would you like to shuttle fly to?:\n";
    cout << "1. adjacentCity1\n";
    cout << "2. adjacentCity2\n";
    cout << "3. adjacentCity3\n\n";
    
    cin >> choice;
    cout << "You have chosen choice " << choice << " and moved to city X.\n\n";
}

void discoverCure() {
    cout << "Select which cards to discard: \n\n";
    cout << "There are actually no cards to discard for a cure yet.\n\n";
}

void passTurn() {
    cout << "Passing turn. It is now Player Z's turn...\n\n";
    
}

int quitGame() {
    //Probably should ask if they're sure, just in case it's an accident...
    
    cout << "Quitting game...\n\n";
    exit(0);
}

void performAnAction() {
    int cityP = 1;
    int cardP = 4;
    int playerID = 5 ;
    int decision = 0;
    do {
        displayOptions();
        cin >> decision;
        
        switch (decision) {
            case 1:
                moveCurrentPlayer(1);
                break;
            case 2:
                performDirectFlight(cityP);
                break;
            case 3:
                performCharterFlight(cityP);
                break;
            case 4:
                performShuttleFlight(cityP);
                break;
            case 5:
                treatDisease(cityP);
                break;
            case 6:
                shareKnowledge(cardP, playerID);
                break;
            case 7:
                discoverCure();
                break;
            case 8:
                buildResearch(cityP);
                break;
            case 9:
                passTurn(); //there needs to be a return that sets player moves back to 0.
                break;
            case 10:
                quitGame();
                break;
            default:
                cout << "You didn't choose a valid option, please try again\n\n";
        }
    } while (decision < 1 || decision > 10);
}
