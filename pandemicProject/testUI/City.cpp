#include "City.h"

City::City() {
  cityName           = "";
  cityPopulation     = 0;
  numInfectedBlack   = 0;
  numInfectedBlue    = 0;
  numInfectedRed     = 0;
  numInfectedYellow  = 0;
  isInfected         = false;
  researchStation    = false;
  adjCity            = NULL;
}

City::City(string cityName, int cityPop, int blackInfected,
                     int blueInfected, int redInfected,  int yellowInfected,
                     bool infectedStatus, bool researchStatus) {
  setCityName(cityName);                 // sets city name
  setPopulation(cityPop);                // sets population
  setInfectedBlack(blackInfected);       // sets level of black infected
  setInfectedBlue(blueInfected);         // sets level of blue infected
  setInfectedRed(redInfected);           // sets level of red infected
  setInfectedYellow(yellowInfected);     // sets level of yellow infected
  setInfected(infectedStatus);           // sets infected status
  setResearchStation(researchStatus);    // sets research station status
  adjCity = NULL;
}

void City::setCityName(string name) {
  cityName = name;
}

void City::setPopulation(int cityPop) {
  cityPopulation = cityPop;
}

void City::setInfectedBlack(int blackInfected) {
  numInfectedBlack = blackInfected;
}

void City::setInfectedBlue(int blueInfected) {
  numInfectedBlue = blueInfected;
}

void City::setInfectedRed(int redInfected) {
  numInfectedRed = redInfected;
}

void City::setInfectedYellow(int yellowInfected) {
  numInfectedYellow = yellowInfected;
}

void City::setInfected(bool infectedStatus) {
  isInfected = infectedStatus;
}

void City::setResearchStation(bool researchStatus) {
  researchStation = researchStatus;
}

void City::addCity(int cityValue) {
  list* cityNode = new list;
  cityNode->city = cityValue;
  cityNode->next = NULL;

  list* node = adjCity;
  if(node == NULL) {
    node = cityNode;
  }
  else {
    while(node->next == NULL) {
      node = node->next;
    }
    node->next = cityNode;
  }
}

//*********************************************************************************************

string City::getCityName() {
  return cityName;
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

bool City::getInfected() {
  return isInfected;
}

bool City::getResearchStation() {
  return researchStation;
}

vector<int> City::getAdjCity() {
  vector<int> cityList;
  list* node = adjCity;

  while(node != NULL) {
    cityList.push_back(node->city);
    node = node->next;
  }

  return cityList;
}
