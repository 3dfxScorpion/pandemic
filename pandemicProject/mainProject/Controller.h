//
// Controller class - controls the flow of pandemic
//

#include "Model.h"
#include "View.h"
#include "Menu.h"
#include<iostream>
#include<iomanip>
#include<sstream>
#include<limits>
#include<vector>
#include "Map.h"
#include "Deck.h"
#include "Player.h"
#include "PlayerMove.h"

using std::cin;
using std::cout;
using std::setw;
using std::string;
using std::streamsize;
using std::numeric_limits;
using std::ostringstream;


class Controller
{
public:
  Controller();
  void setPlayerCount();
  void setPlayerNames();
  void setDifficulty();
  void doPlayerTurns();
  void doInfectRound();
  int run();
  bool getLoadGame();
  bool getLoadScenario();
  void getSaveGame();
  void doProcessMenu(Player*);

private:
  View view;              //the view we're using
  Model model;            //the model
  Menu menu;            //the menu
  int temp;
  string tempStr;
  City* cityP;      //pointer to a city
  ICard* iCardP;      //pointer to an iCard
};
