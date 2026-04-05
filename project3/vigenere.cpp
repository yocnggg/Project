/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Zihao.Yang
 *yocnggg
 *
 * EECS 183: Project 3
 * Winter 2026
 *
 * <#description#>
 */



#include "vigenere.h"
#include "caesar.h"
#include "utility.h"
#include <cctype>
#include <string>

using namespace std;

string vigenereCipher(string original, string keyword, bool encrypt) {
    string result = "";
    
    string cleanKeyword = toUpperCase(removeNonAlphas(keyword));
    
    int keyLen = static_cast<int>(cleanKeyword.length());
    int keyIndex = 0;

    for (int i = 0; i < static_cast<int>(original.length()); i++) {
        char c = original[i];
        if (isalpha(static_cast<unsigned char>(c))) {
            
            char keyChar = cleanKeyword[keyIndex % keyLen];
            int shift = keyChar - 'A';
            if (!encrypt) {
                shift = -shift;
            }
            result += shiftAlphaCharacter(c, shift);
            keyIndex++;
        } else {
            result += c;
        }
    }

    return result;
}
