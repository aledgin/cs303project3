// Alfred Ledgin
// 11/29/2015
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


    void define(const char& inputLetter, const string& inputCode);


    const bool operator<(const MorseLetter& rhs) const
    {
        return code < rhs.code;
    }


    const string hasLetter() const;


    const string hasCode() const {return code;}


private:

    char letter;
    string code;

};