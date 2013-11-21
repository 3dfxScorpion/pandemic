#ifndef MENU_H
#define MENU_H
#include <map>
#include "Card.h"
#include "Deck.h"
#include "Map.h"
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
    Map&            getMenuMap()         { return menuMap;    }
    vector<Player*> getMenuPlayers()     { return players;    }
    vector<string>  getMenuCommands()    { return commands;   }
    map<int,string> getMappedCommands()  { return mappedCmds; }
		// setters
    void setMenuMap(Map& m)                { menuMap  = m; }
    void setMenuPlayers(vector<Player*> p) { players  = p; }
    void setMenuCommands(vector<string> s) { commands = s; }
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
    void   showMenu(Player*);

  private:
    Map menuMap;
    map<string,int> mappedCubes;
    map<int,string> mappedCmds;
    vector<string> commands;
    vector<Player*> players;
};

string menuAdjCities(City*);
string menuRSCities(vector<string>);
#endif
