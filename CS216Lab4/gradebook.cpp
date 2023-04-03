/* 
 * File:   gradebook.cpp
 * Course: CS216
 * Project: Lab4
 * Purpose: provide the implementation of the member functions of gradebook class
 *
 * Author: Aiden Koknat
 *
 */
#include <iostream>
#include "gradebook.h"

// default constructor
gradebook::gradebook()
{
    // do nothing
    // vector class from STL provide default constructor
}

// return the size of the gradebook
int gradebook::getSize() const
{
   return  scores.size();
}

// insert a score into the tail of the gradebook
void gradebook::insert(double score)
{
    scores.push_back (score);
}

// return the maximum score among all scores in the gradebook
double gradebook::getMax() const
{
    int max = scores.at(0);
    for (int i = 0; i < scores.size(); i++) {
        if (scores.at(i) > max) {
            max = scores.at(i);
        }
         else;
    }
    return max;
}

// return the minimum score among all scores in the gradebook
double gradebook::getMin() const
{
    int min = scores.at(0);
    for (int i = 0; i < scores.size(); i++) {
        if (scores.at(i) < min)
            min = scores.at(i);
        else;
    }
    return min;
}

// return the average score among all scores in the gradebook
double gradebook::getAverage() const
{
    int avg = 0;
    for (int i = 0; i < scores.size(); i++) {
       avg = avg + scores.at(i);
    }
    avg = avg / scores.size();
    return avg;
}

// each score in the gradebook will be increased by the given value 
// If the score reaches MAX_SCORE, it does not go beyond
void gradebook::incrementScore(double value) {
    for (int i = 0; i < scores.size(); i++) {
        if ((scores.at(i) + value) > MAX_SCORE) {
            scores.at(i) = MAX_SCORE;
        }
        else {
            scores.at(i) = scores.at(i) + value;
        }
    }
}
// print the scores in the gradebook
// in the following format: (Score No.:    value)
// For example:
// Score 1:    78.50
// Score 2:    90.00
// Score 3:    87.00
void gradebook::print() const
{
    for (int i = 0; i < scores.size(); i++) {
        cout << "Score " << i+1 << ":    " << scores.at(i) << endl;
    }
}

