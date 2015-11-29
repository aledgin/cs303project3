// Alfred Ledgin
// 11/28/2015
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

        MorseCode()
        {
            defineStandardVec();
            codeBuilt = false;
        }
    

        MorseCode(istream& input);


        bool buildCode(istream& input);


        string showCodeTree() {return codeTree.to_string();}
        // Reference:
            // Kuhail, Mohammad. "Binary_Tree.h" 2015. C++ header (.h) file.
        // Note: We may not need this function for final version.


    private:


        bool testCode(string inputCode);


        void defineStandardVec()
        {
            standardVec = { "0", "00", "000", "0000",
                "0001", "001", "0010", "0011", "01", "010", "0100", "0101",
                "011", "0110", "0111", "1", "10", "100", "1000", "1001",
                "101", "1010", "1011", "11", "110", "1100", "1101", "111",
                "1110", "1111" }; // Check again before finishing.
        }


        Binary_Tree<string> codeTree;
        map<char, string> codeMap;
        list<MorseLetter> codeList;
        vector<string> standardVec;
        vector<string> codeVec;
        bool codeBuilt;

};