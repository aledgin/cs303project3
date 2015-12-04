// Alfred Ledgin
// 12/4/2015
// CS 303
// Project 3

#pragma once
#include "MorseSystem.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class MorseUI
    // This class is a user interface for the Morse Code system.  It provides
    // access to the functions within the MorseSystem class.
{

    public:

        MorseUI() {;}
        // Preconditions: A MorseUI object needs to be created.
        // Postconditions: This default constructor simply creates a MorseUI
            // object and declares the contained member variables.


        void execute();
        // Preconditions: The function accessing the MorseUI is ready to run
            // the user interface.
        // Postconditions: This function runs all of the processes involved
            // in the Morse Code user interface.

        
    private:

        void displayMenu();
        // Preconditions: The menu needs to be displayed.
        // Postconditions: This function displays the menu and accepts the
            // user's choice of menu option.


        void obtainFile();
        // Preconditions: A file containing the definition for a Morse Code
            // alphabet needs to be opened, and its contents need to be used
            // to define the Morse Code alphabet.
        // Postconditions: This function prompts the user to enter the name
            // of the relevant file, attempts to open it, and then attempts
            // to define the Morse Code alphabet accordingly.


        void decodeWord();
        // Preconditions: The user wishes to decode a string of Morse Code
            // symbols.
        // Postconditions: This function prompts the user to enter a string of
            // Morse Code symbols and then attempts to decode them.


        void encodeWord();
        // Preconditions: The user wishes to encode a word in Morse Code.
        // Postconditions: This function prompts the user to enter the word to
            // encode and then attempts to encode it in Morse Code.


        void handleInput(string& inputString);
        // Preconditions: The user has entered a string of Morse Code symbols
            // that may contain spaces.
        // Postconditions: This function handles data entered at the cin prompt
            // in order to allow spaces to be used in the string entered by the
            // user.


        bool quit;
        char menuOption;
        MorseSystem codeSystem;

};