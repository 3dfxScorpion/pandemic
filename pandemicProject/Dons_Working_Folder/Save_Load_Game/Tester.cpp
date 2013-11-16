#include <iostream>
#include <vector>
#include <fstream>

#include "Map.h"

using namespace std;

int main() {
	Map gameMap;
	vector<City*> worldMap;
	string filename = "Cities.txt";					// name of file containing map information
	string savefile = "game1";

	worldMap = gameMap.getWorldMap();
	cout << "Before: " << gameMap.getWorldMap().size() << endl << endl;

	cout << "Populating map from file." << endl;
	gameMap.populateMap(filename);
	cout << "Finished populating map."  << endl << endl;

	cout << "After:  " << gameMap.getWorldMap().size() << endl << endl;

	// test of searching map for city and returning city info
	City* currentCity = gameMap.locateCity("Montreal");
	if(currentCity != NULL) {
		currentCity->setInfectedBlue(3);
	}

	ofstream fp_out(savefile, ios::out);
	if(fp_out.is_open()) {
		gameMap.saveGame(fp_out);
		fp_out.close();
	}
	else
		cout << "Error opening file." << endl;

	cout << "Press any key to exit.";
	cin.get();

	return 0;
}
