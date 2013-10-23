//
// View class for Pandemic
// All display routines belong to the view
#include <iostream>
using namespace std;

class view
{
public:
	void printTitle();
	void printNamePrompt(int num){cout << "Enter player " << num+1 << "'s name: ";};
	void printDiffPrompt(){cout << "\nSelect a difficulty:\n1. Introductory\n2. Standard\n3.Heroic\n:";};
};