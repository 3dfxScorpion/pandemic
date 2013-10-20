//
//  Player.h
//  pandemic
//
//  Created by Jefffrey McIntire on 10/14/13.
//  Copyright (c) 2013 Jefffrey McIntire. All rights reserved.
//


//#inlcude <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "cityClass.h"
using namespace std;
#ifndef Player_h
#define Player_h

class Player{
private:
    string playerName;
    string playerRole;
    cityClass * location;
    vector<Card*> hand;
    Card* getCard(int _toGet){return hand[_toGet];}
    void removeCard(int _toRemove);
public:
    Player(string _name, string _role){playerName = _name; playerRole = _role;}
    Player(){playerName = "default";playerRole = "default";}
    void setPlayerName(string _name);
    void setPlayerRole(string _role){playerRole = _role;}
    string getPlayerRole(){return playerRole;}
    string getPlayerName(){return playerName;}
    cityClass * getPlayerLocation(){return location;}
    void setPlayerLocation(cityClass * _location);   //Most likely helper function
    vector<Card*> getHand(){return hand;}
    
    int getHandSize(){return (int)hand.size();}      //get the size of the a players hand.
    /*
     * TO DO-Figure out if we are using city Name to identify, or an ID #
     */
    void moveAdjacent(string cityName);
    void charterFlight(string cityName);
    void discard(int);                               //use the int to index and remove from hand vector
    void addCard(Card* _toAdd);                      //Helper function for Share knowledge and draw card
    void drawCard(Card* _toAdd);                      //draw a card from the deck
    /*============================================================*
     *+++++++++++++++shareKnowledge(Player,int)++++++++++++++++++++
     *      First argument is the player you wish to share
     *      a card with.
     *
     *      Second argument is used to index the players hand
     *
     *============================================================*/
    void shareKnowledge(Player * _who, int _toGive);
    /*============================================================*
     *+++++++++++++++recieveKnowledge(Player,int)++++++++++++++++++++
     *      
     *      First argument is the player you wish to share
     *      a card with.
     *
     *      Second argument is the card requested
     *
     *============================================================*/
    void recieveKnowledge(Player * _who, int _toGet); //recieve a card from another player
};


#endif
