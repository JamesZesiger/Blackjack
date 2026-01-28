#include "game.h"
#include <iostream>
#include <string>

Game::Game() {
    this->deck = Deck();
    Deck::shuffle(this->deck);
    this->player = Player();
    this->dealer = Player();
}

void Game::dealCard(Player& p) {
    if (deck.getNumberOfCards() == 0) {
        std::cout << "The deck is out of cards!\n";
        deck = Deck();
        Deck::shuffle(deck);
    }
    Card dealtCard = deck[deck.getNumberOfCards() - 1];
    deck.pop_back();
    p.addCard(dealtCard);
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

void Game::dealerTurn() {
    while (dealer.handValue() < 17 || dealer.handValue() < player.handValue()) {
        dealCard(dealer);
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
    else if (dealer.isBust()) {
        std::cout << "You win this hand!\n";
        player.winBet();
        player.winBet();
    }
    else if (playerTotal < dealerTotal) {
        std::cout << "You lose this hand!\n";
        player.loseBet();
    }
    else if (playerTotal > dealerTotal) {
        std::cout << "You win this hand!\n";
        player.winBet();
        player.winBet();
    }
    else {
        std::cout << "You've tied this hand.\n";
    }

    std::cout << "Your current money is: $:" << player.getMoney() << "\n";
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
        
        if (player.hasBlackjack()) {
            std::cout << "Winner winner chicken dinner!\n";
        }

        playerTurn();
        if (!player.isBust())
            dealerTurn();

        determineWinner();

        char again;
        std::cout << "Would you like to play another hand? (y/n): ";
        std::cin >> again;
        if (again != 'y' && again != 'Y')
            break;

    }

    std::cout << "Game over. You've left the table with: $" << player.getMoney() << "\n";
}


