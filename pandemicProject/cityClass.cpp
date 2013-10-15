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
	adjCity				= NULL;
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
	adjCity = NULL;						// 
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

void cityClass::addCity(int cityValue) {
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

bool cityClass::getInfected() {
	return isInfected;
}

bool cityClass::getResearchStation() {
	return researchStation;
}

vector<int> cityClass::getAdjCity() {
	vector<int> cityList;
	list* node = adjCity;

	while(node != NULL) {
		cityList.push_back(node->city);
		node = node->next;
	}

	return cityList;
}