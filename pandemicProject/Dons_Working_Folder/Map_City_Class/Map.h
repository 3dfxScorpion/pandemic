#ifndef MAP_H
#define MAP_H

#include <vector>
#include <sstream>
#include <fstream>
#include "City.h"

using std::ifstream;
using std::ofstream;

class Map {
  public:
    Map();                     // default constructor
    int populateMap(string);   // populates map from file (returns 0 if success, 1 if error)
    vector<City*> getWorldMap()
      { return worldMap; }     
    City* locateCity(string);  // takes in city name and returns City*
    string infectedList();     // returns formatted list of infected cities
    string researchList();     // returns formatted list of cities housing research stations
	int loadGame(ifstream &);
	void saveGame(ofstream &);

  private:
    vector<City*> worldMap;
};

#endif
