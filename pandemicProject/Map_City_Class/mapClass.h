#include <vector>
#include "cityClass.h"

class mapClass
{
public:
	mapClass();					// default constructor
	int populateMap(string);	// populates map from file (returns 0 if success, 1 if error)
	int getNumberofCities();	// returns number of cities
//private:
	vector<cityClass> worldMap;
};