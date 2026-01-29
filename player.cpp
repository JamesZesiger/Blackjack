#include "player.h"
#include "deck.h"

Player::Player(){
    this->money = 100; // Starting money
    this->currentBet = 0;
}

// Hand Management
void Player::addCard(Card card){
    hand.push_back(card);
}

void Player::clearHand() {
    hand.clear();
}

int Player::handValue() {
    int total = 0;
    int numAces = 0;

    for(auto& card : hand){
        int cardValue = card.getNumber();
        if(cardValue > 10) {
            cardValue = 10;
        }

        if(cardValue == 1 && total + 11 <= 21) {
            cardValue = 11;
        }
        total += cardValue;
    }
    return total;
}

bool Player::isBust() {
    if (handValue() > 21) {
        return true;
    }

    return false;
}

bool Player::hasBlackjack() {
    if (handValue() == 21) {
        return true;
    }

    return false;
}

// Betting Methods
bool Player::placeBet(int amount) {
    if (amount > money || amount <= 0) {
        return false;
    }

    currentBet = amount;
    money -= amount;
    return true;
}

// win/lose/draw
void Player::winBet() {
    money += currentBet * 2;
}

void Player::loseBet() {
    //money -= currentBet;
}

void Player::returnBet() {
    money += currentBet;
}

// Accessors
int Player::getMoney() {
    return money;
}

int Player::getCurrentBet() {
    return currentBet;
}

std::vector<Card>& Player::getHand() {
    return hand;
}
