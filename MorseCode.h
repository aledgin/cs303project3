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
    // This class serves to handle all relevant functions pertaining to an
    // alphabet of Morse Code symbols.  It requires a Morse Code alphabet to
    // be defined from input, and it then facilitates encoding and decoding of
    // words in Morse Code according to the alphabet definition.
{

    public:

        MorseCode();
        // Preconditions: A MorseCode object (hereafter known as a Morse Code
            // set or, simply, code set) needs to be created.
        // Postconditions: This default constructor allows a Morse Code set to
            // be built by first creating the standard vector needed to define
            // the Morse Code alphabet.
    

        MorseCode(istream& input);
        // Preconditions: A MorseCode object needs to be created with the given
            // input source for alphabet definition.
        // Postconditions: This constructor attempts to build a code set using
            // given input source for alphabet definition, by first creating
            // needed vector and then calling the buildCode() function.


        void buildCode(istream& input);
        // Preconditions: The Morse Code set needs to be built using the given
            // input source for alphabet definition.
        // Postconditions: This function attempts to build and sort a list of
            // MorseLetter objects using the given input source for alphabet
            // definition.  It then builds a corresponding vector and binary
            // tree.  If all operations are successful, it sets a Boolean flag
            // to true to indicate that the code set has been built.


        const bool isBuilt() const {return codeBuilt;}
        // Preconditions: A calling function needs to know whether the code set
            // has been built.
        // Postconditions: This function returns the Boolean indicator of
            // whether the code set has been built.


        const string showCodeTree() const {return codeTree.to_string();}
        // Reference:
            // Kuhail, Mohammad. "Binary_Tree.h" 2015. C++ header (.h) file.
        // Preconditions: When testing the Morse Code set, one wishes to know
            // whether the binary tree has been successfully built.
        // Postconditions: This function returns the string representation of
            // binary tree used for the Morse Code alpahbet definition.


        const vector<string> parse(const string& input) const;
        // Preconditions: A string of Morse Code symbols has been input.
        // Postconditions: This function separates each coded letter in a given
            // string of Morse Code symbols, storing the coded letters in a
            // vector.


        const char decodeLetter(const string& codedLetter) const;
        // Preconditions: A string of Morse Code characters representing
            // a single letter needs to be decoded.
        // Postconditions: This function tests the given string and the status
            // of the code set definition, and then calls an internal function
            // to use the binary tree for alphabet definition in order to
            // decode the Morse Code string representing a letter.


        const string encodeLetter(char letter) const;
        // Preconditions: A given letter needs to be encoded in Morse Code.
        // Postconditions: This function uses a map storing Morse Code symbols
            // corresponding to letters in order to encode the given letter
            // as a string of Morse Code characters.


        const string decodeWord(const vector<string>& input) const;
        // Preconditions: A vector storing strings corresponding to Morse Code
            // symbols needs to be decoded as the corresponding word.
        // Postconditions: This function calls the decodeLetter() function in
            // order to decode the word stored in the vector.


        const string encodeWord(const string& input) const;
        // Preconditions: A given word needs to be encoded as a string of Morse
            // Code symbols.
        // Postconditions: This function calls the encodeLetter() function in
            // order to encode the word as a string of Morse Code symbols.


        const string interpret(const string& input) const;
        // Preconditions: A of Morse Code characters representing a word needs
            // to be decoded.
        // Postconditions: This function calls the parse() function to separate
            // the Morse Code letters in the given string and then calls the
            // decodeWord() function to decode the resulting vector.


    private:


        const string decodeLetterInternal(const string& codedLetter,
            int index, Binary_Tree<string> tempTree) const;
        // Preconditions: The decodeLetter() function has been called and is
            // able to decode a given Morse Code letter.
        // Postconditions: This function recursively traverses the binary tree
            // used for the Morse Code alphabet definition and returns the
            // letter corresponding to the given Morse Code symbols.


        const bool buildCodeList(istream& input);
        // Preconditions: A list of MorseLetter objects needs to be built
            // according to the input definition of a Morse Code alphabet.
        // Postconditions: This function iterates through the input Morse
            // Code alphabet definition, builds a map of key letters and
            // Morse Code entries, and then builds a resulting list of
            // MorseLetter objects.


        const bool testCode(const string& inputCode) const;
        // Preconditions: A string representing a letter in Morse Code needs
            // to be tested in order to ensure that each character is either
            // a '.' or a '_'.
        // Postconditions: This function iterates through the given string and
            // returns true if all characters are valid, and false otherwise.


        void defineStandardVec();
        // Preconditions: A vector of binary strings is needed as a guide for
            // building the binary tree used for the Morse Code alphabet
            // definition.
        // Postconditions: This function builds a vector of binary strings with
            // lengths between 1 and 4 digits, in the order in which they would
            // appear in a binary tree in which the root is null, 0s point to
            // left, and 1s point to the right.


        void buildCodeVec();
        // Preconditions: A vector of binary strings needs to be built from a
            // sorted list of MorseLetter objects, in order to build the binary
            // tree used for the Morse Code alphabet definition.
        // Postconditions: This function iterates through both the list of
            // MorseLetter objects and the vector of binary strings built by
            // the defineStandardVec() function, comparing each MorseLetter's
            // binary string to the next string in the standardVec.  When the
            // MorseLetter binary string matches the entry in the standardVec,
            // the letter from the MorseLetter object is inserted into the new
            // vector.  Whenever an entry in the standardVec is absent from the
            // list containing MorseLetter binary strings, a null entry is
            // inserted into the new vector.  Two null entries are inserted
            // when the position representing the maximum depth of the binary
            // tree is reached.


        Binary_Tree<string> codeTree;
        map<char, string> codeMap;
        list<MorseLetter> codeList;
        vector<string> standardVec;
        vector<string> codeVec;
        bool codeBuilt;

};