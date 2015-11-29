// Alfred Ledgin
// 11/29/2015
// CS 303
// Project 3

#pragma once
#include "Binary_Tree.h"
#include "MorseCode.h"
#include <iostream>
using namespace std;


class MorseDecoder
{

    public:

        MorseDecoder() {;}


        MorseDecoder(const MorseCode& inputDefinitions)
        {
            setDefinitions(inputDefinitions);
        }


        void setDefinitions(const MorseCode& inputDefinitions);

        
        const char decode(const string& codedLetter) const;


    private:


        const string MorseDecoder::decodeInternal(const string& codedLetter,
            int index, Binary_Tree<string> tempTree) const;


        MorseCode definitionSet;
        Binary_Tree<string> inputTree;

};