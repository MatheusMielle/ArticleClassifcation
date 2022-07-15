////////////////////////////////////////
// First Modified: May 16th, 2022
// Last Modified: May  20th, 2022
// CS-172-1 - Final Project
//
// License: Copyright © 2022 Fabian Gomez
// License: Copyright © 2022 Matheus M Silva
// License: Copyright © 2022 Quentin Swett
//
// Word Class cpp file
////////////////////////////////////////

#include <iostream>
#include "..\headers\word.h"
using namespace std;

WORD::WORD()
{
    _word = "";
    _score = 0;
}

WORD::WORD(string w, float s)
{
    _word  = w;
    _score = s;
}

WORD::WORD(string s)
{
    _word = s;
    _score = 1;
}

void WORD::addS()
{
    _score++;
}

void WORD::update_score(int total)
{
    _score /= total;
}

bool WORD::operator==(string s)
{
    if (this->_word == s)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool WORD::operator==(WORD w)
{
    if (this->_word == w._word)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool WORD::operator>(WORD w)
{
    if (this->_score> w._score)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string WORD::getWord()
{
    return _word;
}

float WORD::getCount()
{
    return _score;
}


ostream &operator<<(ostream &out, WORD &w)
{
    out << w.getWord() 
        << " " 
        << w.getCount()
        << "\n";
      
    return out;
}

