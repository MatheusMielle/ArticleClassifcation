////////////////////////////////////////
// May 20th, 2022
// CS-172-1 - Final Project
//
// License: Copyright © 2022 Fabian Gomez
// License: Copyright © 2022 Matheus M Silva
// License: Copyright © 2022 Quentin Swett
//
// Functions to get data from the sample files, format it,
// remove the most used words, calculate the score and save it .dat files
////////////////////////////////////////

#ifndef GATHER_DATA_H
#define GATHER_DATA_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <word.h>
#include <common_functions.h>
using namespace std;

// Function to call all other functions to create the data files
// Input: N/A
// Output: The data files will be created
void create_data_file();

// Gets all the words of all file in a specific folder
// Input: the name of the folder
// Output: creates a string of all the words in the txt in a folder
vector<string> get_words(string folder);

// Check if the word is already in the vector word
// Input: the vector word and the word (string s) to be compared
// Output: true for the word is already added and false for the opposite
bool check_double(string s, vector<WORD> w);

// Add word to the word vector or update the count if the word is already there
// Input: the words of all files(string s) and the word vector
// Output: the word vector will be updated
void add_word(vector<string> s, vector<WORD> &w);

// save the data with the score to .dat file
// Input: the word vector and the article name
// Output: files will be created
void save_data(vector<WORD> w, string article_name);

// Create a vector of the most common words to omit them in the data files
// Input: vector with the information of a food, news, or sport articles
// Output: a vector without the 100 most common words
void remove_most_use(vector<string> &w);


void create_data_file()
{
    vector<WORD> food;
    vector<WORD> sports;
    vector<WORD> news;

    vector<string> f = get_words("food");
    vector<string> s = get_words("sports");
    vector<string> n = get_words("news");

    add_word(f, food);
    add_word(s, sports);
    add_word(n, news);

    save_data(food, "food");
    save_data(sports, "sports");
    save_data(news, "news");
}

vector<string> get_words(string folder)
{
    ifstream input;
    vector<string> words; // vectors of strings
    string line;          // line
    // goes through all the 30 files in the folder
    for (int i = 0; i < 30; i++)
    {
        string filename = "sample_files\\" + folder + "\\" + to_string(i + 1) + ".txt";
        input.open(filename);

        while (getline(input, line))
        {
            sanitizer(line); // Clean the word
            separate_words(words, line); // separate each word from the line
        }
        input.close();
    }
    remove_most_use(words); // remove most used words
    return words;
}

bool check_double(string s, vector<WORD> w)
{
    // Compare each word in the word vector with the desired word
    for (int i = 0; i < w.size(); i++)
    {
        if (w[i] == s)
        {
            return true;
        }
    }
    return false;
}

void add_word(vector<string> s, vector<WORD> &w)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (!check_double(s[i], w))
        {
            w.push_back(WORD(s[i]));
        }
        else
        {
            // Look for the word and increase the score
            for (int j = 0; j < w.size(); j++)
            {
                if (w[j] == s[i])
                {
                    w[j].addS();
                    break;
                }
            }
        }
    }

    for (int i = 0; i < w.size(); i++)
    {
        w[i].update_score(s.size());
    }
}

void save_data(vector<WORD> w, string article_name)
{
    string path = "data\\" + article_name + ".dat";
    ofstream out;
    out.open(path);

    for (int i = 0; i < w.size(); i++)
    {
        out << w[i];
    }
    out.close();
}

void remove_most_use(vector<string> &w)
{
    vector<string> most_used; // the list of most used words
    string word; // the word curent get from the file

    ifstream input; 
    input.open("most_use.txt");
    while (!input.eof())
    {
        input >> word;
        most_used.push_back(word);
    }

    for(int i = 0; i < w.size(); i++)
    {
        for (int j = 0; j < most_used.size(); j++)
        {
            if(w[i] == most_used[j])
            {
                w.erase(w.begin()+ i);
                i -= 1;
                break;                 
            }
        }
    }
}

#endif
