#ifndef MENU_H
#define MENU_H
#include "Card.h"
#include "Deck.h"
#include "Map.h"
#include "Menu.h"
#include "Player.h"
#include "PlayerMove.h"

using std::string;
using std::vector;

class Menu {
  public:
    Menu() {}
    Menu(Map& m, vector<Player*> p, vector<string> c)
        : map(m), players(p), commands(c) {}

    Map&            getMenuMap()      { return map;      }
    vector<Player*> getMenuPlayers()  { return players;  }
    vector<string>  getMenuCommands() { return commands; }
    void setMenuMap(Map& m)                { map      = m; }
    void setMenuPlayers(vector<Player*> p) { players  = p; }
    void setMenuCommands(vector<string> s) { commands = s; }
    string menuCities(Map&);
    string menuHands(vector<Player*>);
    string menuCommands(vector<string>);
    void showMenu();

  private:
    Map map;
    vector<string> commands;
    vector<Player*> players;
    int numCities;
};

#endif
