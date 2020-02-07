#include "roulette.h"
#include <iostream>
#include <optional>
#include <vector>
#include <string>


using namespace std;

int main()
{
    //pointer to hold temporary color
    auto tempColor = make_unique<string> ("");
    //pointer to hold bankAmount
    auto bankAmount = make_unique<int> (25);
    //constant vector containing all the red possibilities
    const vector<int> red = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    //create variable so player can exit the game
    string exitAnswer;

    //create new roulette game and display message
    Roulette game;
    game.displayIntro();

    //continue the game while the player still has money
    while(*bankAmount > 0)
    {
        //spin the wheel and take the player's bets
        game.spinWheel();
        game.takeBets(cin);

        //display the spin and check whether number is a red or black slot
        cout << "SPINNING THE WHEEL" << endl;
        cout << "The spin was " << game.getSpin();
        if (count(red.begin(), red.end(), game.getSpin())) {
            cout << " Red" << endl;
            *tempColor = "red";
        }
        else {
            cout << " Black" << endl;
            *tempColor = "black";
        }

        //will return true if there is a bet
        if (game.getNumBet()) {
            //add money to bank if the guess was correct
            if (game.getNumBetValue() == game.getSpin()) {
                cout << "Your single number bet of was correct!" << endl;
                *bankAmount += 175;
            }
            //otherwise subtract the bet
            else {
                cout << "Your single number was was a miss." << endl;
                *bankAmount -= 5;
            }
        }

        //will return true if there is a bet
        if (game.getRedBlackBet()) {
            //add to the bank if the guess was correct
            if(*tempColor == game.getRedBlackBetValue()){
                cout << "Your red-black bet was correct!" << endl;
                *bankAmount += 5;
            }
            //otherwise subtract the bet
            else {
                cout << "Your red-black bet was a miss." << endl;
                *bankAmount -= 5;
            }

        }
        //display the current bank balance
        cout << "Your current bank balance is: $" << *bankAmount << endl;

        //prompt the user if they'd like to keep playing
        cout << "Keep playing? (enter 'X' to exit) ";
        cin >> exitAnswer;
        //if they answered 'X' then exit the game
        if (exitAnswer == "X")
            exit(0);

        //otherwise clear the input stream and continue
        exitAnswer.clear();
    }

    cout << "Sorry you have run out of money!" << endl;

    return 0;
};
