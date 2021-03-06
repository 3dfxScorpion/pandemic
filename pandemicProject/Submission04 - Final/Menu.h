#ifndef MENU_H
#define MENU_H
#include <map>
#include "Card.h"
#include "Deck.h"
#include "Map.h"
#include "Model.h"
#include "Player.h"

using std::map;
using std::string;
using std::vector;

class Menu {
  public:
    Menu() {}
    Menu(Map& m, vector<Player*> p, vector<string> c )
        : menuMap(m), players(p), commands(c) {
            setMappedCommands(commands);
    }
    // getters
    int             getInfectionRate()   { return infectionRate; }
	int             getOutbreakRate()    { return outbreakRate;  }
    Map&            getMenuMap()         { return menuMap;       }
    vector<Player*> getMenuPlayers()     { return players;       }
    vector<string>  getMenuCommands()    { return commands;      }
    map<int,string> getMappedCommands()  { return mappedCmds;    }
    // setters
    void setInfectionRate(int r)           { infectionRate  = r; }
	void setOutbreakRate(int z)            { outbreakRate   = z; }
    void setMenuMap(Map& m)                { menuMap        = m; }
    void setMenuPlayers(vector<Player*> p) { players        = p; }
    void setMenuCommands(vector<string> s) { commands       = s; }
    void setMappedCubes(string c, int n)   { mappedCubes[c] = n; }
    void setMappedCommands(vector<string> c) {
        size_t idx = 0;
        vector<string>::iterator cItr = c.begin();
        for ( ; cItr != c.end(); cItr++ ) {
            string tmp = *cItr;
            mappedCmds[idx++] = tmp;
        }
    }
    // prototypes
    string menuCities(Map&);
    string menuHands(vector<Player*>);
    string menuCommands(vector<string>);
    void showMenu(Player*);
    void discardMenu(vector<Card*>);
    void eventMenu(vector<Card*>, vector<int>);
    void updateMenu(Model&);
	void removeResStaMenu(vector<string>);
	void menuCitiesNumbered(Map&);
	void resPopMenu(vector<string>);
	

  private:
    Map menuMap;
    map<string,int> mappedCubes;
    map<int,string> mappedCmds;
    vector<string> commands;
    vector<Player*> players;
    int infectionRate;
	int outbreakRate;
};

string menuAdjCities(City*);
string menuStringVector(vector<string>,string);
string menuPlayersVector(vector<Player*>);
string menuCardsVector(vector<Card*> cards,string label);
#endif
