// FOR TESTING ONLY--DO NOT TURN IN
// Alfred Ledgin
// 11/28/2015
// CS 303
// Project 3

#include <iostream>
#include "MorseCode.h"
#include "MorseDecoder.h"
#include "MorseEncoder.h"
#include <fstream>
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
    system("pause");
    return 0;
}