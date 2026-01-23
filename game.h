#ifndef     __H__GAME__
#define     __H__GAME__

#include "deck.h"
#include "player.h"


class Game {
    private:
        Deck deck;
        Player player;

    public:
        Game();
        void play();

};

#endif
