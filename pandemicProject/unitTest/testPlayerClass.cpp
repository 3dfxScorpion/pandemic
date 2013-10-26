#include <iostream>
#include "Player.h"
#include "Map.h"
#include "PlayerMove.h"
#include "Test.h"
//
//  main.cpp
//  pandemic
//
//  Created by Jefffrey McIntire on 10/14/13.
//  Copyright (c) 2013 Jefffrey McIntire. All rights reserved.
//
void viewPlayerHand(Player player);

class TestPlayerMove : public TestSuite::Test {
  public:
    void run() {
        Card * newCard     = new Card(1, "testcard1");
        Card * newCard1    = new Card(2, "testcard2");
        Card * newCard2    = new Card(3, "testcard3");
        Card * miamiCard   = new Card(4, "Miami");
        Card * atlantaCard = new Card(5, "Atlanta");

    /* BEGIN Test Card creations */
        test_( newCard->getCardName()   == "testcard1" );
        test_( newCard1->getCardName()  == "testcard2" );
        test_( newCard2->getCardName()  == "testcard3" );
        test_( miamiCard->getCardName() == "Miami" );
    /* END Test Card creations */

        Player *p1 = new Player("Player 1","Warlock");
        Player *p2 = new Player("Player 2","Priest");
        Player *p3 = new Player("Player 3","Warrior");
        Player *p4 = new Player("Player 4","Mage");
    /* BEGIN Test Player creations */
        test_( p1->getPlayerName() == "Player 1" );
        test_( p1->getPlayerRole() == "Warlock" ); 
        test_( p2->getPlayerName() == "Player 2" );
        test_( p2->getPlayerRole() == "Priest" );
    /* END Test Player creations */

        p1->addCard(newCard);
        p1->addCard(newCard2);
        p2->addCard(newCard);
        p2->addCard(newCard2);
        p3->addCard(newCard);
        p3->addCard(newCard2);
        p4->addCard(newCard);
        p4->addCard(newCard2);

        Map * newMap = new Map();
        newMap->populateMap("/Users/jmcintire/Desktop/CodeCleanup/Cities.txt");
        City * atlantaCity = newMap->locateCity("Atlanta");

        atlantaCity->setResearchStation(false);
        p1->setPlayerLocation(atlantaCity);//player is in atlanta
        p2->setPlayerLocation(atlantaCity);
        p3->setPlayerLocation(atlantaCity);
        p4->setPlayerLocation(atlantaCity);
        vector<string> testVector = p1->getPlayerLocation()->getAdjCity();

        for ( int i = 0; i <= testVector.size() - 1; i++ )
            cout << testVector[i] << endl;

        PlayerMove mover;

    /* BEGIN Test Player move */
        cout << "right now p1 is located in "
             << p1->getPlayerLocation()->getCityName()
             << endl;
        test_( p1->getPlayerLocation()->getCityName() == "Atlanta" );
        City * chicagoCity = newMap->locateCity("Chicago");
        mover.setCurrentPlayer(p1);
        mover.moveAdjacent(chicagoCity);
        cout << "NOW p1 is located in "
             <<p1->getPlayerLocation()->getCityName() << endl;
        test_( p1->getPlayerLocation()->getCityName() == "Chicago" );
        viewPlayerHand(*p1);
    /* END Test Player move */


        //Start shuttle flight test
         
         cout << "right now p2 is located in "
              << p2->getPlayerLocation()->getCityName()
              << endl;
         mover.setCurrentPlayer(p2);
         City * SFCity = newMap->locateCity("San Francisco");
         SFCity->setResearchStation(true);
         mover.shuttleFlight(SFCity);
         cout << "NOW p1 is located in "
              << p2->getPlayerLocation()->getCityName()
              << endl;
         viewPlayerHand(*p2);
         //end shuttle flight test*/

      //Begin direct flight test

        cout << "right now p3 is located in "
             << p3->getPlayerLocation()->getCityName()
             << endl;
        test_( p3->getPlayerLocation()->getCityName() == "Atlanta" );
        mover.setCurrentPlayer(p3);
        p3->addCard(miamiCard);
        viewPlayerHand(*p3);
        City * miamiCity = newMap->locateCity("Miami");
        mover.directFlight(miamiCity);
         cout << "NOW p3 is located in "
              << p3->getPlayerLocation()->getCityName()
              << endl;
        test_( p3->getPlayerLocation()->getCityName() == "Miami" );
        viewPlayerHand(*p3);

      //end Direct flight test*/
        
      //Begin charter flight test
        p4->addCard(atlantaCard);
        cout << "right now p4 is located in "
             << p4->getPlayerLocation()->getCityName()
             << endl;
        test_( p4->getPlayerLocation()->getCityName() == "Atlanta" );
        mover.setCurrentPlayer(p4);
        viewPlayerHand(*p4);
        mover.charterFlight(SFCity);
        cout << "NOW p4 is located in "
             << p4->getPlayerLocation()->getCityName()
             << endl;
        test_( p4->getPlayerLocation()->getCityName() == "San Francisco" );
        viewPlayerHand(*p4);
     
      //end charter flight test*/




    }
};

int main(int argc, const char * argv[]) {
    TestPlayerMove t;
    t.run();
    t.report();
    return 0;
}

void viewPlayerHand(Player player) {
    cout << player.getPlayerName() << " has the cards: \n";
    for ( int i =0; i <= player.getHand().size() - 1; i++ )
        cout << player.getHand()[i]->getCardName() << endl;
}
