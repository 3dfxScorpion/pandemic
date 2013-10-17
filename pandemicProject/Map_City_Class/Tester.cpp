//#include <iostream>
#include "mapClass.h"

using namespace std;

int main() {
	mapClass gameMap;
	string filename = "Cities_test.txt";

	cout << gameMap.getNumberofCities() << endl;

	gameMap.populateMap(filename);

	cout << gameMap.getNumberofCities() << endl << endl;;

	gameMap.worldMap[3].setInfectedBlack(0);
	gameMap.worldMap[3].setInfectedBlue(0);
	gameMap.worldMap[3].setInfectedRed(0);
	gameMap.worldMap[3].setInfectedYellow(0);

	for(int i = 0; i < gameMap.getNumberofCities(); i++) {
		cout << "City:   " << gameMap.worldMap[i].getCityName()			<< endl;
		cout << "Color:  " << gameMap.worldMap[i].getCityColor()		<< endl;
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

/*
	cityClass currentCity = gameMap.locateCity("Essen");
	cout << currentCity.getCityName() << endl;
*/

	cout << gameMap.infectedList();
	
	cout << "Press any key to exit.";
	cin.get();

	return 0;
}
