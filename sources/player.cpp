
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

    //implementing functions
    void Player::setCardDeckAt(Card &c,int ind) //setting cards in the deck
    {
        this->playerDeck[static_cast<std::array<Card, PLAYER_DECKSIZE>::size_type>(ind)] = c;
        this->currentStackSize++;
        // cout << name << " currentStackSize " << currentStackSize << endl;
    }
    Card Player::getCardDeckAt(int ind)
    {
        return (playerDeck[static_cast<std::array<Card, PLAYER_DECKSIZE>::size_type>(ind)]);
    } 
    string Player::getName(){return this->name;}
    void Player::setStackSize(int size)
    {
        currentStackSize = size;
        if(currentStackSize< 0) currentStackSize = 0; 
    }
    void Player::incCardsWon(int amount){cardsWon+=amount;}
    void Player::resetCardsWon(){cardsWon = 0;}

    //assignment functions
    int Player::stacksize(){return this->currentStackSize;} //prints the amount of cards left
    int Player::cardesTaken(){return this->cardsWon;}       // prints the amount of cards this player has won 


