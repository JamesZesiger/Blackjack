#ifndef		__H__PLAYER__
#define		__H__PLAYER__

#include "deck.h"
#include <vector>

class Player {
	private:
		std::vector<Card> hand;
	public:
		Player() = default;
		Player(std::vector<Card> dealtHand);
		std::vector<Card>& getHand();
		void addHand(Card card);
};

#endif