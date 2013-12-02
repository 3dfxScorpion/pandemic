#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "Map.h"
#include "PandemicException.h"
#include "dataManip.h"

using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ostringstream;

                                                    
Map::Map() {}  // default constructor does nothing

// parse file
int Map::populateMap(string cityFile) {
    ifstream cityInfoFile;
    string fileInput;
    cityInfoFile.open(cityFile,ifstream::in);

    
    if ( cityInfoFile.fail() ) {
        throw PandemicException("Error Loading Map");
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
                    City* currentCity =
                        new City(cityName,cityColor,population,black, blue, red, yellow, station);
						
					currentCity->setAdjCity(second);
                    while ( !cityInfoFile.eof() ) {
                        second.clear();
                        getline(cityInfoFile,fileInput);
                        if ( fileInput.empty() ) break;
                        second.append(fileInput.begin()+8,fileInput.end());
                        currentCity->setAdjCity(second);
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

City* Map::locateCity(string cityName) {
    for ( size_t i = 0; i < worldMap.size(); i++ ) {
        if ( worldMap[i]->getCityName() == cityName ) {
            return worldMap[i];
        }
    }
    return NULL;
}

string Map::infectedList() {
    ostringstream infectedCities;
    infectedCities << setw(17) << left    << "City:"   << setw(8)
                   << "Black:" << setw(8) << "Blue:"   << setw(8)
                   << "Red:"   << setw(8) << "Yellow:" << endl;
    for ( size_t i = 0; i < worldMap.size(); i++ ) {
        if ( worldMap[i]->getInfectedBool() ) {
            infectedCities << setw(17) << left << worldMap[i]->getCityName()
                << setw(8) << worldMap[i]->getInfectedBlack()
                << setw(8) << worldMap[i]->getInfectedBlue()
                << setw(8) << worldMap[i]->getInfectedRed()
                << setw(8) << worldMap[i]->getInfectedYellow() << endl;
        }
    }
    return infectedCities.str();
}

string Map::researchList() {
    ostringstream researchCities;
    researchCities << "Research Station Locations:" << endl;
    for ( size_t i = 0; i < worldMap.size(); i++ ) {
        if ( worldMap[i]->getResearchStationBool() ) {
            researchCities << worldMap[i]->getCityName() << endl;
        }
    }
    return researchCities.str();
}

void Map::loadGame(ifstream &fp) {
    City* current;
    
    while(fp.good()) {
        string temp;
        bool researchStatus = false;
        
        getline(fp,temp,',');
        if(!fp.good())
            break;
        current = locateCity(temp);
        
        getline(fp,temp,',');
        current->setInfectedBlack(stoi(temp));
        
        getline(fp,temp,',');
        current->setInfectedBlue(stoi(temp));
        
        getline(fp,temp,',');
        current->setInfectedRed(stoi(temp));
        
        getline(fp,temp,',');
        current->setInfectedYellow(stoi(temp));
		
		getline(fp,temp);
        if(temp == "TRUE")
            researchStatus = true;
        else if(temp == "FALSE")
            researchStatus = false;
        else
            cout << "Error parsing file\n";
        current->setResearchStation(researchStatus);
    }
}

void Map::saveGame(ofstream &fp) {
    for(size_t i = 0; i < worldMap.size(); i++) {
        if( worldMap[i]->getInfectedBlack()  != 0 || worldMap[i]->getInfectedBlue()   != 0 ||
            worldMap[i]->getInfectedRed()    != 0 || worldMap[i]->getInfectedYellow() != 0 ||
            worldMap[i]->getResearchStationBool() ) {
                fp  << worldMap[i]->getCityName()        << ","
                    << worldMap[i]->getInfectedBlack()   << ","
                    << worldMap[i]->getInfectedBlue()    << ","
                    << worldMap[i]->getInfectedRed()     << ","
                    << worldMap[i]->getInfectedYellow()  << ","
                    << worldMap[i]->getResearchStation() << endl;
        }
    }
}
