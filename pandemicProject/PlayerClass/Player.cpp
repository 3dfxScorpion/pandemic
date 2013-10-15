//
//  Player.cpp
//  pandemic
//
//  Created by Jefffrey McIntire on 10/15/13.
//  
//

#include "Player.h"
#include "cityClass.h"

void Player::addCard(Card* _toAdd){
    
    hand.push_back(_toAdd);
    cout<<"add card happened\n";
}

void Player::removeCard(int _toRemove){//swaps the back card with the card being removed
    swap(hand[_toRemove],hand.back()); //and then removes the back
    hand.pop_back();

}
/* possibly used by MVC
void Player::shareKnowledge(Player* _who, int _toGive){

    if (_toGive<=hand.size()-1)
    _who->addCard(hand[_toGive]);
    removeCard(_toGive);
    
}

void Player::recieveKnowledge(Player* _who, int _toGet)
{
    if (_who->getHandSize()-1>=_toGet)
    hand.push_back(_who->getCard(_toGet));
    
}
*/