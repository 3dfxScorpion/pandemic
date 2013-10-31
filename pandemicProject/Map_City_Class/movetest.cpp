#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Map.h"
#include "City.h"

using namespace std;

int main() {
	Map* worldMap = new Map();
	
	if(worldMap->populateMap("Cities.txt")) {
		cout << "Error Creating Map\n";
		cout << "Press any key to exit\n";
		cin.get();
		exit(1);
	}

	City* currentCity = worldMap->locateCity("Atlanta");		// Game default starting city

	int i = -1;
	while(i != 0) {
		cout << "Current City: " << currentCity->getCityName() << endl << endl;

		cout << "Where would you like to go? (0 to Exit)\n";

		vector<string> list = currentCity->getAdjCity();			// get adjacent cities
		
		for(size_t j = 0; j < list.size(); j++) {
			cout << setw(2) << right << j+1 << "  " << list[j] << endl;
		}

		cout << "Please enter destination: ";
		cin >> i;
		if(i != 0) {
			currentCity = worldMap->locateCity(list[i-1]);		// change current city
			system("CLS");
		}
	}
	return 0;
}