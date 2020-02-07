#include "roulette.h"
#include <iostream>

using namespace std;

bool testSpinWheel(){
    //create game and roll the wheel
    Roulette game;

    cout << "TESTING SPIN WHEEL" << endl;

    //roll the wheel 5 times and return false if it falls outside the range
    for (int i = 0; i < 5; ++i){
        game.spinWheel();
        if (game.getSpin() > 36 || game.getSpin() < 0) {
            cout << "Error found in spinWheel" << endl;
            return false;
        }

    }
    //if the two spins are equal then the random number generator is not working
    if (game.spinWheel() == game.spinWheel()) {
        cout << "Error found in spinWheel random number generator" << endl;
        return false;
    }

    return true;
}

bool testTakeBets(){
    //create game
    Roulette game;

    cout << "TESTING TAKE BETS" << endl;

    //run through the function saying yes to both bets with proper inputs and check the fields
    //run with 15 as the num bet and red as the color bet
    cout << "run with 15 and red" << endl;
    game.takeBets(cin);
    if (game.getNumBetValue()!=15) {
        cout << "Error found in takeBets" << endl;
        return false;
    }
    if (game.getRedBlackBetValue() != "red") {
        cout << "Error found in takeBets" << endl;
        return false;
    }

    //run through the function saying no to num bet and yes to color bet
    //run with improper input for color bet and then make black
    cout << "run with no num bet and black" << endl;
    game.takeBets(cin);
    if (game.getRedBlackBetValue() != "black") {
        cout << "Error found in takeBets" << endl;
        return false;
    }

    //run through with yes to num bet and no to color bet and then 10 for num bet
    //run with the improper input for the num bet
    cout << "run with 10 and test invalid inputs" << endl;
    game.takeBets(cin);
    if (game.getNumBetValue() != 10) {
        cout << "Error found in takeBets" << endl;
        return false;
    }

    return true;
}

bool testVerifyBetAnswer(){
    //create roulette game
    Roulette game;

    cout << "TESTING VERIFY BET ANSWER" << endl;

    //check with yes - should return true
    if (game.verifyBetAnswer("no", cin)) {
        cout << "Error found in testVerifyBetAnswer" << endl;
        return false;
    }
    //check with no - should return false
    if (!game.verifyBetAnswer("yes", cin)) {
        cout << "Error found in testVerifyBetAnswer" << endl;
        return false;
    }

    //if it made it here then it has passed
    return true;
}

bool testToLower(){
    //create a game
    Roulette game;

    cout << "TESTING TO LOWER" << endl;

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

    cout << "TESTING SET RED BLACK BET" << endl;

    //set the variable to 'red'
    game.setRedBlackBet("red");
    //if they are not equal there is an error
    if (game.getRedBlackBetValue() != "red") {
        cout << "Error found in setRedBlackBet" << endl;
        return false;
    }
    //set the variable to 'black'
    game.setRedBlackBet("black");
    //if they are not equal there is an error
    if (game.getRedBlackBetValue() != "black") {
        cout << "Error found in setRedBlackBet" << endl;
        return false;
    }

    return true;
}

bool testSetNumBet(){
    //create new game
    Roulette game;

    cout << "TESTING SET NUM BET" << endl;

    //set the numBet variable to 15
    game.setNumBet(15);
    //if the variable is not equal then there is an error
    if (game.getNumBetValue() != 15) {
        cout << "Error found in setNumBet" << endl;
        return false;
    }

    return true;
}

bool testRoulette(){
    //will return true if all test functions pass
    return (testSpinWheel() && testTakeBets() && testVerifyBetAnswer() && testToLower() &&
            testSetRedBlackBet() && testSetNumBet());
}

int main()
{
    if (testRoulette()){
        cout << "All test cases have passed" << endl;
    }
};




