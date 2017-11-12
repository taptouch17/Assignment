//
//  Rule.hpp
//  
//
//  Created by Jelani on 25/09/2017.
//

#ifndef Rule_hpp
#define Rule_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Rule {
private:
    char fromChar;
    string toString;
    
public:
    Rule(char c, string s);
    char getOfChar();
    void setOfChar(char theChar);
    string getToString();
    void setToString(string theString);
    
};

#endif /* Rule_hpp */
