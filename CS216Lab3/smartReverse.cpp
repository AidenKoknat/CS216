/* 
 * File: smartReverse.cpp
 * Purpose: provide the implementation of the smartReverse class
 *
 * Author: Aiden Koknat
 *
 */

#include <stack>
#include "smartReverse.h"

// default constructor
smartReverse::smartReverse()
{	
    str = "";
}

// constructor: initialize str with ini_str passing as a parameter
smartReverse::smartReverse(string ini_str)
{
    str = ini_str;
}

// return the current value of the private data member: str
string smartReverse::getString() const
{
    return str;
}

// set the value of str to be the passed in parameter input_str
void smartReverse::setString(string input_str)
{
    str = input_str;
}

// return a reverse string from str
// using a loop to implement
// Note that str has not been changed
string smartReverse::rev_loop() const
{
    string rev = "";
    int i;

    for (i = str.size()-1; i >= 0; i--) {
	    rev += str[i];
    }
return rev;
}

// return a reverse string from str
// using recursion to implement
// Note that str has not been changed
string smartReverse::rev_recursive() const
{
	if (int x = str.length() <= 1) {
		return str;
	}
	else {
        string recurString = str.substr(0,str.length()-1);
        smartReverse sr(recurString);
		return((str[str.length()-1]+sr.rev_recursive()));
	}
}

// return a reverse string from str
// using a stack to implement
// Note that str has not been changed
string smartReverse::rev_stack() const
{
    string answer;
    int index;

    stack<char> revStr;
    for(index = 0; index < str.size(); index++) {
        revStr.push(str[index]);
    }

    while(!revStr.empty()) {
        answer += revStr.top();
        revStr.pop();
    }
    
    return answer;
}

