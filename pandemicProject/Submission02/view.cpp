#include "view.h"

void view::printTitle()
{
	cout << "******************************" << endl;
	cout << "*    Welcome to Pandemic     *" << endl;
	cout << "******************************" << endl << endl << endl;
}

void view::askNumOfPlayers() {
    cout << "Set player count: ";
}

void view::displayPlayerInfo(string name, string role, string city)
{
	cout <<  "\n**Player: " << name <<  " Role: " << role << " Current Location: "  << city << "**" << endl;

}

void view::printCubeCount(int red, int yellow, int blue, int black)
{
	cout << "Cubes remaining:\n";
	cout << "Red: " << red << " Yellow: " << yellow << " Blue: " << blue << " Black: " << black << endl;

}

void view::printAdj(vector<string>cities)
{
	cout << "\nAdjacent cities:\n";
	while(!cities.empty())
	{
		cout << cities.front() << endl;
		cities.erase(cities.begin());
	}
	cout << "Type a city's name to move: \n";
}