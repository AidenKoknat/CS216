/* File: card.cpp
 * Course: CS216-00x
 * Project: Lab 8 (as part of Project 2)
 * Purpose: the implementation of member functions for the Card class.
 * Author: Aiden Koknat
 */
#include "card.h"
#include <iostream>
#include <iomanip>

// Default constructor marks card as invalid
Card::Card() {
    point = 0;
    suit = cSuits::Invalid;
}

// Alternate constructor
Card::Card(cSuits s, cPoints p) 
{
    suit = s;
    point = p;
}

// access the card point value
Card::cPoints Card::getPoint() const
{
    return point;
}

// access the card suit value
Card::cSuits Card::getSuit() const
{
    return suit;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other) const
{
    if (this->point > other.point)  
        return 1;
    if (this->point < other.point)
        return -1;
    else
        return 0;
}

// Display a description of the Card object to standard output
// The output should look like:
//   the sign of suit, followed by the point, then followed by the sign of suit again   
void Card::print() const
{
        if (point == 11) {
            if (suit == cSuits::Heart)
                cout << HEART << setw(2) << "J" << HEART;
            if (suit == cSuits::Spade)
                cout << SPADE << setw(2) << "J" << SPADE;
            if (suit == cSuits::Club)
                cout << CLUB << setw(2) << "J" << CLUB;
            if (suit == cSuits::Diamond)
                cout << DIAMOND << setw(2) << "J" << DIAMOND;   
        }
        if (point == 12) {
            if (suit == cSuits::Heart)
                cout << HEART << setw(2) << "Q" << HEART;
            if (suit == cSuits::Spade)
                cout << SPADE << setw(2) << "Q" << SPADE;
            if (suit == cSuits::Club)
                cout << CLUB << setw(2) << "Q" << CLUB;
            if (suit == cSuits::Diamond)
                cout << DIAMOND << setw(2) << "Q" << DIAMOND;
        } 
        if (point == 13) {
            if (suit == cSuits::Heart)
                cout << HEART << setw(2) << "K" << HEART;
            if (suit == cSuits::Spade)
                cout << SPADE << setw(2) << "K" << SPADE;
            if (suit == cSuits::Club)
                cout << CLUB << setw(2) << "K" << CLUB;
            if (suit == cSuits::Diamond)
                cout << DIAMOND << setw(2) << "K" << DIAMOND;
        }
        if (point == 14) {
            if (suit == cSuits::Heart)
                cout << HEART << setw(2) << "A" << HEART;
            if (suit == cSuits::Spade)
                cout << SPADE << setw(2) << "A" << SPADE;
            if (suit == cSuits::Club)
                cout << CLUB << setw(2) << "A" << CLUB;
            if (suit == cSuits::Diamond)
                cout << DIAMOND << setw(2) << "A" << DIAMOND;
        }
        if ((point > 1) && (point < 11)) {
        if (suit == cSuits::Heart)
            cout << HEART << setw(2) << point << HEART;
        if (suit == cSuits::Spade)
            cout << SPADE << setw(2) << point << SPADE;
        if (suit == cSuits::Club)
            cout << CLUB << setw(2) << point << CLUB;
        if (suit == cSuits::Diamond)
            cout << DIAMOND << setw(2) << point << DIAMOND;
        }
}       
