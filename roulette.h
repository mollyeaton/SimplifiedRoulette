#include <optional>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>

#ifndef ME_PROJECT2_ROULETTE_H
#define ME_PROJECT2_ROULETTE_H

class Roulette {
    //declare type definitions for optionals
    typedef std::optional<int> OptInt;
    typedef std::optional<std::string> OptString;

private:
    //declare private bet optional fields
    OptInt numBet; //places a bet on a specific number
    //OptString highLowBet = std::nullopt; //places a bet on high vs. low outcome
    //OptString oddEvenBet = std::nullopt; //places a bet on odd or even outcome
    OptString redBlackBet = std::nullopt; //places a bet on red or black outcome

    //declare the outcome field
    int roll;
    //constant vector containing all the high possibilities
    //const std::vector<int> high = {19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
    //constant vector containing all the red possibilities
    const std::vector<int> red = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};

public:
    const int numBetOdds = 35;
    const int redBlackBetOdds = 1;

    Roulette() {
        numBet = std::nullopt;
        //highLowBet = std::nullopt;
        //oddEvenBet = std::nullopt;
        redBlackBet = std::nullopt;

        roll = rollWheel();
        displayIntro();
        takeBets();

    }

    void displayIntro(){
        std::cout << "Welcome to my modified roulette game!" << std::endl;
        std::cout << "You can either place a single number bet, or a red-black bet" << std::endl;
        std::cout << "Single number bets have a 35 to 1 payout and red-black bets have a 1 to 1 payout" << std::endl;
    }

    int rollWheel(){
        //seed the random number generator
        srand(time(0));
        //return a random number between 0 and 36 which will be the roll
        return rand() % 37;
    }

    //take in user's bets for a number or red and clack bet
    void takeBets(){
        //declare temporary variables
        std::string answer;
        int inputBet;
        std::string strInputBet;
        //prompt for a single number bet
        std::cout << "Would you like to place a single number bet? (please type 'yes' or 'no') ";
        std::cin >> answer; //store the input into the variable

        //verify the bet and take in the number if they wish to make a bet
        if (verifyBetAnswer(toLower(answer))){
            std::cout << "What number would you like to bet on? (0-36)" ; //prompt user
            std::cin >> inputBet; //store the input into the variable
            //verify the validity of the number
            //continue to prompt if the number is not in the range
            while (36 < inputBet || inputBet < 0){
                std::cout << "That is not a valid bet. Please try again: " ;
                std::cin >> inputBet;
            }
            //set the optional to the bet
            setNumBet(inputBet);
        }
        else
            numBet = std::nullopt;
        std::cout << "Would you like to place a red-black bet? (please type 'yes' or 'no') ";
        std::cin >> answer;
        if (verifyBetAnswer(toLower(answer))){
            std::cout << "Red or Black? " ;
            std::cin >> strInputBet;
            strInputBet = toLower(strInputBet);
            while(strInputBet != "red" || strInputBet != "black"){
                std::cout << "That is not a valid input. Please try again: " ;
                std::cin >> strInputBet;
                strInputBet = toLower(strInputBet);
            }
            setRedBlackBet(strInputBet);
        }
        else
            redBlackBet = std::nullopt;


    }

    //verification to make sure answer is 'yes' or 'no'
    bool verifyBetAnswer(std::string input){
        //compare the answer with yes and no
        while (input!= "yes" || "no") //if it is not yes or no then keep prompting
        {
            std::cout << "That is not a valid answer. Please try again: " ;
            std::cin >> input; //take in a new input
        }
        if (input == "yes")
            return true; //return true if they do wish to make the bet
        else
            return false; //false otherwise
    }

    //convert a string to all lower case
    std::string toLower(std::string word){
        //loop through each character in the string and convert to lower
        for (char&c: word) {
            c = tolower(c);
        }
        //return the lower case word
        return word;
    }

    //setters
    void setRedBlackBet(std::string bet){
        redBlackBet = bet;
    }
    void setNumBet(int num){
        numBet = num;
    }

    //getters
    int getRoll(){
        return roll;
    }
    int getNumBet() const{
        return *numBet;
    }
    std::string getRedBlackBet() const {
        return *redBlackBet;
    }

};

#endif //ME_PROJECT2_ROULETTE_H
