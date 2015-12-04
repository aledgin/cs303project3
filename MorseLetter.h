// Alfred Ledgin
// 11/29/2015
// CS 303
// Project 3

#pragma once
#include <string>
using namespace std;

class MorseLetter
    // This is a class of objects for the purpose of aiding in the creation of
    // a Morse Code set (MorseCode object).  Each MorseLetter object has its
    // identifying letter ('a' through 'z') and a corresponding code stored as
    // a string of binary digits, converted from Morse Code symbols.
{

public:

    MorseLetter() {letter = ' ';}
    // Preconditions: A MorseLetter needs to be constructed.
    // Postconditions: This constructor initializes a MorseLetter,
        // setting the identifying letter to a space.


    MorseLetter(const char& inputLetter, const string& inputCode)
    // Preconditions: A MorseLetter needs to be constructed with a given
        // letter and corresponding Morse Code.
    // Postconditions: This constructor creates a MorseLetter and defines
        // its attributes according to the given letter and code.
    {
        define(inputLetter, inputCode);
    }


    void define(const char& inputLetter, const string& inputCode);
    // Preconditions: A MorseLetter needs to be defined according to the given
        // letter and corresponding Morse Code.
    // Postconditions: This function sets the object's letter as given,
        // converts the given Morse Code to a binary string, and saves the
        // binary string.


    const bool operator<(const MorseLetter& rhs) const
    // Preconditions: Two MorseLetters need to be compared for sorting
        // purposes.
    // Postconditions: This function compares two MorseLetter objects
        // according to their binary strings representing the corresponding
        // Morse Code.
    {
        return code < rhs.code;
    }


    const string hasLetter() const;
    // Preconditions: A MorseLetter object's letter is needed in string format.
    // Postconditions: This function obtains the letter in string format and
        // returns the string.


    const string hasCode() const {return code;}
    // Preconditions: A MorseLetter object's binary-string code is needed.
    // Postconditions: This function returns the binary-string code for the
        // MorseLetter.


private:

    char letter;
    string code;

};