/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * ZIhao.Yang
 * yocnggg
 *
 * EECS 183: Project 3
 * Winter 2026
 *
 * <#description#>
 */

#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include "utility.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string normalizeInput(string input) {
    int inputLen = static_cast<int>(input.length());
    int start = 0;
    while (start < inputLen && isspace(static_cast<unsigned char>(input[start]))) {
        start++;
    }
    
    int end = inputLen - 1;
    while (end >= 0 && isspace(static_cast<unsigned char>(input[end]))) {
        end--;
    }
    
    string trimmed = "";
    if (start <= end) {
        trimmed = input.substr(static_cast<size_t>(start), static_cast<size_t>(end - start + 1));
    }
    
    string lower = "";
    for (int i = 0; i < static_cast<int>(trimmed.length()); i++) {
        char c = trimmed[i];
        lower += tolower(static_cast<unsigned char>(c));
    }
    return lower;
}

void ciphers() {
    string cipherChoice;
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    getline(cin, cipherChoice);
    string normCipher = normalizeInput(cipherChoice);
    
    bool isCaesar = (normCipher == "caesar" || normCipher == "c");
    bool isVigenere = (normCipher == "vigenere" || normCipher == "v");
    bool isPolybius = (normCipher == "polybius" || normCipher == "p");
    if (!isCaesar && !isVigenere && !isPolybius) {
        cout << "Invalid cipher!" << endl;
        return;
    }
    
    string modeChoice;
    cout << "Encrypt or decrypt: ";
    getline(cin, modeChoice);
    string normMode = normalizeInput(modeChoice);
    
    bool encrypt = (normMode == "encrypt" || normMode == "e");
    bool decrypt = (normMode == "decrypt" || normMode == "d");
    if (!encrypt && !decrypt) {
        cout << "Invalid mode!" << endl;
        return;
    }
    
    string message;
    cout << "Enter a message: ";
    getline(cin, message);
    
    if (isCaesar) {
        int key;
        cout << "What is your key: ";
        cin >> key;
        cin.ignore();
        
        string result = caesarCipher(message, key, encrypt);
        cout << "The " << (encrypt ? "encrypted" : "decrypted") << " message is: " << result << endl;
    } else if (isVigenere) {
        string keyword;
        cout << "What is your key: ";
        getline(cin, keyword);
        
        string cleanedKeyword = removeNonAlphas(keyword);
        if (cleanedKeyword.empty()) {
            cout << "Invalid key!" << endl;
            return;
        }
        
        string result = vigenereCipher(message, keyword, encrypt);
        cout << "The " << (encrypt ? "encrypted" : "decrypted") << " message is: " << result << endl;
    } else if (isPolybius) {
        string key;
        cout << "What is your key: ";
        getline(cin, key);
        
        bool keyHasInvalidChar = false;
        for (int i = 0; i < static_cast<int>(key.length()) && !keyHasInvalidChar; i++) {
            char c = key[i];
            if (!isalnum(static_cast<unsigned char>(c))) {
                keyHasInvalidChar = true;
            }
        }
        if (keyHasInvalidChar) {
            cout << "Invalid key!" << endl;
            return;
        }
        
        string cleanedKey = "";
        for (int i = 0; i < static_cast<int>(key.length()); i++) {
            cleanedKey += key[i];
        }
        if (cleanedKey.empty()) {
            cout << "Invalid key!" << endl;
            return;
        }
        
        string polyKey = toUpperCase(cleanedKey);
        polyKey = removeDuplicate(polyKey);
        
        bool validMsg = true;
        int msgLen = static_cast<int>(message.length());
        for (int i = 0; i < msgLen && validMsg; i++) {
            char c = message[i];
            if (!isalnum(static_cast<unsigned char>(c)) && !isspace(static_cast<unsigned char>(c))) {
                validMsg = false;
            }
        }
        if (!validMsg) {
            cout << "Invalid message!" << endl;
            return;
        }
        
        char grid[SIZE][SIZE];
        string result = polybiusSquare(grid, polyKey, message, encrypt);
        cout << "The " << (encrypt ? "encrypted" : "decrypted") << " message is: " << result << endl;
    }
}




