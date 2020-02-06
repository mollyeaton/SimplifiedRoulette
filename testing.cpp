#include "roulette.h"
#include <iostream>

using namespace std;

bool testRollWheel(){
    //create game and roll the wheel
    Roulette game;

    //roll the wheel 5 times and return false if it falls outside the range
    for (int i = 0; i < 5; ++i){
        game.rollWheel();
        if (game.getRoll() > 36 || game.getRoll() < 0) {
            cout << "Error found in rollWheel" << endl;
            return false;
        }
    }

    return true;
}

bool testTakeBets(){
    //create game
    Roulette game;

    //run through the function saying yes to both bets with proper inputs and check the fields
    //run with 15 as the num bet and red as the color bet
    game.takeBets();
    if (game.getNumBet()!=15) {
        cout << "Error found in takeBets" << endl;
        return false;
    }
    if (game.getRedBlackBet() != "red") {
        cout << "Error found in takeBets" << endl;
        return false;
    }

    //run through the function saying no to num bet and yes to color bet
    //run with improper input for color bet and then make black
    game.takeBets();
    if (game.getRedBlackBet() != "black") {
        cout << "Error found in takeBets" << endl;
        return false;
    }

    //run through with yes to num bet and no to color bet and then 10 for num bet
    //run with the improper input for the num bet
    game.takeBets();
    if (game.getNumBet() != 10) {
        cout << "Error found in takeBets" << endl;
        return false;
    }

    return true;
}

bool testVerifyBetAnswer(){
    //create roulette game
    Roulette game;

    //check with yes - should return true
    if (game.verifyBetAnswer("no")) {
        cout << "Error found in testVerifyBetAnswer" << endl;
        return false;
    }
    //check with no - should return false
    if (!game.verifyBetAnswer("yes")) {
        cout << "Error found in testVerifyBetAnswer" << endl;
        return false;
    }

    //if it made it here then it has passed
    return true;
}

bool testToLower(){
    //create a game
    Roulette game;

    //test the to lower function with all caps
    if (game.toLower("YES") != "yes") {
        cout << "Error found in toLower" << endl;
        return false;
    }
    //test with some upper some lower
    if (game.toLower("yEs")!= "yes") {
        cout << "Error found in toLower" << endl;
        return false;
    }
    //test with all lower case
    if (game.toLower("yes") != "yes") {
        cout << "Error found in toLower" << endl;
        return false;
    }

    //if it made it here then it has passed
    return true;
}

bool testSetRedBlackBet(){
    //create new game
    Roulette game;

    game.setRedBlackBet("red");
    if (game.getRedBlackBet() != "red") {
        cout << "Error found in setRedBlackBet" << endl;
        return false;
    }

    game.setRedBlackBet("black");
    if (game.getRedBlackBet() != "black") {
        cout << "Error found in setRedBlackBet" << endl;
        return false;
    }

    return true;
}

bool testSetNumBet(){
    //create new game
    Roulette game;

    game.setNumBet(15);
    if (game.getNumBet() != 15) {
        cout << "Error found in setNumBet" << endl;
        return false;
    }

    return true;
}

bool testRoulette(){
    //will return true if all test functions pass
    return (testRollWheel() && testTakeBets() && testVerifyBetAnswer() && testToLower() &&
            testSetRedBlackBet() && testSetNumBet() && testRoulette());
}




