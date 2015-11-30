// FOR TESTING ONLY--DO NOT TURN IN
// Alfred Ledgin
// 11/28/2015
// CS 303
// Project 3

#include <iostream>
#include "MorseCode.h"
#include "MorseDecoder.h"
#include "MorseEncoder.h"
#include "WordDecoder.h"
#include "WordEncoder.h"
#include "MorseParser.h"
#include "MorseInterpreter.h"
#include <fstream>
#include <vector>
using namespace std;


int main()
{
    ifstream file;
    file.open("morse.txt");
    MorseCode testCode(file);
    file.close();
    cout << testCode.showCodeTree() << endl;
    cout << "***" << endl;
    MorseDecoder theDecoder(testCode);
    cout << theDecoder.decode("_..") << endl;
    cout << "***" << endl;
    MorseEncoder theEncoder(testCode);
    cout << theEncoder.encode('c') << endl;
    cout << "***" << endl;
    vector<string> decodeTestVec;
    decodeTestVec = { "_..", "__." };
    WordDecoder toDecodeWords(testCode);
    cout << toDecodeWords.decode(decodeTestVec) << endl;
    cout << "***" << endl;
    WordEncoder toEncodeWords(testCode);
    cout << toEncodeWords.encode("ac") << endl;
    cout << "***" << endl;
    MorseParser theParser("_.. __. _.. __.");
    vector<string> decodeTestVec2 = theParser.parse();
    cout << toDecodeWords.decode(decodeTestVec2) << endl;
    cout << "***" << endl;
    MorseInterpreter theInterpreter(testCode);
    cout << theInterpreter.interpret("_.. __. _.. __. _.. __.") << endl;
    system("pause");
    return 0;
}