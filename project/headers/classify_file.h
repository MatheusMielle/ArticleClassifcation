////////////////////////////////////////
// May 20th, 2022
// CS-172-1 - Final Project
//
// License: Copyright © 2022 Fabian Gomez
// License: Copyright © 2022 Matheus M Silva
// License: Copyright © 2022 Quentin Swett
//
// Functions get the file from the user, get the info in the file, 
// sum the score up, compare each score and display the most probable article
////////////////////////////////////////

#ifndef CLASSIFY_FILE_H
#define CLASSIFY_FILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <word.h>
#include <common_functions.h>
using namespace std;

// Function that call function and display results
void do_comparation();

// Utility to get the data from the file provided by the user
// Return a vector with the data of the user's file
vector<string> get_user_file();

// Get the data of one of the files; sport, food ot news
// Input: The type of article
// output: Vector with he data of the article
void get_data_info(vector<WORD> &w, string file);

// Compare the words of the user file with one of articles 
// Input: word of the user file and the word of one of the articles; sport, new or food
// Return the probability of being of that article
float get_score(vector<string> user, vector<WORD> data);

// Calculate the probability of being a food, sport or news articles
// Input: The score of the word of each file
// Output: What article is most likely to be
string compare(float f, float s, float n);

void do_comparation()
{
    vector<WORD> f_data;
    vector<WORD> s_data;
    vector<WORD> n_data;

    vector<string> user_input = get_user_file();

    get_data_info(f_data, "food");
    get_data_info(s_data, "sports");
    get_data_info(n_data, "news");

    float food_score = get_score(user_input, f_data);
    float sports_score = get_score(user_input, s_data);
    float news_score = get_score(user_input, n_data);

    cout <<"\nFood Score: "<< food_score
         << "\nSports Score: " << sports_score
         << "\nNews Score: "<< news_score << "\n\n";

    cout << compare(food_score, sports_score, news_score);
}

vector<string> get_user_file()
{
    string line;
    vector<string> words;

    string filename;
    cin >> filename;

    ifstream input;
    input.open(filename);

    while (getline(input, line)) // get line
    {
        sanitizer(line);
        separate_words(words, line);
    }
    input.close();

    return words; 
}

void get_data_info(vector<WORD> &w, string file)
{
    string fileName = "data\\" + file + ".dat";

    string word;
    float score;

    ifstream input;
    input.open(fileName);

    while(!input.eof())
    {
        input >> word >> score;
        w.push_back(WORD(word, score));
    }

    input.close();
}

float get_score(vector<string> user, vector<WORD> data)
{
    float count = 0; // Total score

    // Compare the data of one of the article, with the data of the user's articles
    for(int i = 0; i < user.size(); i++)
    {
        for(int j = 0; j < data.size(); j++)
        {
            if(data[j] == user[i]) // If the word is on the articles
            {
                count += data[j].getCount(); // Update score
                break;
            }
        }
    }
    return count;
}

string compare(float f, float s, float n)
{
    string article = "FOOD";
    float higher = f;

    if(s > higher)
    {
        higher = s; // Update article
        article = "SPORTS";
    }
    if(n > higher)
    {
        higher = n; // Update article
        article = "NEWS";
    }
    string result = "Most likely to be a " + article + " article.\n";
    return result;
}



#endif