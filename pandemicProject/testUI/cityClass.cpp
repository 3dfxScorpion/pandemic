#include "cityClass.h"

cityClass::cityClass() {
	cityName			= "";
	cityPopulation		= 0;
	numInfectedBlack	= 0;
	numInfectedBlue		= 0;
	numInfectedRed		= 0;
	numInfectedYellow	= 0;
	isInfected			= false;
	researchStation		= false;
}

cityClass::cityClass(string cityName, int cityPop, int blackInfected, int blueInfected, int redInfected, 
						int yellowInfected, bool infectedStatus, bool researchStatus) {
	setCityName(cityName);				// sets city name
	setPopulation(cityPop);				// sets population
	setInfectedBlack(blackInfected);	// sets level of black infected
	setInfectedBlue(blueInfected);		// sets level of blue infected
	setInfectedRed(redInfected);		// sets level of red infected
	setInfectedYellow(yellowInfected);	// sets level of yellow infected
	setInfected(infectedStatus);		// sets infected status
	setResearchStation(researchStatus);	// sets research station status
}

void cityClass::setCityName(string name) {
	cityName = name;
}

void cityClass::setPopulation(int cityPop) {
	cityPopulation = cityPop;
}

void cityClass::setInfectedBlack(int blackInfected) {
	numInfectedBlack = blackInfected;
}

void cityClass::setInfectedBlue(int blueInfected) {
	numInfectedBlue = blueInfected;
}

void cityClass::setInfectedRed(int redInfected) {
	numInfectedRed = redInfected;
}

void cityClass::setInfectedYellow(int yellowInfected) {
	numInfectedYellow = yellowInfected;
}

void cityClass::setInfected(bool infectedStatus) {
	isInfected = infectedStatus;
}

void cityClass::setResearchStation(bool researchStatus) {
	researchStation = researchStatus;
}

void cityClass::setAdjCity(string adjCityName) {
	adjCity.push_back(adjCityName);
}

//*********************************************************************************************

string cityClass::getCityName() {
	return cityName;
}

int cityClass::getPopulation() {
	return cityPopulation;
}

int cityClass::getInfectedBlack() {
	return numInfectedBlack;
}

int cityClass::getInfectedBlue() {
	return numInfectedBlue;
}

int cityClass::getInfectedRed() {
	return numInfectedRed;
}

int cityClass::getInfectedYellow() {
	return numInfectedYellow;
}

bool cityClass::getInfectedBool() {
	return isInfected;
}

string cityClass::getInfected() {
	string result;
	if(isInfected)
		result = "TRUE";
	else
		result = "FALSE";
	return result;
}

bool cityClass::getResearchStationBool() {
	return researchStation;
}

string cityClass::getResearchStation() {
	string result;
	if(researchStation)
		result = "TRUE";
	else
		result = "FALSE";
	return result;
}

vector<string> cityClass::getAdjCity() {
	vector<string> cityList(adjCity);
	return cityList;
}

int cityClass::getNumberAdjacent() {
	return adjCity.size();
}