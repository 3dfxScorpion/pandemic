//
// View class for Pandemic
// All display routines belong to the view
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class View
{
public:
	void printTitle();
    void printCubeCount(int red, int yellow, int blue, int black);
    void printAdj(vector<string>);
    void displayPlayerInfo(string, string, string);
    void askNumOfPlayers();
    void printNonNumeric() {cout << "User entered in a non-numeric input, ending program.\n\n";}
	void printBadPlayerCt() {cout << "Invalid number of players. Please try again and choose between 2 and 4 players.\n\n";}
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
        cout << "1. Move adjacent\n";
        cout << "2. Display infected cities\n";
		cout << "3. Save game\n";
		cout << "4. Quit\n\n";
        cout << "Your choice: ";
    }
	void printInfConfirmation(string city) {
        cout<<"*** " << city << " infected ***\n";
    }
	void printNoCubes() {
        cout<<"*****\nGame over! You ran out of cubes!\n*****";
    }
	void askLoadGame();
	void askLoadScenario();
	void askFileName();
	void playAgain(){cout << "Play again? [1 for yes, - for no]: ";}
};