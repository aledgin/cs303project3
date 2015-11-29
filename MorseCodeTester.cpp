// FOR TESTING ONLY--DO NOT TURN IN
// Alfred Ledgin
// 11/28/2015
// CS 303
// Project 3

#include <iostream>
#include "MorseCode.h"
#include <fstream>
using namespace std;


int main()
{
    ifstream file;
    file.open("morse.txt");
    MorseCode testCode(file);
    cout << testCode.showCodeTree() << endl;
    file.close();
    system("pause");
    return 0;
}