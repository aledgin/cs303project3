// Alfred Ledgin
// 11/30/2015
// CS 303
// Project 3

#include "Binary_Tree.h"
#include "MorseDecoder.h"
#include <iostream>
#include <string>
using namespace std;


void MorseDecoder::setDefinitions(const MorseCode& inputDefinitions)
{
    definitionSet = inputDefinitions;
    inputTree = definitionSet.accessTree();
}


const char MorseDecoder::decode(const string& codedLetter) const
{
    if (definitionSet.isBuilt())
    {
        try
        {
            return decodeInternal(codedLetter, 0, inputTree)[0];
        }
        catch (std::exception)
        {
            return ' ';
        }
    }
    else
        return ' ';
}


const string MorseDecoder::decodeInternal(const string& codedLetter, int index,
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
            return decodeInternal(codedLetter, index + 1,
            tempTree.get_left_subtree());
        else
            return decodeInternal(codedLetter, index + 1,
            tempTree.get_right_subtree());
    }
}
// Reference for Binary Tree Functions:
    // Kuhail, Mohammad. "Lecture 10: Introduction to Trees."
        // CS 303 course materials, University of Missouri-Kansas City,
        // Fall 2015. _Microsoft PowerPoint_ file. Slide 24.