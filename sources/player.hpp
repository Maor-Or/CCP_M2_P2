#pragma once

#include "card.hpp"
#include <string>
#include <iostream>
#include <array>

using namespace std;

namespace ariel
{
    class Player
    {
    //private:
        static constexpr int PLAYER_DECKSIZE = 26;
        
        string name;          // player's name
        int currentStackSize; // the amount of cards left in the deck
        int cardsWon;         // the amount of cards won (starts on 0 for each new game)
        array<Card, PLAYER_DECKSIZE> playerDeck; // the player's card deck

    public:


        // constructors:
        Player(string name);
        
        // destructors:
        // default destructor
        
        // getters:
        string getName();
        Card getCardDeckAt(int ind); // getting the card from the player's deck

        // setters:
        void setCardDeckAt(Card &card, int ind); // inserting a card into the player's card deck
        void setStackSize(int size);

        // my added functions:
        void incCardsWon(int amount);
        void resetCardsWon();

        // functions
        int stacksize();   // prints the amount of cards left
        int cardesTaken(); // prints the amount of cards this player has won.
    };
}
