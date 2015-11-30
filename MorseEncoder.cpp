// Alfred Ledgin
// 11/30/2015
// CS 303
// Project 3

#include "MorseCode.h"
#include "MorseEncoder.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;


void MorseEncoder::setDefinitions(const MorseCode& inputDefinitions)
{
    definitionSet = inputDefinitions;
    inputMap = definitionSet.accessMap();
}


const string MorseEncoder::encode(char letter) const
{
    if (definitionSet.isBuilt())
    {
        try
        {
            return inputMap.at(letter);
            // Reference:
                // "std::map::at." _cplusplus.com_. cplusplus.com, 2015. Web.
                    // 29 Nov. 2015.
                    // <http://www.cplusplus.com/reference/map/map/at/>.
        }
        catch (std::exception)
        {
            return "";
        }
    }
    else
        return "";
}