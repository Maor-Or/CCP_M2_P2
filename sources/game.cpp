
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <string>
#include <array>
#include <algorithm>

#include "game.hpp"
#include "card.hpp"

using namespace std;
using namespace ariel;

// constructors:
Game::Game(Player &player1, Player &player2) : player1(player1), player2(player2)
{
    allGameLog = "";
    amountOfDraws = 0;
    turnsPlayed = 0;
    p1AmountOfWins = 0;
    p2AmountOfWins = 0;

    player1.resetCardsWon();
    player2.resetCardsWon();
    player1.setStackSize(0);
    player2.setStackSize(0);
    setPlayersDecks();
}

// destructors:
// default destructor

// my added functions:
void Game::setPlayersDecks()
{

    // making a new card deck and filling it with cards
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 13; i++)
        {
            gameDeck[static_cast<std::array<Card, DECKSIZE>::size_type>((i) + j * (13))] = Card(i + 2, j + 1);
        }
    }

    // shuffling the card deck:

    // TODO: delete the old array code:
    //  int secondCard, deckStart = 0, deckEnd = 51;
    //  Card *tmp = NULL;
    //  srand(time(NULL));
    //  int random_number = 0; // Initialize the random seed

    // // repositioning all cards:
    // for (int firstCard = deckStart; firstCard <= deckEnd; firstCard++)
    // {
    //     random_number = rand() % 52; // Generate a random number between 0 and 51
    //     secondCard = random_number;

    //     // swapping cards:
    //     tmp = gameDeck[firstCard];
    //     gameDeck[firstCard] = gameDeck[secondCard];
    //     gameDeck[secondCard] = tmp;
    // }

    std::random_device rd;  // seed for the random number generator
    std::mt19937 gen(rd()); // mersenne twister engine for random numbers
    std::shuffle(gameDeck.begin(), gameDeck.end(), gen);

    // handing out the shuffled cards:
    for (int i = 0; i < 26; i++)
    {
        player1.setCardDeckAt(gameDeck[static_cast<std::array<Card, DECKSIZE>::size_type>(i)], i);
    }
    for (int i = 26; i < 52; i++)
    {
        player2.setCardDeckAt(gameDeck[static_cast<std::array<Card, DECKSIZE>::size_type>(i)], i - 26);
    }
}
void Game::roundWinner(int winnerNum)
{
    if (winnerNum == 1) // player1 won the round
    {
        lastTurnLine = lastTurnLine + " " + player1.getName() + " wins.";
        player1.incCardsWon(2);
        cout << player1.getName() << " wins." << endl;
    }
    else if (winnerNum == 2) // player2 won the round
    {
        lastTurnLine = lastTurnLine + " " + player2.getName() + " wins.";
        player2.incCardsWon(2);
        cout << player2.getName() << " wins." << endl;
    }
}
int Game::checkPlayersCards(int num1, int num2) // 0 - tie, 1 - player1 wins, 2 - player2 wins
{
    if (num1 == 2 && num2 == 14) // 2 (player1) wins over ace (player2)
        return 1;
    else if (num2 == 2 && num1 == 14) // 2 (player2) wins over ace (player1)
        return 2;
    else if (num1 == num2) // tie
        return 0;
    else if (num1 > num2) // player1 wins
        return 1;
    else // num2 > num1               // player2 wins
        return 2;
}
string Game::printRoundCardReveal()
{
    // printing the round cards reveal
    string res = player1.getName() + " played " + player1.getCardDeckAt(player1.stacksize() - 1).toString() + " " + player2.getName() + " played " + player2.getCardDeckAt(player2.stacksize() - 1).toString() + ". ";
    cout << res;
    return res;
}

