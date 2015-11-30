// Alfred Ledgin
// 11/30/2015
// CS 303
// Project 3

#include "MorseCode.h"
#include "MorseInterpreter.h"
#include "MorseSystem.h"
#include "WordEncoder.h"
#include <iostream>
#include <string>


void MorseSystem::setInput(istream& input)
{
    definitionSet.buildCode(input);
    theInterpreter.setDefinitions(definitionSet);
    theEncoder.setDefinitions(definitionSet);
}