// Alfred Ledgin
// 11/29/2015
// CS 303
// Project 3

#include "MorseParser.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


const vector<string> MorseParser::parse(const string& input) const
{
    vector<string> output;
    int counter = 0;
    while (counter < input.length())
    {
        string newMorseLetter;
        while (input[counter] != ' ' && counter < input.length())
        {
            newMorseLetter += input[counter];
            counter++;
        }
        if (newMorseLetter.length())
            output.push_back(newMorseLetter);
        counter++;
    }
    return output;
}