//
//  main.cpp
//  pandemic
//
//  Created by Jefffrey McIntire on 10/14/13.
//  Copyright (c) 2013 Jefffrey McIntire. All rights reserved.
//

#include <iostream>
#include "Player.h"
#include "mapClass.h"
#include "CityCard.h"
#include "PlayerMove.h"
void viewPlayerHand(Player player);
int main(int argc, const char * argv[])
{
    Card * newCard = new Card("testcard1",1);
    Card * newCard1 = new Card("testcard2",2);
    Card * newCard2 = new Card("testcard3",3);
    Card * miamiCard = new Card("Miami",4);
    Card * atlantaCard = new Card("Atlanta",5);
    Player *p1 = new Player("Player 1","Warlock");
    Player *p2 = new Player("player 2","priest");
    p1->addCard(newCard);
    p1->addCard(newCard2);
    p2->addCard(newCard1);
   // viewPlayerHand(*p1);
   // viewPlayerHand(*p2);
   // p1->shareKnowledge(p2, 0);
   // viewPlayerHand(*p1);
    //viewPlayerHand(*p2);
    mapClass * newMap = new mapClass();
    newMap->populateMap("/Users/jmcintire/Desktop/pandemic/pandemic/Cities1.txt");
    cityClass atlantaCity = newMap->locateCity("Atlanta");
  
    cityClass * citypointer = &atlantaCity;
    cityClass * citypointer2;
    citypointer->setResearchStation(false);
    p1->setPlayerLocation(citypointer);//player is in atlanta
    vector<string> testVector = p1->getPlayerLocation()->getAdjCity();
    
    for (int i = 0;i<=testVector.size()-1;i++)
        cout<<testVector[i]<<endl;
    PlayerMove mover;
    
    /*//Test move adjacent
    cout <<"right now p1 is located"<<p1->getPlayerLocation()->getCityName()<<endl;
    cityClass chicagoCity = newMap->locateCity("Chicago");
    citypointer2 = &chicagoCity;
    mover.setCurrentPlayer(p1);
    mover.moveAdjacent(citypointer2);
    cout <<"NOW p1 is located"<<p1->getPlayerLocation()->getCityName()<<endl;
    viewPlayerHand(*p1);
     */// end test adjavent
    viewPlayerHand(*p2);
    CityCard * redcard1 = new CityCard("redTest1",15,"red","Transyvania");
    CityCard * redcard2 = new CityCard("redTest1",17,"red","khazaksthan");
    CityCard * redcard3 = new CityCard("redTest1",18,"red","some funny country");
    CityCard * redcard4 = new CityCard("redTest1",19,"red","murica");
    CityCard * redcard5 = new CityCard("redTest1",14,"red","Transyvania again");
    
    p2->addCard(redcard1);
    p2->addCard(redcard2);
    p2->addCard(redcard3);
    p2->addCard(redcard4);
    p2->addCard(redcard5);
    viewPlayerHand(*p2);
    mover.setCurrentPlayer(p2);
    if (mover.cureDisease("red"))
        cout << "\ncure happened\n";
    viewPlayerHand(*p2);
    /*//Begin direct flight test
     
    cout <<"right now p1 is located"<<p1->getPlayerLocation()->getCityName()<<endl;
    mover.setCurrentPlayer(p1);
    p1->addCard(miamiCard);
    viewPlayerHand(*p1);
    cityClass miamiCity = newMap->locateCity("Miami");
    citypointer = &miamiCity;
    mover.directFlight(citypointer);
     cout <<"NOW p1 is located"<<p1->getPlayerLocation()->getCityName()<<endl;
    viewPlayerHand(*p1);
    
     //end Direct flight test*/
    
    
    
    /*//Begin charter flight test
     
     p1->addCard(atlantaCard);
     cout <<"right now p1 is located"<<p1->getPlayerLocation()->getCityName()<<endl;
     mover.setCurrentPlayer(p1);
     viewPlayerHand(*p1);
     cityClass SFCity = newMap->locateCity("San Francisco");
     citypointer = &SFCity;
     mover.charterFlight(citypointer);
     cout <<"NOW p1 is located"<<p1->getPlayerLocation()->getCityName()<<endl;
     viewPlayerHand(*p1);
     
    //end charter flight test*/
    
    
    /*//Start shuttle flight test
    cout <<"right now p1 is located"<<p1->getPlayerLocation()->getCityName()<<endl;
    mover.setCurrentPlayer(p1);
    cityClass SFCity = newMap->locateCity("San Francisco");
    citypointer2 = &SFCity;
    citypointer2->setResearchStation(true);
    mover.shuttleFlight(citypointer2);
    cout <<"NOW p1 is located"<<p1->getPlayerLocation()->getCityName()<<endl;
    viewPlayerHand(*p1);
    //end shuttle flight test*/
    
    
    return 0;
}

void viewPlayerHand(Player player)
{
     cout << player.getPlayerName()<<" has the cards: \n";
    for (int i =0;i<= player.getHand().size()-1;i++)
        cout<<player.getHand()[i]->getCardName()<<endl;

}