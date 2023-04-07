
#include <string>
#include <iostream>
#include "player.hpp"
using namespace std;
using namespace ariel;

    //constructors and destructors
    Player::Player(string name)
    {
        this-> name = name;
        currentStackSize = 0;       
        cardsWon = 0;     
    }
   
    Player::~Player(){
        // for (int i = 0; i < 26; i++)
        // {
        //     delete cardDeck[i];
        // }
        
    }

    //implementing functions
    void Player::setCardDeckAt(Card *c,int ind) //setting cards in the deck
    {
        this->cardDeck[ind] = c;
        this->currentStackSize++;
        // cout << name << " currentStackSize " << currentStackSize << endl;
    }
    Card Player::getCardDeckAt(int ind)
    {
        Card &cr = *(cardDeck[ind]);
        return cr;
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


