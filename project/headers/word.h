////////////////////////////////////////
// May 20th, 2022
// CS-172-1 - Final Project
//
// License: Copyright © 2022 Fabian Gomez
// License: Copyright © 2022 Matheus M Silva
// License: Copyright © 2022 Quentin Swett
//
// Word Class Header
////////////////////////////////////////

#ifndef WORD_H
#define WORD_H

#include <iostream>
using namespace std;

// Goal of this this class is to represent a word and the time it appear
// Imagine you want to know how many time does the word because appear in an essay
class WORD
{
private:
    // Atributes
    string _word; // What's the word
    float _score; // How many times it repeat
    
public:
    // Methods
    
    // Default Constructor
    WORD();

    WORD(string s);

    // Arg. Constructor
    // Input: A single word and the time it occurrs in the file
    WORD(string w, float s);

    //Method to add scores from a certain word
    void addS();

    // Method to divide the score by the number of occurrences
    void update_score(int total);

    // Operator==: compare a word to the words in this class
    bool operator==(string s);

    // Operator==: compare a word from a word class to the other word in this class
    bool operator==(WORD w);

    // Operator>: compare a score from a word class to the other score in this class
    bool operator>(WORD w);

    // Utility to get the word
    // Return the word
    string getWord();

    // Utility to get the count
    // Return the count
    float getCount();

    //Operator<<: out stream operator
    friend ostream &operator<<(ostream &out, WORD &w);
};

#endif