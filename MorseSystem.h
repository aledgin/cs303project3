// Alfred Ledgin
// 12/4/2015
// CS 303
// Project 3

#pragma once
#include "MorseCode.h"
#include <iostream>
#include <string>
using namespace std;


class MorseSystem
    // This class serves as an external means of using the MorseCode class.
    // It provides access to the three main functional components of the
    // MorseCode class: defining a code set, decoding a Morse Code word,
    // and encoding a word in Morse Code.
{

    public:

        MorseSystem() {;}
        // Preconditions: A MorseSystem object needs to be created.
        // Postconditions: This default constructor simply creates a
            // MorseSystem object and the MorseCode object contained within
            // it.


        MorseSystem(istream& input) {setInput(input);}
        // Preconditions: A MorseSystem object needs to be created with the
            // given source for the Morse Code alphabet definition.
        // Postconditions: This constructor creates a MorseSystem object using
            // the given input in order to define the Morse Code alphabet.


        void setInput(istream& input) {definitionSet.buildCode(input);}
        // Preconditions: A MorseSystem needs its Morse Code alphabet defined
            // according to the given input definitions.
        // Postconditions: This function calls the MorseCode object's
            // buildCode() function to define the Morse Code alphabet according
            // to the given input.


        const string decodeWord(const string& inputCodedWord) const
        // Preconditions: The MorseSystem needs to decode a given Morse Code
            // word.
        // Postconditions: This function calls the MorseCode object's
            // interpret() function in order to parse and decode the given
            // string representing a word in Morse Code.
        {
            return definitionSet.interpret(inputCodedWord);
        }


        const string encodeWord(const string& inputWord) const
        // Preconditions: The MorseSystem needs to encode a given word in
            //  Morse Code.
        // Postconditions: This function calls the MorseCode object's
            // encodeWord() function in order to return the string of Morse
            // Code symbols representing the given word.
        {
            return definitionSet.encodeWord(inputWord);
        }


    private:

        MorseCode definitionSet;

};