// functions to implement:
void Game::playTurn()
{
    // covering extreme cases
    if (&player1 == &player2)
        throw std::runtime_error("can't play against yourself!\n");
    else if (player1.stacksize() == 0)
        throw std::runtime_error("Game is already over. Cannot play turn!\n");

    // getting the card numbers and deciding of a round winner
    int player1Num = player1.getCardDeckAt(player1.stacksize() - 1).getNumber();
    int player2Num = player2.getCardDeckAt(player2.stacksize() - 1).getNumber();

    int res = checkPlayersCards(player1Num, player2Num);

    lastTurnLine = printRoundCardReveal();

    if (res == 1) // player1 won
    {
        roundWinner(1);
        player1.setStackSize(player1.stacksize() - 1); // setting up the next card
        player2.setStackSize(player2.stacksize() - 1); // setting up the next card
        p1AmountOfWins++;
    }
    else if (res == 2) // player2 won
    {
        roundWinner(2);
        player1.setStackSize(player1.stacksize() - 1); // setting up the next card
        player2.setStackSize(player2.stacksize() - 1); // setting up the next card
        p2AmountOfWins++;
    }
    else // res == 0, tie
    {
        cout << "Draw. ";
        amountOfDraws += 1;
        lastTurnLine += "Draw. ";
        int drawPile = 0;
        bool flag = true;
        while (flag)
        {
            if (player1.stacksize() == 2) // the draw was on the one before last card for each player
            {
                player1.setStackSize(0);
                player1.incCardsWon(2 + (drawPile / 2));
                player2.setStackSize(0);
                player2.incCardsWon(2 + (drawPile / 2));
                flag = false;
            }
            else if (player1.stacksize() == 1) // the draw was on the last card for each player
            {
                player1.setStackSize(0);
                player1.incCardsWon(1 + (drawPile / 2));
                player2.setStackSize(0);
                player2.incCardsWon(1 + (drawPile / 2));
                flag = false;
            }
            else // player1.stacksize() >= 3
            {
                player1.setStackSize(player1.stacksize() - 2); // skipping one card
                player2.setStackSize(player2.stacksize() - 2); // skipping one card
                drawPile += 4;
                player1Num = player1.getCardDeckAt(player1.stacksize() - 1).getNumber();
                player2Num = player2.getCardDeckAt(player2.stacksize() - 1).getNumber();

                lastTurnLine += printRoundCardReveal();
                if (checkPlayersCards(player1Num, player2Num) == 1) // player1 won
                {
                    player1.incCardsWon(2 + (drawPile));
                    cout << player1.getName() << " wins." << endl;
                    lastTurnLine += player1.getName() + " wins.";
                    flag = false;
                    p1AmountOfWins++;
                }
                else if (checkPlayersCards(player1Num, player2Num) == 2) // player2 won
                {
                    player2.incCardsWon(2 + (drawPile));
                    cout << player2.getName() << " wins." << endl;
                    lastTurnLine += player2.getName() + " wins.";
                    flag = false;
                    p2AmountOfWins++;
                }
                else // tie
                {
                    cout << "Draw. ";
                    lastTurnLine += "Draw. ";
                    amountOfDraws += 1;
                }
            }
        }
        player1.setStackSize(player1.stacksize() - 1); // setting up the next card, if the stacksize is already 0 then nothing changes
        player2.setStackSize(player2.stacksize() - 1); // setting up the next card, if the stacksize is already 0 then nothing changes
    }
    allGameLog += lastTurnLine + "\n";
    turnsPlayed++;
}
void Game::playAll()
{
    while (player1.stacksize() != 0)
    {
        playTurn();
    }
}
void Game::printLastTurn()
{
    cout << lastTurnLine << endl;
}
void Game::printWiner()
{
    int res = player1.cardesTaken() - player2.cardesTaken();
    if (res > 0)
        cout << player1.getName() << " wins the game. " << endl;
    else if (res < 0)
        cout << player2.getName() << " wins the game. " << endl;
    else // res == 0 meaning its a tie
        cout << "game is tied, no one wins. " << endl;
}
void Game::printLog()
{
    cout << allGameLog << endl;
}
void Game::printStats()
{
    cout << "Game results:" << endl;
    printWiner();
    cout << "Turns played: " << turnsPlayed << endl;
    if (turnsPlayed == 0)// for evading dividing by 0
    {
        turnsPlayed = 1;
    } 
    cout << player1.getName() << "'s Winrate: " << int(double(p1AmountOfWins) / double(turnsPlayed) * 100) << "%" << endl;
    cout << player1.getName() << " has won " << player1.cardesTaken() << " cards." << endl;
    cout << player2.getName() << "'s Winrate: " << int(double(p2AmountOfWins) / double(turnsPlayed) * 100) << "%" << endl;
    cout << player2.getName() << " has won " << player2.cardesTaken() << " cards." << endl;
    cout << "Amount of draws: " << (amountOfDraws) << ". Draw-rate: " << int(double(amountOfDraws) / double(turnsPlayed) * 100) << "%" << endl;
}
