#include "player.h"

Player::Player(std::vector<Card> dealtHand){
    this->hand = dealtHand;
}
std::vector<Card>& Player::getHand(){
    return hand;
}

void Player::addHand(Card card){
    hand.push_back(card);
}