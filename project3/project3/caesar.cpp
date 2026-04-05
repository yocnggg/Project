/*
 * caesar.cpp
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



#include "caesar.h"
#include "utility.h"
#include <cctype>
#include <string>

using namespace std;

char shiftAlphaCharacter(char c, int n) {
    
    if (!isalpha(c)) {
        return c;
    }
    
    char base = isupper(c) ? 'A' : 'a';
  
    int shift = (n % 26 + 26) % 26;
    int originalPos = c - base;
    int newPos = (originalPos + shift) % 26;
    if (newPos < 0) {
        newPos += 26;
    }
    return base + newPos;
}

string caesarCipher(string original, int key, bool encrypt) {
    string result = "";
    int shift = encrypt ? key : -key;
    
    for (char c : original) {
        if (isalpha(c)) {
            result += shiftAlphaCharacter(c, shift);
        } else {
            result += c; 
        }
    }
    return result;
}
