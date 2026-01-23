#ifndef		__H__PLAYER__
#define		__H__PLAYER__

#include "deck.h"

class Player {
	private:
		Deck hand;
	public:
		Player() = default;
		Player(Deck dealtHand);
		Deck& getHand();
		void addHand(Card card);
};

#endif