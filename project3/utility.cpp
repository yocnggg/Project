/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Zihao.Yang
 * yocnggg
 *
 * EECS 183: Project 3
 * Winter 2026
 *
 * <#description#>
 */

#include "utility.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************


#include "utility.h"
#include <cctype>
#include <string>

using namespace std;

string toUpperCase(string original) {
    string result = "";
    for (int i = 0; i < original.length(); i++) {
        char c = original[i];
        if (islower(c)) {
            result += toupper(c);
        } else {
            result += c;
        }
    }
    return result;
}

string removeNonAlphas(string original) {
    string result = "";
    for (int i = 0; i < original.length(); i++) {
        char c = original[i];
        if (isalpha(c)) {
            result += c;
        }
    }
    return result;
}

string removeDuplicate(string original) {
    string result = "";
    for (int i = 0; i < original.length(); i++) {
        char c = original[i];
        
        bool found = false;
        for (int j = 0; j < result.length(); j++) {
            if (result[j] == c) {
                found = true;
                break;
            }
        }
        if (!found) {
            result += c;
        }
    }
    return result;
}

int charToInt(char original) {
    // Requires: original is a digit character ('0'-'9')
    return original - '0';
}


////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
