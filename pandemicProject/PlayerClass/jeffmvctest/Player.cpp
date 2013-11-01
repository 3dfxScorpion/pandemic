#include "Player.h"
#include "City.h"
//
//  Player.cpp
//  pandemic
//
//  Created by Jefffrey McIntire on 10/15/13.
//  
void Player::addCard(Card* _toAdd) {
    hand.push_back(_toAdd);
}

void Player::removeCard(int _toRemove) { //swaps back card with card being removed
    std::swap(hand[_toRemove],hand.back()); //and then removes the back
    hand.pop_back();

}
