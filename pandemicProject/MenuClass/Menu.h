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
    Menu(Map& map, vector<Player*> plyrs)
        : menuMap(map), menuPlayers(plyrs) {}

    Map& getMenuMap() { return menuMap; }
    vector<Player*> getMenuPlayers() { return menuPlayers; }
    void setMenuMap(Map& m) { menuMap = m; }
    void setMenuPlayers(vector<Player*> p) { menuPlayers = p; }
    string menuCities(Map&);
    string menuHands(vector<Player*>);

  private:
    Map menuMap;
    vector<Player*> menuPlayers;
    int numCities;
};

#endif
