// Alfred Ledgin
// 11/30/2015
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
        // Note: We may not need this function for final version.


        const Binary_Tree<string>& accessTree() const {return codeTree;}


        const map<char, string>& accessMap() const {return codeMap;}


    private:


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