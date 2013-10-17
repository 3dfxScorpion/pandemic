#ifndef MAP_H
#define MAP_H
#include <vector>
#include "City.h"

class Map
{
public:
	Map();				// default constructor
	Map(string);		// constructor (string = filename)
private:
	vector<City> worldMap;
};

#endif
