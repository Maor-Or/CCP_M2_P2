
#include <string>
#include <iostream>

#include "card.hpp"

using namespace ariel;
using namespace std;

//implementing constructors
Card::Card(int number,int type) // 1 = Spades 2 = Hearts 3 = Diamonds 4 = Club
{
    this->number = number; //getting the card's number
    
    //checking for a special card
    switch (number)
    {
    case 11:
        this->isSpecialType = true;
        this->specialTypeName = "Jack";
        break;
    case 12:
        this->isSpecialType = true;
        this->specialTypeName = "Queen";
        break;
    case 13:
        this->isSpecialType = true;
        this->specialTypeName = "King";
        break;
    case 14:
        this->isSpecialType = true;
        this->specialTypeName = "Ace";
        break;
    default:
        this->isSpecialType = false;
        this->specialTypeName = "";
        break;
    }
    
    //defining the card's type
    switch (type)
    {
    case 1:
        this->type = "Spades";
        break;
    case 2:
        this->type = "Hearts";
        break;
    case 3:
        this->type = "Diamonds";
        break;
    case 4:
        this->type = "Club";
        break;
    default:
        break;
    }

}

// Card::Card(const Card &c)       //copy constructor
// {
//     this->number = c.number; //getting the card's number
    
//     //checking for a special card
//     switch (number)
//     {
//     case 11:
//         this->isSpecialType = true;
//         this->specialTypeName = "Jack";
//         break;
//     case 12:
//         this->isSpecialType = true;
//         this->specialTypeName = "Queen";
//         break;
//     case 13:
//         this->isSpecialType = true;
//         this->specialTypeName = "King";
//         break;
//     case 14:
//         this->isSpecialType = true;
//         this->specialTypeName = "Ace";
//         break;
//     default:
//         this->isSpecialType = false;
//         this->specialTypeName = "";
//         break;
//     }
    
//     //defining the card's type
//     this->type = c.type;
// }

//implementing destructors    
Card::~Card()
{
    // delete specialTypeName;
    // delete type;
}

//implementing functions
int Card::getNumber(){ return this->number;}
bool Card::getIsSpecialType(){return this->isSpecialType;}
string Card::getSpecialTypeName(){return this->specialTypeName;}
string Card::getType(){return this->type;}

//my functions:
string Card::toString(){
    return getIsSpecialType()?
    (getSpecialTypeName()+" of "+getType()):
    (to_string(getNumber())+" of "+getType());}