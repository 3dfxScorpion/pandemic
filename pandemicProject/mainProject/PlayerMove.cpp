#include<iostream>
#include "PlayerMove.h"
#include "CityCard.h"
#include "model.h"
#include <string>
//
//  PlayerMove.cpp
//  pandemic
//
//  Created by Jefffrey McIntire on 10/17/13.
//  Copyright (c) 2013 Jefffrey McIntire. All rights reserved.
//

using std::cout;
using std::endl;

PlayerMove::PlayerMove() {} // default constructor to keep my compiler happy.

//The player moves to any city adjacent to it on the map.
void PlayerMove::moveAdjacent(City* toMove) {
    bool isAdj = false;
    string destination = toMove->getCityName();
    vector<string> adjCities = currentPlayer->getPlayerLocation()->getAdjCity();
    //check if the requested city is adjacent
    for ( int i = 0; i <= toMove->getNumberAdjacent(); i++ ) {
        if ( destination == adjCities[i] ) {
            isAdj = true;  // if adj city is found set true
            break;         // found the city, no need to loop further.
        }
    }
    if ( isAdj )
    {
       /* if (this->getCurrentPlayer()->getPlayerRole()=="Medic")
            if ( toMove->getInfectedBool())
                if (toMove->getInfectedBlack()>=0 && */
        currentPlayer->setPlayerLocation(toMove);
        
    }
    else
        cout << "Requested city is not adjacent";
    
}

//Discard a City card to move to the city named on the card.
void PlayerMove::directFlight(City* toMove) {
    string destination = toMove->getCityName();
    if (canDirectFlight(toMove)){
        for ( int i = 0; i <= currentPlayer->getHandSize() - 1; i++ ) {
            // check players hand for the city card.
            if ( currentPlayer->getHand()[i]->getCardName() == destination ) {
                currentPlayer->removeCard(i);  // discard that card
                currentPlayer->setPlayerLocation(toMove);
            }
        }
    }
    else
        cout << currentPlayer->getPlayerName()
        << " does not have the required card to move to "
        << destination << endl;
}


bool PlayerMove::canDirectFlight(City* toMove){
    string destination = toMove->getCityName();
    for ( int i = 0; i <= currentPlayer->getHandSize() - 1; i++ ) {
        // check players hand for the city card.
        if ( currentPlayer->getHand()[i]->getCardName() == destination ) {
            return true;
        }
    }
    return false;
    
}

//Discard the City card that matches the city you are in to move to any city.
void PlayerMove::charterFlight(City* toMove) {
    string destination = toMove->getCityName();
    if (canCharterFlight(toMove)){
        for ( int i = 0; i <= currentPlayer->getHandSize() - 1; i++ ) {
            //check players hand for the city card.
            if ( currentPlayer->getHand()[i]->getCardName() ==
                currentPlayer->getPlayerLocation()->getCityName() ) {
                currentPlayer->removeCard(i);  //discard the card
                currentPlayer->setPlayerLocation(toMove);
            }
        }
    }
    else
    {
        cout << currentPlayer->getPlayerName()
        << " does not have the required card to move to "
        << destination << endl;
    }
    
}

bool PlayerMove::canCharterFlight(City* toMove){
    string destination = toMove->getCityName();
    for ( int i = 0; i <= currentPlayer->getHandSize() - 1; i++ ) {
        //check players hand for the city card.
        if ( currentPlayer->getHand()[i]->getCardName() ==
            currentPlayer->getPlayerLocation()->getCityName() ) {
            return true;                //Players card was found
            
        }
    }
    
    return false;
}





//Move from city with research station to any other city that has research station.
void PlayerMove::shuttleFlight(City* toMove) {
    //check if player is on a city with an RS
    if (canShuttleFlight(toMove))
    currentPlayer->setPlayerLocation(toMove);
    
}

bool PlayerMove::canShuttleFlight(City* toMove){
    if ( !currentPlayer->getPlayerLocation()->getResearchStationBool())
    {
        cout << currentPlayer->getPlayerName()
             << " must be on a research station for a shuttle flight." << endl;
        return false;
    }
    else {
        if (toMove->getResearchStationBool())  //Check destination city has an RS
            return true;
        else
        {
            cout << "You may only shuttle flights to cities with research stations" << endl;
            return false;
        }
    }
}

void PlayerMove::shareKnowledge(Player* _who, Card* _toGive) {
    for ( int i = 0; i <= currentPlayer->getHandSize() - 1; i++ ) {
        if ( currentPlayer->getHand()[i]->getCardName() ==
            currentPlayer->getPlayerLocation()->getCityName() ) {
            _who->addCard(currentPlayer->getHand()[i]);//add card to other palyers hand
            currentPlayer->removeCard(i);//remove the card from your hand
        }
    }
}

bool PlayerMove::cureDisease(string color){//This will be updated later when we have a bit more user input.
    int colorNum=0;                        //We will need to ask which 5 cards a player wants to discard
    vector<int> toRemove;                   //if they have more than 5 cards of the same color.
    CityCard * cityCaster;
    for (int i = 0; i <= currentPlayer->getHandSize()-1;i++){
        cityCaster=(CityCard*)currentPlayer->getHand()[i];   //hopefully its not too dangerous to cast like this, RTTI MAY BE REQUIRED
        if (color == cityCaster->getColor())                 //wtb instanceof
        {
            toRemove.push_back(i);
            colorNum++;
        }
        if (colorNum>=5){
            //Right here I would call the cureDisease function in Darrens CureStatusIdeas.cpp
            for (int k =0;k<=toRemove.size()-1;k++)
                currentPlayer->removeCard(toRemove[k]);//discard the 5 city cards.
            return true;
        }
    }
    return false;
    
    
}
//Accepts a color as parameter, decrements by one.
//DOES NOT CHECK IF THERE ARE 0 CUBES, that should be handled by controller.
void PlayerMove::treatDisease(int col){
       City* toTreat = currentPlayer->getPlayerLocation();
    switch(col){
        case blue:
            if (currentPlayer->getPlayerRole() == "Medic") //if medic, remove all cubes.
                toTreat->setInfectedBlue(0);
            else
            toTreat->setInfectedBlue(toTreat->getInfectedBlue()-1);//decrement by 1
            break;
        case black:
            if (currentPlayer->getPlayerRole() == "Medic")
                toTreat->setInfectedBlack(0);
            else
            toTreat->setInfectedBlack(toTreat->getInfectedBlack()-1);
            break;
        case yellow:
            if (currentPlayer->getPlayerRole() == "Medic")
                toTreat->setInfectedYellow(0);
            else
             toTreat->setInfectedYellow(toTreat->getInfectedYellow()-1);
            break;
        case red:
            if (currentPlayer->getPlayerRole() == "Medic")
                toTreat->setInfectedRed(0);
            else
             toTreat->setInfectedRed(toTreat->getInfectedRed()-1);
    }
}