#include "game.h"
#include <iostream>
#include <string>

Game::Game() {
    Deck::shuffle(deck); //shuffles deck at start
}

void Game::dealCard(Player& p) {
    int top = 0; //keeps track of where we are in deck

    if (top > 52) {
        std::cout << "Reshuffling the deck." << std::endl;
        Deck::shuffle(deck);
        top = 0;
    }
    p.addCard(deck[top]);
    top++;
}

void Game::showHands(bool showDealerHole) {
    std::cout << "Player hand: ";
    for (auto& card : player.getHand())
        std::cout << card << " ";
    std::cout << " (" << player.handValue() << ")\n";

    std::cout << "Dealer hand: ";
    auto& dealerHand = dealer.getHand();
    if (showDealerHole) {
        for (auto& card : dealerHand)
            std::cout << card << " ";
        std::cout << " (" << dealer.handValue() << ")";
    }
    else {
        if (!dealerHand.empty())
            std::cout << dealerHand[0] << " ??"; // hides the hole card
    }
    std::cout << "\n";
}

void Game::playerTurn() {
    bool turnOver = false;
    while (!turnOver) {
        showHands(false);
        std::cout << "What will you do (hot/stand): ";
        std::string action;
        std::cin >> action;

        if (action == "hit") {
            dealCard(player);
            if (player.isBust()) {
                std::cout << "You've busted!\n";
                turnOver = true;
            }
        }
        else if (action == "stand") {
            turnOver = true;
        }
        else {
            std::cout << "Invalid action, please try again.\n";
        }
    }
}

void Game::determineWinner() {
    showHands(true);

    int playerTotal = player.handValue();
    int dealerTotal = dealer.handValue();

    if (player.isBust()) {
        std::cout << "You lose this hand!\n";
        player.loseBet();
    }
    else if (deal.isBust()) {
        std::cout << "You win this hand!\n";
    }
    else if (playerTotal < dealerTotal) {
        std::cout << "You lose this hand!\n";
    }
    else if (playerTotal > dealerTotal) {
        std::cout "You win this hand!\n";
    }
    else {
        std::cout << "You've tied this hand.\n";
    }

    std::cout << "Your current money is: $:" << player.getMoney() << "\n"
}

void Game::play() {
    while (player.getMoney() > 0) {
        player.clearHand();
        dealer.clearHand();

        int bet;
        std::cout << "You have $" << player.getMoney() << ". Please enter a bet: ";
        std::cin >> bet;

        if (!player.placeBet(bet)) {
            std::cout << "Invalid bet.\n";
        }
        
        // inital deal
        dealCard(player);
        dealCard(dealer);
        dealCard(player);
        dealCard(dealer);

        if (player.handBlackjack()) {
            std::cout << "Winner winner chicken dinner!\n";
            player.winBet();
        }

        playerTurn();
        if (!player.isBust())
            dealerTurn();

        determineWinner();

        char again;
        std::cout << "Would you like to play another hand? (y/n): ";
        std::cin >> again;
        if (cont != 'y' && cont != 'Y')
            break;

    }

    std::cout << "Game over. You've left the table with: $" << player.getMoney() << "\n";
}


