/* File: deck.cpp
 * Course: CS216-00x
 * Project: Lab 8 (as part of Project 2)
 * Purpose: the implementation of member functions for the Deck class.
 * Author: Aiden Koknat
 */
#include <iostream>
#include <iomanip>
#include "card.h"
#include "deck.h"
#include <vector>

// Constructor
void Deck::createDeck() {
    deck.clear();
    for (int i = (int)Card::cSuits::Spade; i < (int)Card::cSuits::Spade + SUITS; i++) {
        for (Card::cPoints val = CARD_START; val < CARD_START + POINTS; val++) {
            Card::cSuits suit = static_cast<Card::cSuits>(i);
            Card Card(suit,val);
            deck.push_back(Card);
        }
    }
}

// Shuffle Deck
void Deck::shuffleDeck() {
    srand(time(0));
    Card temp;
    for (int i = deck.size() - 1; i>=1; i--) {
        int j = rand() % (i + 1);
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

Card Deck::deal_a_card() {
    Card c = deck.back();
    deck.pop_back();
    return c;
}
