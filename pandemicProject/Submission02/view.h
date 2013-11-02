//
// View class for Pandemic
// All display routines belong to the view
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class view
{
public:
	void printTitle();
	void printNamePrompt(int num){cout << "Enter player " << num+1 << "'s name: ";};
	void printDiffPrompt(){cout << "\nSelect a difficulty:\n1. Introductory\n2. Standard\n3.Heroic\n:";};
	void printInfectedCities(string iList){cout << "\nInfected citites:\n" << iList<< "\n"<<endl;};
	void printMenu(){cout << "1. Move adjacent\n2.Display infected cities\n:";};
	void printCubeCount(int red, int yellow, int blue, int black);
	void printInfConfirmation(string city){cout<<"*** " << city << " infected ***\n";};
	void printAdj(vector<string>);
	void printNoCubes(){cout<<"*****\nGame over! You ran out of cubes!\n*****";};
	void displayPlayerInfo(string, string, string);
};