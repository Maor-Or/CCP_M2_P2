#pragma once

#include <array>
#include <iostream>
#include "player.hpp"

using namespace std;


namespace ariel{
    class Game
    {
        //private:

        static constexpr int DECKSIZE = 52;

        Player &player1, &player2;
        array<Card,DECKSIZE> gameDeck;
        string lastTurnLine;            //log for each turn
        string allGameLog;              //log for the entire game
        
        //for following stats:
        int amountOfDraws;              
        int turnsPlayed;                
        int p1AmountOfWins;             
        int p2AmountOfWins;

        public:

            //constructors:
            Game(Player &player1,Player &player2);
            
            //destructors:
            //default destructor

            //my added functions:
            void setPlayersDecks();                      //the game distributes it's card to the players when a new game starts
            void roundWinner(int winnerNum);             //when one of the players wins a round, some actions are needed
            int checkPlayersCards(int num1, int num2);
            string printRoundCardReveal();    

            //functions to implement:
            void printLastTurn();
            void playTurn(); 
            void playAll();     //playes the game untill the end
            void printWiner();  // prints the name of the winning player
            void printLog();    // prints all the turns played one line per turn (same format as game.printLastTurn())
            void printStats();  // for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )


    };
}