// Alfred Ledgin
// 11/30/2015
// CS 303
// Project 3

#include "MorseSystem.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void displayMenu(char& menuInput);


void obtainFile(MorseSystem& inputSystem);


void decodeWord(MorseSystem& inputSystem);


void encodeWord(MorseSystem& inputSystem);


void convertSlashes(string& inputString);


int main()
{

    bool quit = false;
    char menuOption;
    MorseSystem codeSystem;

    do
    {

        displayMenu(menuOption);

        switch (menuOption)
        {
            case '1': obtainFile(codeSystem); break;
            case '2': decodeWord(codeSystem); break;
            case '3': encodeWord(codeSystem); break;
            case '4': quit = true; break;
            default: displayMenu(menuOption); break;
        }

    }
    while (!quit);
    
    return 0;

}


void displayMenu(char& menuInput)
{
    cout << "Morse Code System" << endl << endl;
    cout << "Enter a menu option:" << endl;
    cout << "1. Enter a code file." << endl;
    cout << "2. Decode a word." << endl;
    cout << "3. Encode a word." << endl;
    cout << "4. Quit." << endl << endl;
    cin >> menuInput;
}


void obtainFile(MorseSystem& inputSystem)
{
    string filename;
    ifstream file;
    do
    {
        cout << "Enter the filename (or 'b' to go back):" << endl;
        cin >> filename;
        file.open(filename);
        if (filename == "b")
            break;
    }
    while (!file);
    if (file)
        inputSystem.setInput(file);
    file.close();
}


void decodeWord(MorseSystem& inputSystem)
{
    string inputWord;
    cout << "Enter a word in Morse Code." << endl;
    cout << "Separate each letter code with a slash (/)." << endl;
    cout << "Do not use spaces." << endl;
    cin >> inputWord;
    convertSlashes(inputWord);
    cout << "The word is: " << inputSystem.decodeWord(inputWord) << endl
        << endl;
}


void encodeWord(MorseSystem& inputSystem)
{
    string inputWord;
    cout << "Enter a word to encode:" << endl;
    cin >> inputWord;
    cout << "Morse Code: " << inputSystem.encodeWord(inputWord) << endl
        << endl;
}


void convertSlashes(string& inputString)
{
    for (int counter = 0; counter < inputString.length(); counter++)
    {
        if (inputString[counter] == '/')
            inputString[counter] = ' ';
    }
}