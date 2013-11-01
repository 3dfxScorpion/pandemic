#include "City.h"

City::City() {
    cityName          = "";
    cityColor         = "";
    cityPopulation    = 0;
    numInfectedBlack  = 0;
    numInfectedBlue   = 0;
    numInfectedRed    = 0;
    numInfectedYellow = 0;
    isInfected        = false;
    researchStation   = false;
}

City::City(string cityName, string cityColor, int cityPop, int blackInfected,
      int blueInfected, int redInfected, int yellowInfected, bool researchStatus) {
    setCityName(cityName);               // sets city name
    setCityColor(cityColor);             // sets city color
    setPopulation(cityPop);              // sets population
    setInfectedBlack(blackInfected);     // sets level of black infected
    setInfectedBlue(blueInfected);       // sets level of blue infected
    setInfectedRed(redInfected);         // sets level of red infected
    setInfectedYellow(yellowInfected);   // sets level of yellow infected
    setInfected();                       // sets infected status
    setResearchStation(researchStatus);  // sets research station status
}

void City::setCityName(string name) {
    cityName = name;
}

void City::setCityColor(string color) {
    cityColor = color;
}

void City::setPopulation(int cityPop) {
    cityPopulation = cityPop;
}

void City::setInfectedBlack(int blackInfected) {
    numInfectedBlack = blackInfected;
    setInfected();  // test if infected
}

void City::setInfectedBlue(int blueInfected) {
    numInfectedBlue = blueInfected;
    setInfected();  // test if infected
}

void City::setInfectedRed(int redInfected) {
    numInfectedRed = redInfected;
    setInfected();  // test if infected
}

void City::setInfectedYellow(int yellowInfected) {
    numInfectedYellow = yellowInfected;
    setInfected();  // test if infected
}

void City::setInfected() {
    if ( numInfectedBlack > 0 || numInfectedBlue   > 0 ||
         numInfectedRed   > 0 || numInfectedYellow > 0 )
        isInfected = true;
    else
        isInfected = false;
}

void City::setResearchStation(bool researchStatus) {
    researchStation = researchStatus;
}

void City::setAdjCity(string adjCityName) {
    adjCity.push_back(adjCityName);
}

//*****************************************************************************

string City::getCityName() {
    return cityName;
}

string City::getCityColor() {
    return cityColor;
}

int City::getPopulation() {
    return cityPopulation;
}

int City::getInfectedBlack() {
    return numInfectedBlack;
}

int City::getInfectedBlue() {
    return numInfectedBlue;
}

int City::getInfectedRed() {
    return numInfectedRed;
}

int City::getInfectedYellow() {
    return numInfectedYellow;
}

bool City::getInfectedBool() {
    return isInfected;
}

string City::getInfected() {
    string result;
    if ( isInfected )
        result = "TRUE";
    else
        result = "FALSE";
    return result;
}

bool City::getResearchStationBool() {
    return researchStation;
}

string City::getResearchStation() {
    string result;
    if ( researchStation )
        result = "TRUE";
    else
        result = "FALSE";
    return result;
}

vector<string> City::getAdjCity() {
    vector<string> cityList(adjCity);
    return cityList;
}

int City::getNumberAdjacent() {
    return adjCity.size();
}
