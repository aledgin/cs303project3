// Alfred Ledgin
// 12/4/2015
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
        // Kuhail, Mohammad. "Binary_Tree.h." 2015. C++ header (.h) file.
        // Kuhail, Mohammad. "Lecture 10: Introduction to Trees."
            // CS 303 course materials, University of Missouri-Kansas City,
            // Fall 2015. _Microsoft PowerPoint_ file. Slide 29.
    codeBuilt = true;
}


const vector<string> MorseCode::parse(const string& input) const
{
    vector<string> output;
    int counter = 0;
    while (counter < input.length())
    {
        string newMorseLetter;
        while (input[counter] != ' ' && counter < input.length())
        { // Use spaces to separate needed substrings.
            newMorseLetter += input[counter];
            counter++;
        }
        if (newMorseLetter.length()) // Add non-empty strings to vector.
            output.push_back(newMorseLetter);
        counter++;
    }
    return output;
}


const char MorseCode::decodeLetter(const string& codedLetter) const
{
    if (!testCode(codedLetter))
    {
        throw
            std::exception("Invalid Morse Code.");
    }
    if (isBuilt())
    {
        try
        {
            return decodeLetterInternal(codedLetter, 0, codeTree)[0];
        }
        catch (std::exception)
        {
            throw
                std::exception("Letter not found.");
        }
    }
    else
    {
        throw
            std::exception("Code set not found.");
    }
}


const string MorseCode::decodeLetterInternal(const string& codedLetter, int index,
    Binary_Tree<string> tempTree) const
{
    if (index == codedLetter.length() - 1)
    {
        if (codedLetter[index] == '.')
            return tempTree.get_left_subtree().get_data();
        else
            return tempTree.get_right_subtree().get_data();
    }
    else
    {
        if (codedLetter[index] == '.')
            return decodeLetterInternal(codedLetter, index + 1,
            tempTree.get_left_subtree());
        else
            return decodeLetterInternal(codedLetter, index + 1,
            tempTree.get_right_subtree());
    }
}
// Reference for Binary Tree Functions:
    // Kuhail, Mohammad. "Lecture 10: Introduction to Trees."
        // CS 303 course materials, University of Missouri-Kansas City,
        // Fall 2015. _Microsoft PowerPoint_ file. Slide 24.


const string MorseCode::encodeLetter(char letter) const
{
    if (isBuilt())
    {
        if (letter >= 'A' && letter <= 'Z') // Convert upper case to lower.
            letter += 32;
            // Reference for ASCII conversion:
                // Wikipedia contributors. "ASCII." _Wikipedia, The Free
                    // Encyclopedia_. Wikipedia, The Free Encyclopedia, 
                    // 20 Nov. 2015. Web. 3 Dec. 2015.
                    // <https://en.wikipedia.org/wiki/ASCII>.
                    // Distributed under Creative Commons
                    // Attribution-ShareAlike License:
                    // <http://creativecommons.org/licenses/by-sa/3.0/>.
        try
        {
            return codeMap.at(letter);
            // Reference:
                // "std::map::at." _cplusplus.com_. cplusplus.com, 2015. Web.
                    // 29 Nov. 2015.
                    // <http://www.cplusplus.com/reference/map/map/at/>.
        }
        catch (std::exception)
        {
            throw
                std::exception("Character is not a letter.");
        }
    }
    else
    {
        throw
            std::exception("Code set not found.");
    }
}


const string MorseCode::decodeWord(const vector<string>& input) const
{
    if (isBuilt())
    {
        string output;
        for (int counter = 0; counter < input.size(); counter++)
        {
            output += decodeLetter(input[counter]);
        }
        return output;
    }
    else
    {
        throw
            std::exception("Code set not found.");
    }
}


const string MorseCode::encodeWord(const string& input) const
{
    if (isBuilt())
    {
        string output;
        for (int counter = 0; counter < input.length(); counter++)
        {
            output += encodeLetter(input[counter]);
            if (counter < input.length() - 1)
                output += " "; // Put spaces between Morse Code letters.
        }
        return output;
    }
    else
    {
        throw
            std::exception("Code set not found");
    }
}


const string MorseCode::interpret(const string& input) const
{
    if (isBuilt())
    {
        vector<string> currentLetters = parse(input);
        return decodeWord(currentLetters);
    }
    else
    {
        throw
            std::exception("Code set not found.");
    }
}


const bool MorseCode::buildCodeList(istream& input)
{
    codeList.clear(); // Initialize list.
    // Reference:
        // "std::list." _cplusplus.com_. cplusplus.com, 2015.
            // Web. 4 Dec. 2015.
            // <http://www.cplusplus.com/reference/list/list/>.
    string entry;
    char letter = ' ';
    string code;
    MorseLetter pair;
    while (input >> entry)
    {
        code = "";
        letter = entry[0]; // The first character of each line is a letter.
        for (int counter = 1; counter < entry.length(); counter++)
        {
            code += entry[counter]; // The following characters are Morse Code.
        }
        if (!testCode(code))
            return false;
        codeMap[letter] = code; // Build the map while building the list.
        pair.define(letter, code);
        codeList.push_back(pair);
    }
    return true;
}


const bool MorseCode::testCode(const string& inputCode) const
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
        "1110", "1111" }; // Checked against hand-drawn tree.
}


void MorseCode::buildCodeVec()
{
    codeVec = {}; // Initialize vector.
    codeVec.push_back(" "); // Put a space at the root of the tree.
    list<MorseLetter>::iterator iter = codeList.begin();
    int counter = 0;
    while (iter != codeList.end())
    {
        if (iter->hasCode() == standardVec[counter]) // Match found.
        {
            codeVec.push_back(iter->hasLetter());
            if (iter->hasCode().length() == 4) // Max depth.
            {
                for (int two = 0; two < 2; two++)
                {
                    codeVec.push_back("NULL"); // Establish leaf nodes.
                }
            }
            iter++;
        }
        else
            codeVec.push_back("NULL"); // Where a non-leaf has only one child.
        counter++;
    }
}
// Reference for Idea:
    // Kuhail, Mohammad. "Lecture 10: Introduction to Trees."
        // CS 303 course materials, University of Missouri-Kansas City,
        // Fall 2015. _Microsoft PowerPoint_ file. Slide 29.