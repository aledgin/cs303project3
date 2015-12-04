// Alfred Ledgin
// 12/4/2015
// CS 303
// Project 3

#include "MorseLetter.h"
#include <string>
using namespace std;


void MorseLetter::define(const char& inputLetter, const string& inputCode)
{
    letter = inputLetter;
    code = "";
    for (int counter = 0; counter < inputCode.length(); counter++)
    {
        if (inputCode[counter] == '.')
            code += '0';
        else // Assumption: inputCode[counter] == '_'
            code += '1';
    } // Conversion necessary for correct comparison.
}


const string MorseLetter::hasLetter() const
{
    string letterString;
    letterString += letter;
    return letterString;
}