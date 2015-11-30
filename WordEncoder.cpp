// Alfred Ledgin
// 11/29/2015
// CS 303
// Project 3

#include "MorseCode.h"
#include "MorseEncoder.h"
#include "WordEncoder.h"
#include <iostream>
#include <string>
using namespace std;


const string WordEncoder::encode(const string& input) const
{
    if (definitionSet.isBuilt())
    {
        MorseEncoder letterEncoder(definitionSet);
        string output;
        for (int counter = 0; counter < input.length(); counter++)
        {
            output += letterEncoder.encode(input[counter]);
            if (counter < input.length() - 1)
                output += " ";
        }
        return output;
    }
    else
        return "";
}