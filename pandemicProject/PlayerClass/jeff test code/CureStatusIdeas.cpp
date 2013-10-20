/*
Issue #15: Keep track of disease cure status
*/

#include <string>
#include <iostream>
using namespace std;
/*
enum cureStatus {UNCURED, CURED, ERADICATED};

cureStatus redDisease = UNCURED;
cureStatus blueDisease = UNCURED;
cureStatus blackDisease = UNCURED;
cureStatus yellowDisease = UNCURED;

void cureDisease(string color)
{	// Cure conditions checked in Player class?
	switch (color)
	{
	case "red":
		redDisease = CURED;
		break;
	case "blue":
		blueDisease = CURED;
		break;
	case "black":
		blackDisease = CURED;
		break;
	case "yellow":
		yellowDisease = CURED;
	default:
		cout << "Nonexistant Disease" << endl;  // or other error message
	}
}


void eradicateDisease(string color)
{	// Eradication conditions checked elsewhere?
	if (color == "red" && redDisease == CURED)
		redDisease = ERADICATED;
	else if (color == "blue" && blueDisease == CURED)
		blueDisease = ERADICATED;
	else if (color == "black" && blackDisease == CURED)
		blackDisease = ERADICATED;
	else if (color == "yellow" && yellowDisease == CURED)
		redDisease = ERADICATED;
	else
		cout << "Disease cannot be eradicated" << endl; // or other form of error handling
}

//OR
void changeCureStatus(string color, cureStatus newStatus)
{   // assuming all condition checking done outside
	switch (color)
	{
	case "red":
		redDisease = newStatus;
		break;
	case "blue":
		blueDisease = newStatus;
		break;
	case "black":
		blackDisease = newStatus;
		break;
	case "yellow":
		yellowDisease = newStatus;
	default:
		cout << "Invalid disease color" << endl;
	}
}

void resetDiseases()
{
	redDisease = UNCURED;
	blueDisease = UNCURED;
	blackDisease = UNCURED;
	yellowDisease = UNCURED;
}*/