#include "view.h"

void view::printTitle()
{
	cout << "******************************" << endl;
	cout << "*    Welcome to Pandemic     *" << endl;
	cout << "******************************" << endl << endl << endl;
	cout << "Set player count: ";
}

void view::printNamePrompt(int num)
{
	cout << "Enter player " << num+1 << "'s name: ";
}