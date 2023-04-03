/* File: pokerhand.cpp
 * Course: CS216-00x
 * Project: Project 2
 * Purpose: the implementaion for the PokerHand class.
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include "pokerhand.h"
using namespace std;

PokerHand::PokerHand() { // Default Constructor, marks private stuff as invalid.
    cards[HANDS]; // Do I need to make these 0 values?
    Rank hand_rank(Rank::hRanks::NoRank, 0);
}

void PokerHand::sort() { // Sorts the hand into descending order
    int arrayLength = 5;
    Card tempCard;
    for (int i = 0; i < arrayLength; i++) {
        for (int j = i + 1; j < arrayLength; j++) {
            if (cards[j].getPoint() > cards[i].getPoint()) {
                tempCard = cards[j];
                cards[j] = cards[i];
                cards[i] = tempCard;
            }
        }
    }
}

bool PokerHand::isAllOneSuit() const { // Checks if the cards are the same suit, used for flushes.
    int flushCount = 1;
    int maxFlushCount = 1;
        for (int i = 0; i < HANDS-1; i++) {
            if (cards[i+1].getSuit() == cards[i].getSuit()) {
                flushCount++;
                if (flushCount > maxFlushCount)
                    maxFlushCount = flushCount;
            }
            else
                flushCount = 1;
        }
    if (maxFlushCount > 4)
        return true;
    else
        return false;
}

bool PokerHand::isSequence() const { // Checks if cards are in a continuous sequence
    int straightLength = 1;
    int straightMax = 1;
        for (int l = 0; l < HANDS-1; l++) {
            if (cards[l+1].getPoint() == (cards[l].getPoint())) {
                straightLength++;
                if (straightLength > straightMax) 
                    straightMax = straightLength;
            }
            else 
                straightLength = 1;
            }
        if (straightMax > 4) {
            return true;
        }
        else
            return false;
}

int PokerHand::findMatch() { // Checks if a single card has matches for pairs, three of a kind, or four of a kind.
    
    int maxtick = 1; // counts max mode of cards
    int fullHousePairTick = 1;
    for (int i = 0; i < HANDS; i++) {
        int tick = 1; // temporary match counter
        for (int j = 0; j < HANDS; j++) {
            if (i != j) {
                if (cards[i].getPoint() == cards[j].getPoint())
                    tick++;  
            }
        }
        if (tick > maxtick)
            maxtick = tick;
        if (maxtick == 3) { // Checks for Full House
            for (int j = 0; j < PokerHand::HANDS; j++) {
                for (int k = 0; k < PokerHand::HANDS; k++) {
                    if (j != i) {
                        if (j != k) {
                            if (cards[j].getPoint() == cards[k].getPoint()) 
                                fullHousePairTick++;
                        }
                    }
                }
            }       
        }
    }
    if ((maxtick == 3) && (fullHousePairTick == 2))
        return 6;
    else
        return maxtick;
}
 
void PokerHand::setPokerHand(Card in_hand[], int size) { // Sets poker hand into memory
    if (size != HANDS)
        cout << "Invalid number of cards!" << endl;
    else {
        for (int i = 0; i < HANDS; i++) {
            cards[i] = in_hand[i];
        }
    }
    // Evaluating/Determining Rank of Hand::
    sort();
    isStraightFlush(); // works
    isFourOfAKind();
    isFullHouse();
    isFlush(); // works
    isStraight(); // works
    isThreeOfAKind();
    isPair();
    isHighCard();
}

int PokerHand::compareHand(const PokerHand &otherHand) const {
    if (this->hand_rank.kind == Rank::hRanks::NoRank || otherHand.hand_rank.kind == Rank::hRanks::NoRank) {
        if (this->hand_rank.kind == Rank::hRanks::NoRank && otherHand.hand_rank.kind == Rank::hRanks::NoRank) 
            return 0; // Invalid
        if (this->hand_rank.kind == Rank::hRanks::NoRank && otherHand.hand_rank.kind != Rank::hRanks::NoRank)
            return -1; // Player hand lost
        else 
            return 1; // Player hand wins
    }
    else {
        if (this->hand_rank.kind > otherHand.hand_rank.kind)
            return 1; // Player hand wins
        if (this->hand_rank.kind < otherHand.hand_rank.kind)
            return -1; // Player hand loses
        if (this->hand_rank.kind == otherHand.hand_rank.kind)
            return 0; // Tie
    }
}

void PokerHand::print() const { // Prints out the five cards, and its rank.
    cout << "Five cards:" << endl;
    for (int i = 0; i < HANDS; i++) {
        cards[i].print();
        cout << endl;
    }
    cout << endl;
    cout << "Its rank is: ";
    hand_rank.print();
}

Rank PokerHand::getRank() const { // Returns the rank of the hand
    return hand_rank;
} 

bool PokerHand::isStraightFlush() { // Determines if hand is Straight Flush
    if ((isAllOneSuit() == true) && (isSequence() == true)) {
        Rank result(Rank::hRanks::StraightFlush, 8);
        hand_rank = result;
        return true;
    }
    else
        return false;
    
}

bool PokerHand::isFourOfAKind() { // Determines if hand is Four of a Kind 
    if (findMatch() == 4) {
        Rank result(Rank::hRanks::FourOfAKind, 7);
        hand_rank = result;
        return true;
    }
    else
        return false;
}

bool PokerHand::isFullHouse() { // Determines if hand is Full House
    if (findMatch() == 6) {
        Rank result(Rank::hRanks::FullHouse, 6);
        hand_rank = result;
        return true;
    }
    else
        return false;
}

bool PokerHand::isFlush() { // Determines if hand is Flush
    if (isSequence() == false) {
        if (isAllOneSuit() == true) {
            Rank result(Rank::hRanks::Flush, 5);
            hand_rank = result;
            return true;
        }
        else
            return false;
    }
    if (isSequence() == true)
        return false;
}

bool PokerHand::isStraight() { // Checking for Straight
    if (isAllOneSuit() == false) {
        if (isSequence() == true) {
            Rank result(Rank::hRanks::Straight, 4);
            hand_rank = result;
            return true;
        }
        else
            return false;
    }
    if (isAllOneSuit() == true)
        return false;
    
}

bool PokerHand::isThreeOfAKind() { // Determines if hand is Three of a Kind
              if (findMatch() == 3) {
                Rank result(Rank::hRanks::ThreeOfAKind, 3);
                hand_rank = result;
                return true;
              }
              else
                return false;
}

bool PokerHand::isPair() { // Determines if hand is Pair
    if (findMatch() == 2) {
        Rank result(Rank::hRanks::Pair, 2);    
        hand_rank = result;
        return true;
        }
    else
        return false;
}

bool PokerHand::isHighCard() { // Determines if hand is High Card
    if (isStraightFlush())
        return false;
    if (isFourOfAKind() == true)
        return false;
    if (isFullHouse() == true)
        return false;
    if (isFlush() == true)
        return false;
    if (isStraight() == true)
        return false;
    if (isThreeOfAKind() == true)
        return false;
    if (isPair() == true)
        return false;
    else {
        Rank result(Rank::hRanks::HighCard, 1);
        hand_rank = result;
        return true;
    }
}   

        

         

