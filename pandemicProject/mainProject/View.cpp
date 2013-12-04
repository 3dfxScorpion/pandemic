#include "View.h"

void View::printTitle() {
    cout << "******************************" << endl;
    cout << "*    Welcome to Pandemic     *" << endl;
    cout << "******************************" << endl << endl << endl;
}

void View::printInvalidInputMsg() {
    cout << "Invalid input.  Try again: ";
}

void View::printGoodbye() {
    cout << "\nGoodbye...\n";
}

void View::printProgressSavedMsg() {
    cout << "Your progress has been saved.\n";
}


void View::printCharterFlightMsg() {
    cout << "Please type the name of a valid city you would like to travel to.\n";
}


void View::printShareKnowledgeMsg() {
    cout << "share knowledge, are you crazy???\n";
}

void View::printTreatDiseaseMsg() {
    cout << "Treating disease...\n";
}

void View::askNumOfPlayers() {
    cout << "\nSet player count: ";
}

void View::displayPlayerInfo(string name, string role, string city) {
    cout <<  "\n**Player: " << name <<  " Role: " << role << " Current Location: "  << city << "**" << endl;
}

void View::printCubeCount(int red, int yellow, int blue, int black) {
    cout << "Cubes remaining:\n";
    cout << "Black: " << black << " Blue: " << blue << " Red: " << red<< " Yellow: " << yellow <<  endl;
}

void View::printAdj(vector<string>cities)
{
    cout << "\nAdjacent cities:\n";
    while(!cities.empty())
    {
        cout << cities.front() << endl;
        cities.erase(cities.begin());
    }
    cout << "Type a city's name to move: \n";
}

void View::askLoadGame() {
    cout << "Would you like to load a game? (Y/N) ";
}

void View::askLoadScenario() {
    cout << "Would you like to load a scenario? (Y/N) ";
}

void View::askFileName() {
    cout << "Please enter a file name (Leave blank for autosave): ";
}

void View::askFileName2() {
    cout << "Please enter a scenario name: ";
}

void View::askWhereTo() {
    cout << "Where to (\"10\" to return to main menu) ? ";
}

void View::printReasearchStations(vector<string> cities){
    cout << menuStringVector(cities, "Research Stations");
}

void View::printAdjCities(City* toCheck){
    cout << menuAdjCities(toCheck);
}

void View::printPlayersVector(vector<Player*> players){
    cout << menuPlayersVector(players);
}

void View::askCanCure(string color){
    cout << "Do you want to cure the "
         << color
         << " disease? (y/n)\n";
    
}

void View::askCanTreat(string color){
    cout << "Do you want to treat the "
        << color
        << " disease? (y/n)\n";
}

void View::printGetOrGiveKnowlege(vector<string> s){
    cout<< menuStringVector(s,"Get or Give Knowledge?");
}

void View::askGiveKnowledge(vector<Player*> p){
    cout << "Which of these players would you like to give knowledge?\n";
    cout << menuPlayersVector(p);
}

void View::askGetKnowledge(vector<Player*> p){
    cout << "Which of these players would you like to get knowledge?\n";
    cout << menuPlayersVector(p);
}

void View::askForcedDiscard(vector<Card*> c){
    cout << "Whick of these cards would you like to discard?\n";
    cout << menuCardsVector(c, "Choose a card");
}

void View::printOutbreaks(vector<string> cities)
{
    int num = cities.size();

    cout<< "\n***** Outbreak";
    if(num>1)
        cout<<"s";
    cout << " occured in the following: ";

    for(int i =0; i<num; i++)
    {
        if(i>0){
            cout << ", ";
            cout << cities[i];
		}
    }
    cout <<"*****\n";
    
    return;

}

void View::forecastMenu(vector<ICard*> icards)
{
	cout << "Select a card to add to the top of the infection deck (last card added is new top of deck)\n";
	
	int x = icards.size();
	for(int i = 0; i<x; i++)
	{
		cout << "(" << i << ")" << icards[i]->getName() << endl;
	}
}