#ifndef INTERFACES_H
#define INTERFACES_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class Move
{
  public:
    virtual void playOwnCard(Card*) const = 0;
    virtual void playOthCard(Card*) const = 0;
    virtual void moveToCity(City*) const = 0; 
    virtual void charterFlight(City*) const = 0; 
    virtual void directFlight(City*) const = 0; 
    virtual void shuttleFlight(City*) const = 0; 
    virtual void buildRStation() const = 0; 
    virtual void treatDisease() const = 0; 
    virtual void cureDisease(Card*) const = 0; 
    virtual void shareKnowledge(Card*) const = 0; 
    virtual string toString() = 0;
};

class GameState
{
  public:
    virtual bool coordCheck(string) = 0;
    virtual int  getPlayer() const = 0;
    virtual int  getWinner() const = 0;
    virtual int  placeMove(string*, string, int) = 0;
    virtual List<City*> getCities() = 0;
    virtual string  ToString() = 0;
    virtual GameState* nextState(Move*) = 0;
};

#endif

