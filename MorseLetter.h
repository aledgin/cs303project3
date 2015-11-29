// Alfred Ledgin
// 11/28/2015
// CS 303
// Project 3

#pragma once
#include <string>
using namespace std;

class MorseLetter
{

public:

    MorseLetter() {letter = ' ';}


    MorseLetter(const char& inputLetter, const string& inputCode)
    {
        define(inputLetter, inputCode);
    }


    void define(const char& inputLetter, const string& inputCode)
    {
        letter = inputLetter;
        code = "";
        for (int counter = 0; counter < inputCode.length(); counter++)
        {
            if (inputCode[counter] == '.')
                code += '0';
            else
                code += '1';
        } // Necessary for correct comparison.
    }


    const bool operator<(const MorseLetter& rhs) const
    {
        return code < rhs.code;
    }


    const string hasLetter() const 
    {
        string letterString;
        letterString += letter;
        return letterString;
    }


    const string hasCode() const {return code;}


private:

    char letter;
    string code;

};