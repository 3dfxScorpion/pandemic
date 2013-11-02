#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Map.h"
#include "City.h"

using namespace std;

int main() {
	string infStr[48] = { 
		"Sydney","Bangkok","Tokyo","Manila","Beijing","Ho Chi Minh City","Hong Kong","Taipei","Shanghai","Seoul","Osaka","Jakarta",
		"Washington","St. Petersburg","Essen","Montreal","Chicago","Milan","San Francisco","Atlanta","London","Paris","Madrid","New York",
		"Miami","Mexico City","Los Angeles","Kinshasa","Lagos","Bogota","Lima","Santiago","Khartoum","Sao Paulo","Buenos Aires","Johannesburg",
		"Karachi","Istanbul","Delhi","Mumbai","Chennai","Moscow","Riyadh","Algiers","Baghdad","Kolkata","Tehran","Cairo"};

	Map* worldMap = new Map();
	City* currentCity;
	
	if(worldMap->populateMap("Cities.txt")) {
		cout << "Error Creating Map\n";
		cout << "Press any key to exit\n";
		cin.get();
		exit(1);
	}

	int found = 0;
	int notFound = 0;
	for(int i = 0; i < 48; i++) {
		currentCity = worldMap->locateCity(infStr[i]);
		cout << setw(15) << right << infStr[i];
		if((currentCity->getCityName()) == (infStr[i])) {
			cout << setw(10) << right << "Found!\n";
			found++;
		}
		else {
			cout << setw(10) << right << "Error!\n";
			notFound++;
		}
	}
	cout << endl;
	cout << setw(3) << right << found << " cities found successfully!\n";
	cout << setw(3) << right << notFound << " cities not found...\n";
	cout << endl;

	cout << "Press any key to exit.";
	cin.get();
	return 1;
}
