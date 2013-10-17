#include <fstream>
#include <string>
#include <sstream>
#include "mapClass.h"

// default constructor
mapClass::mapClass() {
	// does nothing
}

// parse file
int mapClass::populateMap(string cityFile) {
	ifstream cityInfoFile;
	string fileInput;

	cityInfoFile.open(cityFile,ifstream::in);
	if(cityInfoFile.fail())
		cout << "ERROR: failed opening file.\n";

	if(cityInfoFile.eof())
		return 1;
	else {
		string cityName, adjCity;
		int population, black, blue, red, yellow;
		bool infected, station;

		while(!cityInfoFile.eof()) {
			string first;
			string second;

			// parse file
			getline(cityInfoFile,fileInput);

			if(fileInput == "") {
			}
			else {
				first.append(fileInput.begin(),fileInput.begin()+7);
				second.append(fileInput.begin()+8,fileInput.end());

				if(first == "NAME:  ") 
					cityName = second;
				else if(first == "Pop:   ")
					population = stoi(second);
				else if(first == "Black: ")
					black = stoi(second);
				else if(first == "Blue:  ")
					blue = stoi(second);
				else if(first == "Red:   ")
					red = stoi(second);
				else if(first == "Yellow:")
					yellow = stoi(second);
				// 
				else if(first == "IsInf: ") {
					if(second == "TRUE")
						infected = true;
					else if(second == "FALSE")
						infected = false;
					else
						cout << "ERROR: IsInf\n";
				}
				// 
				else if(first == "HasSta:") {
					if(second == "TRUE")
						station = true;
					else if(second == "FALSE")
						station = false;
					else
						cout << "ERROR: HasSta\n";
				}
				else if(first == "Adj:   ") {
					// populate map vector with cities
					cityClass currentCity = cityClass(cityName, population, black, blue, red, yellow, infected, station);
					
					currentCity.setAdjCity(second);
					while(!cityInfoFile.eof()) {
						second.clear();
						getline(cityInfoFile,fileInput);
						if(fileInput.empty()) break;
						second.append(fileInput.begin()+8,fileInput.end());
						currentCity.setAdjCity(second);
					}
					worldMap.push_back(currentCity);
				}
				else {
					cout << "ERROR: File Parser\n";
					return 1;
				}
			}
		}
	}
	return 0;
}

int mapClass::getNumberofCities() {
	return worldMap.size();
}
