#include "player.h"

Player::Player(Deck dealtHand){
    this->hand = dealtHand;
}

Deck& Player::getHand(){
    return hand;
}

void Player::addHand(Card card){
    hand.cards.push_back(card);
}