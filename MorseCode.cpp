// Alfred Ledgin
// 11/30/2015
// CS 303
// Project 3

#include "MorseCode.h"
#include "MorseLetter.h"
#include "Binary_Tree.h"
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;


MorseCode::MorseCode()
{
    defineStandardVec();
    codeBuilt = false;
}


MorseCode::MorseCode(istream& input)
{
    defineStandardVec();
    buildCode(input);
}


void MorseCode::buildCode(istream& input)
{
    if (!buildCodeList(input))
    {
        codeBuilt = false;
        return;
    }
    codeList.sort();
    buildCodeVec();
    codeTree.read_tree(codeVec);
    // References:
        // Kuhail, Mohammad. "Binary_Tree.h" 2015. C++ header (.h) file.
        // Kuhail, Mohammad. "Lecture 10: Introduction to Trees."
            // CS 303 course materials, University of Missouri-Kansas City,
            // Fall 2015. _Microsoft PowerPoint_ file. Slide 29.
    codeBuilt = true;
}


const bool MorseCode::buildCodeList(istream& input)
{
    string entry;
    char letter = ' ';
    string code;
    MorseLetter pair;
    while (input >> entry)
    {
        code = "";
        letter = entry[0];
        for (int counter = 1; counter < entry.length(); counter++)
        {
            code += entry[counter];
        }
        if (!testCode(code))
            return false;
        codeMap[letter] = code;
        pair.define(letter, code);
        codeList.push_back(pair);
    }
    return true;
}


const bool MorseCode::testCode(string inputCode)
{
    for (int counter = 0; counter < inputCode.length(); counter++)
    {
        if (inputCode[counter] != '.' && inputCode[counter] != '_')
            return false;
    }
    return true;
}


void MorseCode::defineStandardVec()
{
    standardVec = { "0", "00", "000", "0000",
        "0001", "001", "0010", "0011", "01", "010", "0100", "0101",
        "011", "0110", "0111", "1", "10", "100", "1000", "1001",
        "101", "1010", "1011", "11", "110", "1100", "1101", "111",
        "1110", "1111" }; // Check again before finishing.
}


void MorseCode::buildCodeVec()
{
    codeVec.push_back(" ");
    list<MorseLetter>::iterator iter = codeList.begin();
    int counter = 0;
    while (iter != codeList.end())
    {
        if (iter->hasCode() == standardVec[counter])
        {
            codeVec.push_back(iter->hasLetter());
            if (iter->hasCode().length() == 4) // Max depth.
            {
                for (int two = 0; two < 2; two++)
                {
                    codeVec.push_back("NULL");
                }
            }
            iter++;
        }
        else
            codeVec.push_back("NULL");
        counter++;
    }
}
// Reference for Idea:
    // Kuhail, Mohammad. "Lecture 10: Introduction to Trees."
        // CS 303 course materials, University of Missouri-Kansas City,
        // Fall 2015. _Microsoft PowerPoint_ file. Slide 29.