// Alfred Ledgin
// 12/3/2015
// CS 303
// Project 3

#pragma once
#include "MorseSystem.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class MorseUI
{

    public:

        MorseUI() {;}


        void execute();

        
    private:

        void displayMenu();


        void obtainFile();


        void decodeWord();


        void encodeWord();


        void handleInput(string& inputString);


        bool quit;
        char menuOption;
        MorseSystem codeSystem;

};