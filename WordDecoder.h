// Alfred Ledgin
// 11/29/2015
// CS 303
// Project 3

#pragma once
#include "MorseCode.h"
#include "MorseDecoder.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class WordDecoder
{

    public:

        WordDecoder() {;}


        WordDecoder(const MorseCode& inputDefinitions)
        {
            setDefinitions(inputDefinitions);
        }


        void setDefinitions(const MorseCode& inputDefinitions)
        {
            definitionSet = inputDefinitions;
        }


        const string decode(const vector<string>& input) const;


    private:

        MorseCode definitionSet;

};