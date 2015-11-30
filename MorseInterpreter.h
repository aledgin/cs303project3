// Alfred Ledgin
// 11/29/2015
// CS 303
// Project 3

#pragma once
#include "MorseCode.h"
#include "WordDecoder.h"
#include "MorseParser.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class MorseInterpreter
{

    public:

        MorseInterpreter() {;}


        MorseInterpreter(const MorseCode& inputDefinitions)
        {
            setDefinitions(inputDefinitions);
        }


        void setDefinitions(const MorseCode& inputDefinitions)
        {
            definitionSet = inputDefinitions;
        }


        const string interpret(const string& input) const;


    private:

        MorseCode definitionSet;

};