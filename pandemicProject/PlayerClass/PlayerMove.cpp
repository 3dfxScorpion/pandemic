//
//  PlayerMove.cpp
//  pandemic
//
//  Created by Jefffrey McIntire on 10/17/13.
//  Copyright (c) 2013 Jefffrey McIntire. All rights reserved.
//



#include "PlayerMove.h"

PlayerMove::PlayerMove(){
}//default constructor


//The player moves to any city adjacent to it on the map.
void PlayerMove::moveAdjacent(cityClass* toMove){
    bool isAdj = false;
    string destination = toMove->getCityName();
    vector<string> adjCities = toMove->getAdjCity();
    for (int i = 0;i<=toMove->getNumberAdjacent();i++)  //check if the requested city is adjacent
        if (destination == adjCities[i])
            isAdj = true;                               //if adj city is found set true
    if (isAdj)
        currentPlayer->setPlayerLocation(toMove);
    else
        cout <<"Requested city is not adjacent";
    
}
//Discard a City card to move to the city named on the card.
void PlayerMove::directFlight(cityClass* toMove)
{
    bool hasCard = false;
    string destination = toMove->getCityName();
    for (int i =0;i<=currentPlayer->getHandSize()-1;i++) //size - 1 because vectors always
        if (currentPlayer->getHand()[i]->getCardName()==destination) //check players hand for the city card.
        {
            hasCard=true;//Players card was found
            currentPlayer->removeCard(i);//discard the card
            break;
        }
    if(hasCard)
        currentPlayer->setPlayerLocation(toMove);
    else
        cout<<currentPlayer->getPlayerName()<<" does not have the required card to move to "<<destination<<endl;
    
    
}
//Discard the City card that matches the city you are in to move to any city.
void PlayerMove::charterFlight(cityClass* toMove)
{
    bool hasCard = false;
    string destination = toMove->getCityName();
    for (int i =0;i<=currentPlayer->getHandSize();i++)
        if (currentPlayer->getHand()[i]->getCardName() == currentPlayer->getPlayerLocation()->getCityName()) //check players hand for the city card.
        {
            hasCard=true;//Players card was found
            currentPlayer->removeCard(i);//discard the card
            break;
        }
    if(hasCard)
        currentPlayer->setPlayerLocation(toMove);
    else
        cout<<currentPlayer->getPlayerName()<<" does not have the required card to move to "<<destination<<endl;
    
    
}
//Move from a city with a research station to any other city that has a research station.
void PlayerMove::shuttleFlight(cityClass* toMove)
{
    if (!currentPlayer->getPlayerLocation()->getResearchStationBool())//check if player is on a city with an RS
        cout<<currentPlayer->getPlayerName()<<" must be on a research station for a shuttle flight."<<endl;
    else
    {
        if (toMove->getResearchStationBool())           //Check destination city has an RS
            currentPlayer->setPlayerLocation(toMove);
        else
            cout<<"You may only shuttle flights to cities with research stations"<<endl;
    }
    
}