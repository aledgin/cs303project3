// Alfred Ledgin
// 12/4/2015
// CS 303
// Project 3

#include "MorseSystem.h"
#include "MorseUI.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void MorseUI::execute()
{

    quit = false; // Force the program to continue until the user quits.

    do
    {

        displayMenu();

        switch (menuOption)
        {
            case '1': obtainFile(); break;
            case '2': decodeWord(); break;
            case '3': encodeWord(); break;
            case '4': quit = true; break;
            default: displayMenu(); break;
        }

    }
    while (!quit);
    
}


void MorseUI::displayMenu()
{
    cout << "Morse Code System" << endl << endl;
    cout << "Enter a menu option:" << endl;
    cout << "1. Enter a code file." << endl;
    cout << "2. Decode a word." << endl;
    cout << "3. Encode a word." << endl;
    cout << "4. Quit." << endl << endl;
    cin >> menuOption;
}


void MorseUI::obtainFile()
{
    string filename;
    ifstream file;
    do
    {
        cout << "Enter the filename (or 'b' to go back):" << endl;
        cin >> filename;
        file.open(filename);
        if (filename == "b") // Allow the user to go back.
            break;
        if (!file)
            cout << "Error: File not found." << endl;
    }
    while (!file);
    if (file)
        codeSystem.setInput(file); // Define the Morse Code alphabet.
    file.close();
}


void MorseUI::decodeWord()
{
    string inputWord;
    cout << "Enter a word in Morse Code." << endl;
    handleInput(inputWord); // Handle spaces at cin prompt.
    try
    {
        cout << "The word is: " << codeSystem.decodeWord(inputWord) << endl
            << endl; // Print the decoded word.
    }
    catch(std::exception& error)
    {
        cout << "Error: " << error.what() << endl << endl;
    }
    // Reference:
        // "std::exception." _cplusplus.com_. cplusplus.com, 2015.
            // Web. 3 Dec. 2015.
            // <http://www.cplusplus.com/reference/exception/exception/>.
}


void MorseUI::encodeWord()
{
    string inputWord;
    cout << "Enter a word to encode:" << endl;
    cin >> inputWord;
    try
    {
        cout << "Morse Code: " << codeSystem.encodeWord(inputWord) << endl
            << endl; // Print the word in Morse Code.
    }
    catch(std::exception& error)
    {
        cout << "Error: " << error.what() << endl << endl;
    }
    // Reference:
        // "std::exception." _cplusplus.com_. cplusplus.com, 2015.
            // Web. 3 Dec. 2015.
            // <http://www.cplusplus.com/reference/exception/exception/>.
}


void MorseUI::handleInput(string& inputString)
{
    do
    {
        cin.ignore();
        inputString = "";
        getline(cin, inputString);
        if (inputString == "")
            inputString = "NULL";
    } while (inputString.length() > 500 || inputString.length() == 0);
    // Maximum of 100 four-character Morse-coded letters plus 100 spaces.
}
// Source:
    // Kuhail, Mohammad. "White spaces." Message to the author.
        // 2 Dec. 2015. E-mail.