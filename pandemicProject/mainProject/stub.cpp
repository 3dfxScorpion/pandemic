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

int main()
{
    printIntro();
    
    int numOfPlayers = getNumOfPlayers();
    int difficulty = getDifficulty();
    
    setUpBoard();
    infectCities();
    
    dealRoleCards(numOfPlayers);
    placePawns();
    dealPlayerCards(numOfPlayers);
    
    shuffleEpidemicsIn(difficulty);
    checkWhoGoesFirst();
    
    int infectionRate[7] = {2, 2, 2, 3, 3, 4, 4};
    int outbreakNumber[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8}; //Does this start at one? I have to double check!
    
    //Main menu of the game
    
    displayGameState(infectionRate[0], outbreakNumber[0]); //probably some while loops here
    displayPlayerHand();
    displayOptions();
    
    //After the players' turns
    
    drawTwoCards();
    infectTwoCities();
    moveToNextPlayer();
    infectTwoCities();
    moveToNextPlayer();
    
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
    
    //Obviously some count until 0 will happen. Probably a for loop. I hardcoded a min of 2 players.
    cout << "Player " << playerCount << " is assigned the role: Medic.\n\n";
    cout << "Player " << playerCount-1 << " is assigned the role: Scientist.\n\n";
    
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
    
    cout << "------------------------------------------------------------\n";
    cout << "                 State of the World\n\n\n";
    cout << "Infected Cities:\n";
    cout << "City	Red	  Blue	Yellow  Black\n"; //obviously some setw stuff to be done here
    cout << "city1   0      0     2       0\n\n";
    cout << "Infection rate: " << infectRate << "\n";
    cout << "Outbreak number: " << outbreakNum << "\n\n";
    cout << "Number of remaining player cards: 30\n";
    cout << "------------------------------------------------------------\n";
}

void displayPlayerHand() {
    //Should this display ALL player hands? For strategic purposes?
}

void displayOptions() {
    /*
     
     This should display the player menu. It would be nice to have checking options to omit options if they possibly cannot do something with what cards they have. So maybe something like this:
     
     Player X, please select your first(2nd, 3rd, 4th) action:
     
     1. Drive/Ferry {
     Where would you like to move to?:
     -1. San Francisco
     -2. city 2
     -3. etc…
     Their choice moves their location to the chosen city, and the # of actions is subtracted by 1.
     }
     
     2. Direct Flight (If they have city cards in their hand other than the one their pawn is in) {
     
     Where would you like to directly fly to?:
     -display cities
     -make decision
     -move player
     -actions -1
     }
     
     3. Charter Flight (If they have a city card in their hand that matches the name of the city their pawn is in) {
     
     Where would you like to charter fly to?:
     -display cities
     -make decision
     -move player
     }
     
     4. Shuttle Flight (Only if another research station exists) {
     
     Which city would you like to shuttle fly to?:
     -display cities
     -make decision
     -move player
     }
     
     5. Treat Disease (Only if a cube exists on the same location the player is on) {
     
     If there is only 1 kind of cube color AND not cured: remove 1 cube
     If there is only 1 kind of cube color AND is cured: remove all cubes
     If there are more than 1 kind of cube: Player needs to decide which color, then just use the if cases above.
     
     Treating disease…
     
     -checkCubeStatus() //Whatever color they removed, the game should check if anymore remain on the map ONLY if this disease has been cured. If no more remain on the board, the disease status is set to eradicated. If there is no cure, ignore this function.
     
     -checkWinOrLose() //checks ALL cases on whether the players won or lost. In this case, it checks if all diseases are eradicated by the end of this turn
     
     }
     
     6. Share Knowledge (If two players are in the same location and either one of them own that city player card) {
     
     What would you like to do?
     - Give player a card
     - Take player card (maybe should ask if the player agrees? Or is this forced?)
     
     Sharing knowledge…
     Player X received [city Card] from Player N.
     
     -checkPlayerHandLimits() //Checks if each player has 7 or less cards. If not, they must discard one immediately.
     
     }
     
     7. Discover Cure (ONLY if a player has 5 of the same color card AND is in a city that has a research station) {
     
     -Player discards said 5 cards, and the disease status of that color changes to cured.
     
     The [color] disease has been cured!
     
     }
     
     8. Pass //Just pass your turn, making the action counter equal 0 or 4 (whatever we choose to count them) and moves on.
     
     9. Quit //End the game. Do not do anything else and just say quitting the game or something.
     
     */
}

void drawTwoCards() {
    //Player draws 2 cards and adds it to their hand. There is NO limit as long as the first epidemic has not been drawn
    //yet. This function should be able to handle what happens when epidemics are drawn and if so, perform some
    //performEpidemic() function. If the player cannot draw any cards, the players LOSE!

}

void infectTwoCities() {
    //Player draws 2 infection cards and places 1 disease cube of such color on that drawn city. This function must handle
    //what happens when outbreaks occur as well. If there are no more cubes to distribute, OR if the outbreak number
    //reaches 8, the players LOSE!
}

void moveToNextPlayer() {
    //Just move to the next player. How we decide who goes next is up to us I guess…since this is text based. This assumes
    //everything is okay and no one has caused the game to end.
}

/*
 
 If the players have lose:
 
 Display the reason the players lost and say they lost, asking if they’d like to play again or quit.
 
 If the players won:
 
 Just display that they have won and congratulate them…then asks if they’d like to play again.
 
 */





