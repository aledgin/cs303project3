// Alfred Ledgin
// 11/29/2015
// CS 303
// Project 3

#pragma once
#include "MorseCode.h"
#include <iostream>
#include <map>
#include <string>


class MorseEncoder
{

    public:

        MorseEncoder() {;}


        MorseEncoder(const MorseCode& inputDefinitions)
        {
            setDefinitions(inputDefinitions);
        }


        void setDefinitions(const MorseCode& inputDefinitions);


        const string encode(char letter) const;


    private:

        MorseCode definitionSet;
        map<char, string> inputMap;

};