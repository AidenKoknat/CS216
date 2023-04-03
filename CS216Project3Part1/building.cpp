/* File: building.cpp
 * Course: CS216-00x
 * Project: Lab11 (as the first part of project 3)
 * Purpose: the implementation of member functions for the Building class.
 */

#include <iomanip>
#include <iostream>
#include <algorithm>  //std::swap (c++98)  it is defined in <utility> in c++11
#include "building.h"

Building::Building() {
    name = "";
    ID = 0;
    coordinate = "";
}

Building::Building(string Name, int id, string position) {
    name = Name;
    ID = id;
    coordinate = position;
}

string Building::get_Name() const {
    return name;
}

int Building::get_ID() const {
    return ID;
}

string Building::get_Coordinate() const {
    return coordinate;
}

int Building::compareByPrefix(const Building& b1, const Building& b2, int r) {
    string a = b1.name;
    string b = b2.name;
    if (a.substr(0,r) < b.substr(0,r))
        return 1;
    if (a.substr(0,r) == b.substr(0,r))
        return 0;
    else
        return -1;
    
}

int Building::compareByID(const Building& B1, const Building& B2) {
    if (B1.ID < B2.ID)
        return 1;
    if (B1.ID == B2.ID)
        return 0;
    else
        return -1;
}

int Building::compareByReverseCoordinate(const Building& B1, const Building& B2) {
    if (B1.coordinate > B2.coordinate)
        return 1;
    if (B1.coordinate == B2.coordinate)
        return 0;
    else
        return -1;
    
}

bool Building::operator<(const Building& other) {
    if (this->name < other.name)
        return true;
    else
        return false;
    
}

ostream& operator<<(ostream &out, const Building& b) {
    out << setfill(' ') << left << setw(27) << b.name << right << " ( ID: " << setw(4) << setfill('0') << b.ID << " ) ---> " << b.coordinate;
    return out;
}

