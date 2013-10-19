#include <iostream>
#include <string>
#include <vector>

using namespace std;
#ifndef CITYCLASS_H
#define CITYCLASS_H
class cityClass 
{
public:
	// default constructor
	cityClass();

	// cityClass(cityName, population, black, blue, red, yellow, station)
	cityClass(string, string, int, int, int, int, int, bool);

	void	setCityName(string);		// sets city name
	void	setCityColor(string);		// sets city color
	void	setPopulation(int);			// sets population
	void	setInfectedBlack(int);		// sets level of black infected
	void	setInfectedBlue(int);		// sets level of blue infected
	void	setInfectedRed(int);		// sets level of red infected
	void	setInfectedYellow(int);		// sets level of yellow infected
	void	setInfected();				// sets infected status
	void	setResearchStation(bool);	// sets research station status
	void	setAdjCity(string);			// adds city to list of adjacent cities

	string	getCityName();				// returns city name
	string	getCityColor();				// returns city color
	int		getPopulation();			// returns city population
	int		getInfectedBlack();			// return black infection level
	int		getInfectedBlue();			// return blue infection level
	int		getInfectedRed();			// return red infection level
	int		getInfectedYellow();		// return yellow infection level
	bool	getInfectedBool();			// returns city infection status as bool
	string	getInfected();				// returns city infection status as string
	bool	getResearchStationBool();	// returns research station status as bool
	string	getResearchStation();		// returns research station status as string
	vector<string>	getAdjCity();		// returns a vector of adjacent cities
	int		getNumberAdjacent();		// returns the number of adjacent cities

private:
	string	cityName;					// name of city
	string	cityColor;					// color of city
	int		cityPopulation;				// population of city
	int		numInfectedBlack;			// number of people infected with black virus
	int		numInfectedBlue;			// number of people infected with blue virus
	int		numInfectedRed;				// number of people infected with red virus
	int		numInfectedYellow;			// number of people infected with yellow virus
	bool	isInfected;					// is city infected
	bool	researchStation;			// does city have research station
	vector<string> adjCity;				// vector of adjacent cities
};

#endif