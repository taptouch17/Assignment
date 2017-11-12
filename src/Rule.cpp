//
//  Rule.cpp
//  
//
//  Created by Jelani on 25/09/2017.
//

#include "Rule.h"
#include <iostream>
#include <vector>

using namespace std;




Rule::Rule(char c, string s) {
    fromChar = c;
    toString = s;
}

char Rule::getOfChar() {
    return fromChar;
}

string Rule::getToString() {
    return toString;
}

void Rule::setOfChar(char theChar) {
    fromChar = theChar;
}

void Rule::setToString(string theString) {
    toString = theString;
}
