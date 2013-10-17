#ifndef PLAYERMOVE_H
#define PLAYERMOVE_H
#include <string>
#include <vector>
#include "interfaces.h"

using std::string;
using std::vector;

class PlayerMove : public Move {
  public:
    void playOwnCard(Card*);
    void playOthCard(Card*);
    void moveToCity(City*); 
    void charterFlight(City*); 
    void directFlight(City*); 
    void shuttleFlight(City*); 
    void buildRStation(); 
    void treatDisease(); 
    void cureDisease(Card*); 
    void shareKnowledge(Card*); 
    string toString() = 0;

  private:
};

#endif

