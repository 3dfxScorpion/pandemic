#ifndef MAP_H
#define MAP_H
#include <vector>
#include <sstream>
#include "City.h"

class Map {
  public:
    Map();                    // default constructor

    int populateMap(string);  // populates map from file
                              // (returns 0 if success, 1 if error)
    int getNumberofCities();  // returns number of cities
    City* locateCity(string);  // takes in city name and returns City
    string infectedList();    // returns formatted list of infected cities

    vector<City*> worldMap;
};

#include "Map.cpp"
#endif

