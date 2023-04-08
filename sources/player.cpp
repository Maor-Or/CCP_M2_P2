
#include <string>
#include <iostream>
#include <array>

#include "player.hpp"
using namespace std;
using namespace ariel;

    //constructor:
    Player::Player(string name)
    {
        this-> name = name;
        currentStackSize = 0;       
        cardsWon = 0;     
    }
    
    //destructors:
    //default destructor

    //my added functions:
    void Player::setCardDeckAt(Card &c,int ind) //adding a card to the player's deck
    {
        this->playerDeck[static_cast<std::array<Card, PLAYER_DECKSIZE>::size_type>(ind)] = c;
        this->currentStackSize++;
    }
    Card Player::getCardDeckAt(int ind) //getting the card in the ind position from the player's deck
    {
        return (playerDeck[static_cast<std::array<Card, PLAYER_DECKSIZE>::size_type>(ind)]);
    } 
    string Player::getName(){return this->name;}
    void Player::setStackSize(int size)
    {
        currentStackSize = size;
        if(currentStackSize < 0) currentStackSize = 0; //for avoiding out of bounds
    }
    void Player::incCardsWon(int amount){cardsWon+=amount;}
    void Player::resetCardsWon(){cardsWon = 0;}

    //assignment functions
    int Player::stacksize(){return this->currentStackSize;} //prints the amount of cards left
    int Player::cardesTaken(){return this->cardsWon;}       // prints the amount of cards this player has won 


