#include "roulette.h"
#include <optional>
#include <iostream>
#include "time.h"
#include <string>

using namespace std;

//declare type definitions for optionals
typedef optional<int> OptInt;
typedef optional<string> OptString;


Roulette::Roulette() {
    srand((unsigned) time(0));

    numBet = nullopt;
    redBlackBet = nullopt;

}

void Roulette::displayIntro() {

        cout << "Welcome to my modified roulette game!" << endl;
        cout << "You can either place a single number bet, or a red-black bet" << endl;
        cout << "Single number bets have a 35 to 1 payout and red-black bets have a 1 to 1 payout" << endl;
        cout << "You are given $25 to begin with and the game will end once you are broke or quit" << endl;
        cout << "Good luck!" << endl;

}

int Roulette::spinWheel() {
    //return a random number between 0 and 36 which will be the spin
    spin = (rand() % 37);
    return spin;
}

void Roulette::takeBets(istream &in) {
    //declare temporary variables
    string answer;
    int inputBet;
    string strInputBet;
    //prompt for a single number bet
    cout << "Would you like to place a single number bet? (please type 'yes' or 'no') ";
    in >> answer; //store the input into the variable

    //verify the bet and take in the number if they wish to make a bet
    if (verifyBetAnswer(toLower(answer), cin)){
        cout << "What number would you like to bet on? (0-36) " ; //prompt user
        in >> inputBet; //store the input into the variable
        //verify the validity of the number
        //continue to prompt if the number is not in the range
        while (36 < inputBet || inputBet < 0 || in.fail()) {
            in.clear();
            in.ignore(256,'\n');
            cout << "That is not a valid bet. Please try again: " ;
            in >> inputBet;
        }
        //set the optional to the bet
        setNumBet(inputBet);
    }
    else
        numBet = nullopt;
    cout << "Would you like to place a red-black bet? (please type 'yes' or 'no') ";
    in >> answer;
    if (verifyBetAnswer(toLower(answer), cin)){
        cout << "Red or Black? " ;
        in >> strInputBet;
        strInputBet = toLower(strInputBet);
        while(strInputBet != "red" && strInputBet != "black"){
            cout << "That is not a valid input. Please try again: " ;
            in >> strInputBet;
            strInputBet = toLower(strInputBet);
        }
        setRedBlackBet(strInputBet);
    }
    else
        redBlackBet = nullopt;
}

bool Roulette::verifyBetAnswer(string input, istream &in) {
    //compare the answer with yes and no
    while (input!= "yes" && input != "no") //if it is not yes or no then keep prompting
    {
        cout << "That is not a valid answer. Please try again: " ;
        in >> input; //take in a new input
    }
    if (input == "yes")
        return true; //return true if they do wish to make the bet
    else
        return false; //false otherwise
}

string Roulette::toLower(string word) {
    //loop through each character in the string and convert to lower
    for (char&c: word) {
        c = tolower(c);
    }
    //return the lower case word
    return word;
}

void Roulette::setRedBlackBet(string bet) {
    redBlackBet = bet;
}

void Roulette::setNumBet(int num) {
    numBet = num;
}

int Roulette::getSpin() const{
    return spin;
}

int Roulette::getNumBetValue() const {
    return *numBet;
}

string Roulette::getRedBlackBetValue() const {
    return *redBlackBet;
}

OptInt Roulette::getNumBet() const {
    return numBet;
}

OptString Roulette::getRedBlackBet() const {
    return redBlackBet;
}


