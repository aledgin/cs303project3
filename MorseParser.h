// Alfred Ledgin
// 11/29/2015
// CS 303
// Project 3

#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class MorseParser
{

    public:

        MorseParser() {;}


        MorseParser(const string& input) {morseString = input;}


        void setInput(const string& input) {morseString = input;}


        const vector<string> parse() const {return parse(morseString);}


        const vector<string> parse(const string& input) const;


    private:

        string morseString;

};