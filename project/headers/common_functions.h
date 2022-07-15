////////////////////////////////////////
// May 20th, 2022
// CS-172-1 - Final Project
//
// License: Copyright © 2022 Fabian Gomez
// License: Copyright © 2022 Matheus M Silva
// License: Copyright © 2022 Quentin Swett
//
//The functions bellow are used in both gather_data and classify_file
////////////////////////////////////////

#ifndef COMMON_FUNC_H
#define COMMON_FUNC_H

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

// Remove punctuation, parenthesis and convert all capital letter to lower cases
// Input: word that is going to be clean
// Output the punctuation will be removed from the word and covert to lower case
void sanitizer(string &str);

// Separate the words from a sentence and store them into a vector
// Input: the vector of strings and the sentence
// Output: the words are stored into the vector
void separate_words(vector<string> &w, string s);

void sanitizer(string &str)
{
   // Go through all the string
    for(int  i = 0; i < str.size(); i ++)
    {
        // Make it a lower letter
        str[i] = tolower(str[i]);

        // Replace anything that is not a number of a letter by " "
        if(!isalnum(str[i]))
        {
            str.erase(i, 1);
            str.insert(i, " ");
        }
    } 
}

void separate_words(vector<string> &w, string s)
{
    // run until the string is empty
    while (!s.empty())
    {
        if (s[0] != ' ')
        {
            int index = s.find(' '); // find a space
            w.push_back(s.substr(0, index)); // push back until the space
            s.erase(0, index); // delete until the space
        }
        else
        {
            s.erase(0, 1); // erase if the first character is a space
        }
    }
}

#endif