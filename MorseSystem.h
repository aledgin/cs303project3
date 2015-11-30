// Alfred Ledgin
// 11/30/2015
// CS 303
// Project 3

#include "MorseCode.h"
#include "MorseInterpreter.h"
#include "WordEncoder.h"
#include <iostream>
#include <string>
using namespace std;


class MorseSystem
{

    public:

        MorseSystem() {;}


        MorseSystem(istream& input) {setInput(input);}


        void setInput(istream& input);


        const string decodeWord(const string& inputCodedWord) const
        {
            return theInterpreter.interpret(inputCodedWord);
        }


        const string encodeWord(const string& inputWord) const
        {
            return theEncoder.encode(inputWord);
        }


    private:

        MorseCode definitionSet;
        MorseInterpreter theInterpreter;
        WordEncoder theEncoder;

};