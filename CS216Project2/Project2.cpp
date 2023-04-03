// Main file for project 2
// Course: CS216-00x
// Project: Project 2

#include <iostream>
#include <vector>
#include "pokerhand.h"
#include "deck.h"

using namespace std;

// avoid magic numbers
const int TOTALCARDS = 7;  // each player gets TOTALCARDS=7 cards
const int HANDS = 5;       // each player plays HANDS=5 cards in hand
vector<Card> play;
vector<Card> comp;

PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards)
        {    
            PokerHand bestH;
            PokerHand cardsH;

            // check if the parameter is valid
            if (cards.size() != TOTALCARDS)
            {
                cout << "Invalid Cards, we need SEVEN cards!" << endl;
                return cardsH; // return a PokerHand object by default constructor
            }

            // Consider all possible ways of dropping two cards
            // from all seven cards 
            // i is the index of the first card dropped
            // and j is the index of the second card dropped.
            // There are 21 different ways to pick 5 cards out of 7
            for (int i=0; i < TOTALCARDS; i++) 
            {
                for (int j=i+1; j < TOTALCARDS; j++) 
                {
                    Card pick[HANDS];
                    int index = 0;

                    // Iterate over all seven cards and assign them to the pick[] array
                    // exclude cards with index numbers of #i and #j.
                    for (int k=0 ; k < TOTALCARDS ; k++) 
                    {
                        if (k == i || k == j) 
                            continue;
                        pick[index] = cards[k];
                        index++;
                    }
                    
                    // create a PokerHand with pick[]
                    cardsH.setPokerHand(pick, HANDS);

                    // Check to see if current pick is better than
                    // the best you have seen so far
                    if (bestH.compareHand(cardsH) < 0)
                    {
                        bestH = cardsH ;
                    }
                }
            }
            return bestH;
        }

int main() {
    char quit = ' ';
    while (quit != 'Q' && quit != 'q') {
    PokerHand Player;
    Card player[TOTALCARDS];

    PokerHand Computer;
    Card computer[TOTALCARDS];

    Card shared[HANDS];

    // Creating deck and dealing cards:
    Deck deck;
    deck.createDeck();
    deck.shuffleDeck();
        for (int i = 0; i < 2; i++) { // Deal two cards each
            player[i] = deck.deal_a_card();
            computer[i] = deck.deal_a_card();
        }
        for (int i = 0; i < HANDS; i++) {
            shared[i] = deck.deal_a_card();
            player[i+2] = shared[i];
            computer[i+2] = shared[i];
        }
        //Player.setPokerHand(player, 7);
        //Computer.setPokerHand(computer,7);

        // Showing hands
        cout << "The cards in your hand are:" << endl;
        for (int i = 0; i < 2; i++) {
            player[i].print();
            cout << endl;
        }
        cout << "The FIVE cards on the deck to share are: " << endl;
        cout << "    *************************" << endl;
        for (int i = 0; i < HANDS; i++) {
            cout << "    *   ";
            shared[i].print();
            cout << "         *   " << endl;
        }
        cout << "    *************************" << endl;
        cout << "The cards in the computer's hand are: " << endl;
        for (int i = 0; i < 2; i++) {
            computer[i].print();
            cout << endl;
        }

        // Setting up Vector for player best_five:
        for (int i = 0; i < 2; i++)
            play.push_back(player[i]);
        for (int i = 0; i < HANDS; i++)
            play.push_back(shared[i]);

        cout << "Player 1: You" << endl;  // Showing best player hand
        Player = best_FIVE_out_of_SEVEN(play);
        Player.print();
        cout << endl << endl << endl;

        // Setting up Vector for computer best_five:
        for (int i = 0; i < 2; i++)
            comp.push_back(computer[i]);
        for (int i = 0; i < HANDS; i++)
            comp.push_back(shared[i]);

        cout << "Player 2: Computer" << endl; // Showing best computer hand
        Computer = best_FIVE_out_of_SEVEN(comp);
        Computer.print();
        cout << endl << endl << endl;

        if (best_FIVE_out_of_SEVEN(play).compareHand(best_FIVE_out_of_SEVEN(comp)) == 1)
            cout << "Congratulations, you win the game!" << endl;
        else if (best_FIVE_out_of_SEVEN(play).compareHand(best_FIVE_out_of_SEVEN(comp)) == -1)
            cout << "Sorry, the computer wins the game!" << endl;
        else
            cout << "It's a tie!" << endl;
        cout << "Do you want to play poker game again (Press 'Q' or 'q' to quit the program)?" << endl;
        cin >> quit;
    }
    cout << "Thank you for using this program!" << endl;
return 0;
}