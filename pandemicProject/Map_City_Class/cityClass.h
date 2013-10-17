#include <iostream>
#include <string>
#include <vector>

using namespace std;

<<<<<<< HEAD
=======
struct list
{
	int   city;
	int test;
	int test2;
	list* next;
};

>>>>>>> d21a82c6227ad753492499a32b543aa48fe83338
class cityClass 
{
public:
	// default constructor
	cityClass();

	// cityClass(cityName, population, black, blue, red, yellow, infected, station)
	cityClass(string, int, int, int, int, int, bool, bool);

	void	setCityName(string);		// sets city name
	void	setPopulation(int);			// sets population
	void	setInfectedBlack(int);		// sets level of black infected
	void	setInfectedBlue(int);		// sets level of blue infected
	void	setInfectedRed(int);		// sets level of red infected
	void	setInfectedYellow(int);		// sets level of yellow infected
	void	setInfected(bool);			// sets infected status
	void	setResearchStation(bool);	// sets research station status
	void	setAdjCity(string);			// adds city to list of adjacent cities

	string	getCityName();				// returns city name
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
	int		cityPopulation;				// population of city
	int		numInfectedBlack;			// number of people infected with black virus
	int		numInfectedBlue;			// number of people infected with blue virus
	int		numInfectedRed;				// number of people infected with red virus
	int		numInfectedYellow;			// number of people infected with yellow virus
	bool	isInfected;					// is city infected
	bool	researchStation;			// does city have research station
<<<<<<< HEAD
	vector<string> adjCity;				// vector of adjacent cities
};
=======
	list*	adjCity;					// linked list of adjacent cities
};

<<<<<<< HEAD
>>>>>>> d21a82c6227ad753492499a32b543aa48fe83338
=======
>>>>>>> d21a82c6227ad753492499a32b543aa48fe83338
