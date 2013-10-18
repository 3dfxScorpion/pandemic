//
//  Player.cpp
//  pandemic
//
//  Created by Jefffrey McIntire on 10/15/13.
//  
//

#include "Player.h"
#include "City.h"

void Player::addCard(Card* _toAdd){
    
    hand.push_back(_toAdd);
}

void Player::removeCard(int _toRemove){//swaps the back card with the card being removed
    swap(hand[_toRemove],hand.back()); //and then removes the back
    hand.pop_back();

}
/* possibly used by MVC


void Player::recieveKnowledge(Player* _who, int _toGet)
{
    if (_who->getHandSize()-1>=_toGet)
    hand.push_back(_who->getCard(_toGet));
    
}
*/
