// Alfred Ledgin
// 12/3/2015
// CS 303
// Project 3

#pragma once
#include "MorseCode.h"
#include <iostream>
#include <string>
using namespace std;


class MorseSystem
{

    public:

        MorseSystem() {;}


        MorseSystem(istream& input) {setInput(input);}


        void setInput(istream& input)
        {
            definitionSet.buildCode(input);
        }


        const string decodeWord(const string& inputCodedWord) const
        {
            return definitionSet.interpret(inputCodedWord);
        }


        const string encodeWord(const string& inputWord) const
        {
            return definitionSet.encodeWord(inputWord);
        }


    private:

        MorseCode definitionSet;

};