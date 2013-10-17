#include <vector>
#include <sstream>
#include "cityClass.h"

class mapClass
{
public:
	mapClass();						// default constructor
	int populateMap(string);		// populates map from file (returns 0 if success, 1 if error)
	int getNumberofCities();		// returns number of cities
	cityClass locateCity(string);	// takes in city name and returns cityClass
	ostream infectedList();			// returns formatted list of infected cities

	vector<cityClass> worldMap;
};