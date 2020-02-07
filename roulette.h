#include <optional>
#include <iostream>


#ifndef ME_PROJECT2_ROULETTE_H
#define ME_PROJECT2_ROULETTE_H

class Roulette {
    //declare type definitions for optionals
    typedef std::optional<int> OptInt;
    typedef std::optional<std::string> OptString;

private:
    //declare private bet optional fields
    OptInt numBet = std::nullopt; //places a bet on a specific number
    OptString redBlackBet = std::nullopt; //places a bet on red or black outcome

    //declare the outcome field
    int spin;

public:
    //default constructor
    /**
    * Requires: nothing
    * Modifies: makes bets null
    * Effects:  displays the intro message and resets bets
    */
    Roulette();

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects:  displays beginning message and info
    */
    void displayIntro();

    /**
    * Requires: nothing
    * Modifies: spin
    * Effects:  "spins" the wheel and chooses a random number
    */
    int spinWheel();

    /**
    * Requires: input stream
    * Modifies: numBet, redBlackBet
    * Effects:  prompts user for both types of bets, verifies input and
    *   updates the bets accordingly
    */
    void takeBets(std::istream & in);

    /**
    * Requires: string input, and input stream
    * Modifies: nothing
    * Effects:  determines if the yes/no answer was valid. will continue
    *   to prompt if not
    */
    bool verifyBetAnswer(std::string input, std::istream& in);

    /**
    * Requires: string word
    * Modifies: word passed through parameter
    * Effects:  converts all of the letters in the word to lowercase
    */
    std::string toLower(std::string word);

    //setters
    /**
    * Requires: string bet
    * Modifies: redBlackBet
    * Effects:  changes the red-black bet to the parameter
    */
    void setRedBlackBet(std::string bet);

    /**
    * Requires: int num
    * Modifies: numBet
    * Effects:  changes the numBet to the parameter
    */
    void setNumBet(int num);

    //getters
    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects:  returns the value of the current spin
    */
    int getSpin() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects:  returns the value of the current num bet
    */
    int getNumBetValue() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects:  returns the value of the current red-black bet
    */
    std::string getRedBlackBetValue() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects:  returns the numBet optional (whether there is a bet or not)
    */
    OptInt getNumBet() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects:  returns the redBlackBet optional (whether there is a bet or not)
    */
    OptString getRedBlackBet() const;

};

#endif //ME_PROJECT2_ROULETTE_H
