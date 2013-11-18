#ifndef MENU_H
#define MENU_H
#include <map>
#include "Card.h"
#include "Deck.h"
#include "Map.h"
#include "Menu.h"
#include "Player.h"
#include "Player.h"

using std::map;
using std::string;
using std::vector;

typedef void (*menuFunctions)(Player *);
class Menu {
  public:
    Menu() {}
    Menu(Map& m, vector<Player*> p, vector<string> c, vector<menuFunctions> f )
        : menuMap(m), players(p), commands(c), functions(f) {
            setMappedCommands(commands);
            setMappedFunctions(functions);
    }
    // getters
    Map&            getMenuMap()         { return menuMap;     }
    vector<Player*> getMenuPlayers()     { return players;     }
    vector<string>  getMenuCommands()    { return commands;    }
    map<int,string> getMappedCommands()  { return mappedCmds;  }
    map<int, void(*)(Player*)>
                    getMappedFunctions() { return mappedFuncs; }
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

    void setMappedFunctions(vector<menuFunctions> f) {
        size_t idx = 0;
        vector<menuFunctions>::iterator fItr = f.begin();
        for ( ; fItr != f.end(); fItr++ ) {
            mappedFuncs[idx++] = *fItr;
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
    map<int, void(*)(Player*)> mappedFuncs;
    vector<string> commands;
    vector<menuFunctions> functions;
    vector<Player*> players;
};

string menuAdjCities(City*);
#endif
