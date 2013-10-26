#ifndef PlayerMove_H
#define PlayerMove_H
//
//  PlayerMove.h
//  pandemic
//
//  Created by Jefffrey McIntire on 10/17/13.
//  Copyright (c) 2013 Jefffrey McIntire. All rights reserved.
//
#include "Card.h"
#include "City.h"
#include "Player.h"

class PlayerMove {
  public:
    PlayerMove();

    Player * getCurrentPlayer() { return currentPlayer; }
    void setCurrentPlayer(Player * _currentPlayer)
        { currentPlayer=_currentPlayer; }
    void playOwnCard(Card*);
    void playOthCard(Card*);
    void moveToCity(City*);
    void moveAdjacent(City*);
    void charterFlight(City*);
    void directFlight(City*);
    void shuttleFlight(City*);
    void buildRStation();
    void treatDisease();
    bool cureDisease(string);
    void shareKnowledge(Player*, Card*);
  private:
    Player * currentPlayer;
};

#endif /* defined(__pandemic__PlayerMove__) */
