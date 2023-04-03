/* File: term.cpp
 * Course: CS216-00x
 * Project: Lab12 (as part of Project 3)
 * Purpose: the implementation for the Term class.
 */
#ifndef TERM_CPP
#define TERM_CPP
#include "term.h"
#include <iostream>

using namespace std;
#include <string>

Term::Term() {
    string query = " ";
    long weight = 0;
}

Term::Term(string q, long w) {
    query = q;
    weight = w;
}

int Term::compareByWeight(const Term& T1, const Term& T2) {
    if (T1.weight > T2.weight)
        return 1;
    if (T1.weight == T2.weight)
        return 0;
    else
        return -1;
}

int Term::compareByPrefix(const Term& T1, const Term& T2, int r) {
    string a = T1.query;
    string b = T2.query;
    if (a.substr(0,r) < b.substr(0,r))
        return 1;
    if (a.substr(0,r) == b.substr(0,r))
        return 0;
    else
        return -1;
}

bool operator<(const Term& T1, const Term& T2) {
    string a = T1.query;
    string b = T2.query;
    if (a < b)
        return true;
    else
        return false;
}

ostream& operator<<(ostream &out, const Term& t) {
    out << t.weight << "    " << t.query;
}

#endif