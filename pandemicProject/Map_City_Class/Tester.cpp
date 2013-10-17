//#include <iostream>
#include "mapClass.h"

using namespace std;

int main() {
	mapClass gameMap;
	string filename = "Cities.txt";

	cout << gameMap.getNumberofCities() << endl;

	gameMap.populateMap(filename);

	cout << gameMap.getNumberofCities() << endl << endl;;

/*
	for(int i = 0; i < gameMap.getNumberofCities(); i++) {
		cout << "City:   " << gameMap.worldMap[i].getCityName()			<< endl;
		cout << "Pop:    " << gameMap.worldMap[i].getPopulation()		<< endl;
		cout << "Black:  " << gameMap.worldMap[i].getInfectedBlack()	<< endl;
		cout << "Blue:   " << gameMap.worldMap[i].getInfectedBlue()		<< endl;
		cout << "Red:    " << gameMap.worldMap[i].getInfectedRed()		<< endl;
		cout << "Yellow: " << gameMap.worldMap[i].getInfectedYellow()	<< endl;
		cout << "IsInf:  " << gameMap.worldMap[i].getInfected()			<< endl;
		cout << "HasSta: " << gameMap.worldMap[i].getResearchStation()	<< endl;
		vector<string> cityList(gameMap.worldMap[i].getAdjCity());
		cout << "Adj:    " << cityList[0] << endl;
		for(int i = 1; i < cityList.size(); i++) {
			cout << "        " << cityList[i] << endl;
		}
		cout << endl;
	}
*/

/*
	cityClass currentCity = gameMap.locateCity("Essen");
	cout << currentCity.getCityName() << endl;
*/


	
	cout << "Press any key to exit.";
	cin.get();

	return 0;
}
