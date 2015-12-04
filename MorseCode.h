// Alfred Ledgin
// 12/3/2015
// CS 303
// Project 3

#pragma once
#include "Binary_Tree.h"
#include "MorseLetter.h"
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;


class MorseCode
{

    public:

        MorseCode();
    

        MorseCode(istream& input);


        void buildCode(istream& input);


        const bool isBuilt() const {return codeBuilt;}


        const string showCodeTree() const {return codeTree.to_string();}
        // Reference:
            // Kuhail, Mohammad. "Binary_Tree.h" 2015. C++ header (.h) file.
        // Note: This function exists for testing purposes.


        const vector<string> parse(const string& input) const;


        const char decodeLetter(const string& codedLetter) const;


        const string encodeLetter(char letter) const;


        const string decodeWord(const vector<string>& input) const;


        const string encodeWord(const string& input) const;


        const string interpret(const string& input) const;


    private:


        const string decodeLetterInternal(const string& codedLetter,
            int index, Binary_Tree<string> tempTree) const;


        const bool buildCodeList(istream& input);


        const bool testCode(string inputCode);


        void defineStandardVec();


        void buildCodeVec();


        Binary_Tree<string> codeTree;
        map<char, string> codeMap;
        list<MorseLetter> codeList;
        vector<string> standardVec;
        vector<string> codeVec;
        bool codeBuilt;

};