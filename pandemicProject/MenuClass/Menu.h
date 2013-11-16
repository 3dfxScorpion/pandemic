#ifndef MENU_H
#define MENU_H
#include <map>
#include "Card.h"
#include "Deck.h"
#include "Map.h"
#include "Menu.h"
#include "Player.h"
#include "PlayerMove.h"

using std::map;
using std::string;
using std::vector;

typedef void (*menuFunctions)(PlayerMove *);
class Menu {
  public:
    Menu() {}
    Menu(Map& m, vector<Player*> p, vector<string> c, vector<menuFunctions> f )
        : menuMap(m), players(p), commands(c), functions(f) {
            setMappedCommands(commands);
            setMappedFunctions(functions);
    }

    Map&            getMenuMap()         { return menuMap;     }
    vector<Player*> getMenuPlayers()     { return players;     }
    vector<string>  getMenuCommands()    { return commands;    }
    map<int,string> getMappedCommands()  { return mappedCmds;  }
    map<int, void(*)(PlayerMove*)>
                    getMappedFunctions() { return mappedFuncs; }

    void setMenuMap(Map& m)                { menuMap  = m; }
    void setMenuPlayers(vector<Player*> p) { players  = p; }
    void setMenuCommands(vector<string> s) { commands = s; }

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

    string menuCities(Map&);
    string menuHands(vector<Player*>);
    string menuCommands(vector<string>);
    void processMenu();
    void showMenu();

  private:
    Map menuMap;
    map<int,string> mappedCmds;
    map<int, void(*)(PlayerMove*)> mappedFuncs;
    vector<menuFunctions> menuFuncs;
    vector<string> commands;
    vector<menuFunctions> functions;
    vector<Player*> players;
    int numCities;
};

string menuAdjCities(City*);
#endif
