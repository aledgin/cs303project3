// Alfred Ledgin
// 11/29/2015
// CS 303
// Project 3

#pragma once
#include "MorseCode.h"
#include "MorseEncoder.h"
#include <iostream>
#include <string>
using namespace std;


class WordEncoder
{

    public:

        WordEncoder() {;}


        WordEncoder(const MorseCode& inputDefinitions)
        {
            setDefinitions(inputDefinitions);
        }


        void setDefinitions(const MorseCode& inputDefinitions)
        {
            definitionSet = inputDefinitions;
        }


        const string encode(const string& input) const;


    private:

        MorseCode definitionSet;

};