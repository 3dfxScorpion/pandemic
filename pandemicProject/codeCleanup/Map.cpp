#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "Map.h"

using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::string;
using std::ifstream;
using std::ostringstream;


Map::Map() {}  // default constructor does nothing
// parse file
int Map::populateMap(string cityFile) {
    ifstream cityInfoFile;
    string fileInput;

    cityInfoFile.open(cityFile,ifstream::in);
    if ( cityInfoFile.fail() ) {
        cout << "ERROR: failed opening file.\n";
        return 1;
    }
    if ( cityInfoFile.eof() )
        return 1;
    else {
        string cityName, cityColor, adjCity;
        int population, black, blue, red, yellow;
        bool station;

        while ( !cityInfoFile.eof() ) {
            string first;
            string second;
            // parse file
            getline(cityInfoFile,fileInput);

            if ( fileInput == "" ) {
            }
            else {
                first.append(fileInput.begin(),fileInput.begin()+7);
                second.append(fileInput.begin()+8,fileInput.end());

                if ( first == "NAME:  " ) 
                    cityName = second;
                else if ( first == "Color: " )
                    cityColor = second;
                else if ( first == "Pop:   " )
                    population = stoi(second);
                else if ( first == "Black: " )
                    black = stoi(second);
                else if ( first == "Blue:  " )
                    blue = stoi(second);
                else if ( first == "Red:   " )
                    red = stoi(second);
                else if ( first == "Yellow:" )
                    yellow = stoi(second);
                // 
                else if ( first == "HasSta:" ) {
                    if ( second == "TRUE" )
                        station = true;
                    else if ( second == "FALSE" )
                        station = false;
                    else
                        cout << "ERROR: HasSta\n";
                }
                else if ( first == "Adj:   " ) {
                // populate map vector with cities
                    City currentCity =
                        City(cityName, cityColor, population,
                             black, blue, red, yellow, station);
                    currentCity.setAdjCity(second);
                    while ( !cityInfoFile.eof() ) {
                        second.clear();
                        getline(cityInfoFile,fileInput);
                        if ( fileInput.empty() ) break;
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

int Map::getNumberofCities() {
    return worldMap.size();
}

City Map::locateCity(string cityName) {
    City located;
    for ( int i = 0; i < worldMap.size(); i++ ) {
        if ( worldMap[i].getCityName() == cityName ) {
            located = worldMap[i];
            break;
        }
    }
    return located;
}

string Map::infectedList() {
    ostringstream infectedCities;
    infectedCities << setw(15) << left    << "City:"   << setw(8)
                   << "Black:" << setw(8) << "Blue:"   << setw(8)
                   << "Red:"   << setw(8) << "Yellow:" << endl;
    for ( int i = 0; i < worldMap.size(); i++ ) {
        if ( worldMap[i].getInfectedBool() ) {
            infectedCities << setw(15) << left << worldMap[i].getCityName()
                << setw(8) << worldMap[i].getInfectedBlack()
                << setw(8) << worldMap[i].getInfectedBlue()
                << setw(8) << worldMap[i].getInfectedRed()
                << setw(8) << worldMap[i].getInfectedYellow() << endl;
        }
    }
    return infectedCities.str();
}
