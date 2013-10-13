#include <iostream>
#include <string>

using namespace std;

struct list
{
	int   city;
	list* next;
};

class cityClass 
{
public:
	void setCityName(string);		// sets city name
	void setPopulation(int);		// sets population
	void setInfectedBlack(int);		// sets level of black infected
	void setInfectedBlue(int);		// sets level of blue infected
	void setInfectedRed(int);		// sets level of red infected
	void setInfectedYellow(int);	// sets level of yellow infected
	void setInfected(bool);			// sets infected status
	void setResearchStation(bool);	// sets research station status
	void addCity(string);			// adds city to list of adjacent cities

	string getCityName();			// returns city name
	int    getPopulation();			// returns city population
	int    getInfectedBlack();		// return black infection level
	int    getInfectedBlue();		// return blue infection level
	int    getInfectedRed();		// return red infection level
	int    getInfectedYellow();		// return yellow infection level
	bool   getInfected();			// returns city infection status
	bool   getResearchStation();	// returns research station status
	list*  getAdjCity();			// returns a list of adjacent cities

private:
	string	cityName;				// name of city
	int		cityPopulation;			// population of city
	int		numInfectedBlack;		// number of people infected with black virus
	int		numInfectedBlue;		// number of people infected with blue virus
	int		numInfectedRed;			// number of people infected with red virus
	int		numInfectedYellow;		// number of people infected with yellow virus
	bool	isInfected;				// is city infected
	bool	ResearchStation;		// does city have research station
	list*	adjCity;				// linked list of adjacent cities
};