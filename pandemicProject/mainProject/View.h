//
// View class for Pandemic
// All display routines belong to the view
#include <iostream>
#include <string>
#include <iomanip>
#include "Model.h"
#include "Menu.h"
#include <vector>
using namespace std;

class View
{
public:
	void printTitle();
    void printInvalidInputMsg();
    void printGoodbye();
    void printProgressSavedMsg();
    void printCharterFlightMsg();
    void printTreatDiseaseMsg();
    void printShareKnowledgeMsg();
    void printSaveGameMsg();
    void printGetOrGiveKnowlege(vector<string>);
    void printInfected();
    void askCanCure(string);
    void printPlayersVector(vector<Player*>);
    void askGiveKnowledge(vector<Player*>);
    void askGetKnowledge(vector<Player*>);
    void printCantBuildRS(){cout << "You do not have the required card to build an RS here\n";}
    void printCubeCount(int red, int yellow, int blue, int black);
    void askLocationShuttleFlight(){cout << "Which city would you like to take a shuttle flight to?\n";}
    void askLocationCharterFlight(){cout << "Which city would you like to charter a flight to?\n";};
    void printAdj(vector<string>);
    void displayPlayerInfo(string, string, string);
    void askNumOfPlayers();
    void printNonNumeric() {cout << "User entered in a non-numeric input. Please try again.\n\n";}
	void printBadPlayerCt() {cout << "Invalid number of players. Please try again and choose between 2 and 4 players.\n\n";}
    void printEmptyPlayerNameMessage() {
        cout << "Please enter in a name for the player. Empty names are not valid...\n\n";
    }
	void printBadDiff() {cout << "Invalid difficulty. Please try again and choose between 1 and 3.\n\n";}
	void printBadTurnChoice() {cout << "Invalid choice... Please enter in a valid option number.\n\n";}
	void printNamePrompt(int num) {
        cout << "Enter player " << num+1 << "'s name: ";
    }
	void printDiffPrompt() {
        cout << "\nSelect a difficulty:\n1. Introductory\n2. Standard\n3. Heroic\n\nYour choice: ";
    }
	void printInfectedCities(string iList) {
        cout << "\nInfected cities:\n" << iList<< "\n\n";
    }
	void printMenu() {
        cout << "Please choose an action:\n\n";
        cout << " 1. Drive/Ferry\n";
        cout << " 2. Direct Flight\n";
        cout << " 3. Charter Flight\n";
        cout << " 4. Shuttle Flight\n";
        cout << " 5. Treat Disease\n";
        cout << " 6. Share Knowledge\n";
        cout << " 7. Discover Cure\n";
        cout << " 8. Build Research Station\n";
        cout << " 9. Display infected cities\n";
		cout << "10. Save game\n";
		cout << "11. Quit Game\n\n";
        cout << "Your choice: ";
    }
	void printInfConfirmation(string city) {
        cout<<"*** " << city << " infected ***\n";
    }
	void printEpiConfirmation(string city) {
        cout<<"*** " << city << " has experienced an epidemic! ***\n";
    }
	
	void printPlayOrDiscard(){cout << "\n You've chosen an event card.  Would you like to play it, or discard?\n(0)Play\n(1)Discard\n";}
	void printOutbreaks(vector<string>);
	void askLoadGame();
	void askLoadScenario();
	void askFileName();
    void askWhereTo();
	void playAgain(){cout << "Play again? [1 for yes, 0 for no]: ";}
    void printReasearchStations(vector<string> cities);
    void printAdjCities(City*);
	void printDrawConfirmation(string card){cout  << card << " added to your hand.\n";}
	void newLine(){cout << "\n";}
	
};

