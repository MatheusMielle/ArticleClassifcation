///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Input Classification Program
// Final Project for CS-172-1 - Whitworth University
//
// Developed by Matheus Mielle Silva, Fabian Gomez, and Quentin Swett
// Developed on: May 20th, 2022
//
// License: Only project developers are allowed to edit or share
// this file electronically unless such permission is given by the developers.
//
// License: Copyright © 2022 Fabian Gomez
// License: Copyright © 2022 Matheus M Silva
// License: Copyright © 2022 Quentin Swett
//
// Credits and Sources:
// - Scott Griffith - Whitworth CS Professor (Ideas and Debugging)
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <word.h>
#include <gather_data.h>
#include <classify_file.h>
using namespace std;

int main()
{
    cout << "Input 1 for gather data or 2 for categorize a file\n";
    int a;
    cin >> a;

    if (a == 1)
    {
        create_data_file();
        cout << "Done!";
    }
    else if (a == 2)
    {
        cout << "File Path: ";
        do_comparation();
    }
    else
    {
        cout << "ERROR!";
        return 0;
    }
}
