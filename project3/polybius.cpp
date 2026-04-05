/*
 * polybius.cpp
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





#include "polybius.h"
#include "utility.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string mixKey(string key) {
    key = toUpperCase(key);
    string cleanedKey = "";
    for (int i = 0; i < static_cast<int>(key.length()); i++) {
        char c = key[i];
        if (isalnum(static_cast<unsigned char>(c))) {
            cleanedKey += c;
        }
    }
    cleanedKey = removeDuplicate(cleanedKey);
    
    string alnum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string result = cleanedKey;
    for (int i = 0; i < static_cast<int>(alnum.length()); i++) {
        char c = alnum[i];
        bool found = false;
        for (int j = 0; j < static_cast<int>(result.length()) && !found; j++) {
            if (result[j] == c) {
                found = true;
            }
        }
        if (!found) {
            result += c;
        }
    }
    
    return result.substr(0, SIZE * SIZE);
}

void fillGrid(char grid[SIZE][SIZE], string content) {
    int index = 0;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            grid[row][col] = content[index];
            index++;
        }
    }
}

string findInGrid(char c, char grid[SIZE][SIZE]) {
    string result = "";
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == c) {
                result += to_string(row);
                result += to_string(col);
                return result;
            }
        }
    }
    return "";
}

string polybiusSquare(char grid[SIZE][SIZE], string key, string original, bool encrypt) {
    string result = "";
    
    string mixedKey = mixKey(key);
    fillGrid(grid, mixedKey);
    
    if (encrypt) {
        string cleanedMsg = "";
        for (int i = 0; i < static_cast<int>(original.length()); i++) {
            char c = original[i];
            if (isalnum(static_cast<unsigned char>(c)) || isspace(static_cast<unsigned char>(c))) {
                cleanedMsg += toupper(c);
            }
        }
        
        for (int i = 0; i < static_cast<int>(cleanedMsg.length()); i++) {
            char c = cleanedMsg[i];
            if (isspace(static_cast<unsigned char>(c))) {
                result += " ";
            } else if (isalnum(static_cast<unsigned char>(c))) {
                string coord = findInGrid(c, grid);
                result += coord;
            }
        }
    } else {
        string cleanedMsg = "";
        for (int i = 0; i < static_cast<int>(original.length()); i++) {
            char c = original[i];
            if (isdigit(static_cast<unsigned char>(c)) || isspace(static_cast<unsigned char>(c))) {
                cleanedMsg += c;
            }
        }
        
        string tempDigits = "";
        for (int i = 0; i < static_cast<int>(cleanedMsg.length()); i++) {
            char c = cleanedMsg[i];
            if (isspace(static_cast<unsigned char>(c))) {
                while (static_cast<int>(tempDigits.length()) >= 2) {
                    int row = charToInt(tempDigits[0]);
                    int col = charToInt(tempDigits[1]);
                    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
                        result += grid[row][col];
                    } else {
                        result += '?';
                    }
                    tempDigits = tempDigits.substr(2);
                }
                result += " ";
            } else if (isdigit(static_cast<unsigned char>(c))) {
                tempDigits += c;
            }
        }
        
        while (static_cast<int>(tempDigits.length()) >= 2) {
            int row = charToInt(tempDigits[0]);
            int col = charToInt(tempDigits[1]);
            if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
                result += grid[row][col];
            } else {
                result += '?';
            }
            tempDigits = tempDigits.substr(2);
        }
    }
    
    return result;
}
