#ifndef		__H__PLAYER__
#define		__H__PLAYER__

#include "deck.h"

class player {
	private:
        int money;
        int currentBet;

	public:
        // Constructor
		player();

        // money/bets interactions
        void placeBet(int amount);
        void winBet(); //add money
        void loseBet(); // reduce money
        int getMoney();
        int getCurrentBet();

        // hand actions
		void addCard();
        void clearHand();
        int getHandValue();
        bool isBust();

};
