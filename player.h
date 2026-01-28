#ifndef		__H__PLAYER__
#define		__H__PLAYER__

#include "deck.h"
#include <vector>

class Player {
	private:
		std::vector<Card> hand;
        int money;
        int currentBet;

	public:
		Player();
        void clearHand(); // clear hand each round
        int handValue(); // calculate hand value
        bool isBust(); // check if you busted
        bool hasBlackjack(); // check for hand score of 21
        void addCard(Card card);

        // Betting methods
        bool placeBet(int amount); // places a bet
        void winBet(); // player wins
        void loseBet(); // player loses

        // Accessors
        int getMoney(); // access current amount of money
        int getCurrentBet(); // accesses current hand
		std::vector<Card>& getHand(); // Accesses players hand

};

#endif
