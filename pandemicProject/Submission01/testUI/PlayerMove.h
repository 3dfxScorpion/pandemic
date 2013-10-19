//
//  PlayerMove.h
//  pandemic
//
//  Created by Jefffrey McIntire on 10/17/13.
//  Copyright (c) 2013 Jefffrey McIntire. All rights reserved.
//

#ifndef PlayerMove_H
#define PlayerMove_H
#include "Card.h"
#include "City.h"
#include "Player.h"
#include <iostream>
class PlayerMove{
public:
    PlayerMove();
    void setCurrentPlayer(Player * _currentPlayer){currentPlayer=_currentPlayer;}
    void playOwnCard(Card*);
    void playOthCard(Card*);
    void moveToCity(City*);
    void moveAdjacent(City*);
    void charterFlight(City*);
    void directFlight(City*);
    void shuttleFlight(City*);
    void buildRStation();
    void treatDisease();
    void cureDisease(Card*);
    void shareKnowledge(Player*, Card*);
    Player * getCurrentPlayer(){return currentPlayer;}
private:
    
    Player * currentPlayer;
};

#include "PlayerMove.cpp"

#endif /* defined(__pandemic__PlayerMove__) */
