/*
Names: James Zesiger, Jared Bradley
Date: 1/30/26
*/

#ifndef     __H__GAME__
#define     __H__GAME__

#include "deck.h"
#include "player.h"


class Game {
    private:
        Deck deck;
        Player player;
        Player dealer;
        void dealCard(Player& p); // deals top card to player
        void playerTurn(); //handles player actions
        void dealerTurn(); //handles dealer actions
        void determineWinner(); //compare hands and updates money
        void showHands(bool showDealerHole); //displays hands, can show hole card

    public:
        Game();
        void play(); // game loop

};

#endif
