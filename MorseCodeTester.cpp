//// This has been commented out so that MorseUI.cpp will run instead.
//// FOR TESTING ONLY--DO NOT TURN IN
//// Alfred Ledgin
//// 12/3/2015
//// CS 303
//// Project 3
//
//#include <iostream>
//#include "MorseCode.h"
//#include "MorseSystem.h"
//#include <fstream>
//#include <vector>
//using namespace std;
//
//
//int main()
//{
//    ifstream file;
//    file.open("morse.txt");
//    MorseCode testCode(file);
//    file.close();
//    cout << testCode.showCodeTree() << endl;
//    cout << "***" << endl;
//    cout << testCode.decodeLetter("_..") << endl;
//    cout << "***" << endl;
//    cout << testCode.encodeLetter('C') << endl;
//    cout << "***" << endl;
//    vector<string> decodeTestVec;
//    decodeTestVec = { "_..", "__." };
//    cout << testCode.decodeWord(decodeTestVec) << endl;
//    cout << "***" << endl;
//    cout << testCode.encodeWord("ac") << endl;
//    cout << "***" << endl;
//    vector<string> decodeTestVec2 = testCode.parse("_.. __. _.. __.");
//    cout << testCode.decodeWord(decodeTestVec2) << endl;
//    cout << "***" << endl;
//    cout << testCode.interpret("_.. __. _.. __. _.. __.") << endl;
//    cout << "***" << endl;
//    MorseSystem theSystem;
//    file.open("morse.txt");
//    theSystem.setInput(file);
//    file.close();
//    cout << theSystem.decodeWord("_.. __. _.. __. _.. __. _.. __.") << endl;
//    system("pause");
//    return 0;
//}
//// Reference for tested input:
//    // Kuhail, Mohammad. "Project 3." Project assignment sheet,
//        // CS 303 course materials, University of Missouri-Kansas City,
//        // Fall 2015. PDF file. Pages 4-5.