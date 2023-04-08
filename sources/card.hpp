#pragma once

#include <string>
#include <iostream>
using namespace std;

namespace ariel
{
    class Card
    {
        private:
        int number;             //the numeric value of the card (or it's "strength", between 2 to 14)
        bool isSpecialType;     //if the card is one of the following:
        string specialTypeName; //Jack/ Queen/ King/ Ace
        string type;            // Spades/ Hearts/ Diamonds/ Club

        public:
        //constructors and destructors
        Card(int number,int type);
        Card();

        //my added functions:
        string toString();
        //getter functions for the object's attributes
        int getNumber();
        bool getIsSpecialType();
        string getSpecialTypeName();
        string getType();

    };
    
} 
