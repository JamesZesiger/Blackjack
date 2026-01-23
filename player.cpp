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

int Player::handValue(){
    int total = 0;
    for(auto& card : hand){
        int cardValue = card.getNumber();
        if(cardValue > 10){
            cardValue = 10;
        }
        if(cardValue == 1 && total + 11 <= 21){
            cardValue = 11;
        }
        total += cardValue;
    }
    return total;
}
