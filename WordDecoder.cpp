// Alfred Ledgin
// 11/29/2015
// CS 303
// Project 3

#include "WordDecoder.h"
#include "MorseCode.h"
#include "MorseDecoder.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


const string WordDecoder::decode(const vector<string>& input) const
{
    if (definitionSet.isBuilt())
    {
        MorseDecoder letterDecoder(definitionSet);
        string output;
        for (int counter = 0; counter < input.size(); counter++)
        {
            output += letterDecoder.decode(input[counter]);
        }
        return output;
    }
    else
        return "";
}