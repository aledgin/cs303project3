// Alfred Ledgin
// 11/29/2015
// CS 303
// Project 3


#include "MorseCode.h"
#include "MorseDecoder.h"
#include "MorseInterpreter.h"
#include "MorseParser.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


const string MorseInterpreter::interpret(const string& input) const
{
    if (definitionSet.isBuilt())
    {
        MorseParser currentParser(input);
        WordDecoder currentWordDecoder(definitionSet);
        vector<string> currentLetters = currentParser.parse();
        return currentWordDecoder.decode(currentLetters);
    }
    else
        return "";
}