// Alfred Ledgin
// 12/4/2015
// CS 303
// Project 3

#include "MorseUI.h"
#include "MorseSystem.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{

    // Note to Tester:
        // If you do not wish to use the UI, remove the comment lines from
        // around the following code segment, change the string arguments as
        // desired, and then enter "4" to quit the UI.

    /***
    
    ifstream file;
    file.open("morse.txt");
    MorseSystem theSystem(file);
    file.close();
    cout << theSystem.decodeWord(".... ..") << endl;
    cout << theSystem.encodeWord("hi") << endl;
    system("pause"); // Do not change.

    ***/

    MorseUI theInterface;
    theInterface.execute();

    return 0;

}