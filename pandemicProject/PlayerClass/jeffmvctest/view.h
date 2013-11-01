//
// View class for Pandemic
// All display routines belong to the view
#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <vector>
#include "model.h"
#include "Card.h"

using namespace std;

class view
{
public:
    view();
	void printTitle();
	void printNamePrompt(int num){cout << "Enter player " << num+1 << "'s name: ";}
	void printDiffPrompt(){cout << "\nSelect a difficulty:\n1. Introductory\n2. Standard\n3.Heroic\n:";}
    void opExpertEventPrompt(vector<Card*> _check);
    void whichCityPrompt(){cout << "\nWhich city would you like to travel to?\n" ;}
    void otherPlayerAction(string n1, string n2){cout << n1 << " would like to perform an action on "
                                                      << n2 << ". \nIs that OK? (y/n)\n" ;}
};
#endif