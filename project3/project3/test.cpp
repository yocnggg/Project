

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void testToUpperCase();
void testRemoveNonAlphas();
void testRemoveDuplicate();
void testCharToInt();
void testShiftAlphaCharacter();
void testCaesarCipher();
void testVigenereCipher();
void testMixKey();
void testFillGrid();
void testFindInGrid();
void testPolybiusSquare();

void startTests() {
    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testShiftAlphaCharacter();
    testCaesarCipher();
    testVigenereCipher();
    testMixKey();
    testFillGrid();
    testFindInGrid();
    testPolybiusSquare();
}

// 1. toUpperCase
void testToUpperCase() {
    cout << "Testing toUpperCase()" << endl;
    cout << "Expected: ABC, Actual: " << toUpperCase("abc") << endl;
    cout << "Expected: HELLO WORLD!, Actual: " << toUpperCase("Hello World!") << endl;
    cout << "Expected: 123XYZ, Actual: " << toUpperCase("123xyz") << endl;
}

// 2. removeNonAlphas
void testRemoveNonAlphas() {
    cout << "\nTesting removeNonAlphas()" << endl;
    cout << "Expected: Hello, Actual: " << removeNonAlphas("Hello!@#123") << endl;
    cout << "Expected: abc, Actual: " << removeNonAlphas("a1b2c3") << endl;
    cout << "Expected: , Actual: '" << removeNonAlphas("123!@#") << "'" << endl;
}

// 3. removeDuplicate
void testRemoveDuplicate() {
    cout << "\nTesting removeDuplicate()" << endl;
    cout << "Expected: HELOWRD, Actual: " << removeDuplicate("HELLOWORLD") << endl;
    cout << "Expected: ABC12, Actual: " << removeDuplicate("AABBC1122") << endl;
    cout << "Expected: AB, Actual: " << removeDuplicate("AAAAABBBBB") << endl;
}

// 4. charToInt
void testCharToInt() {
    cout << "\nTesting charToInt()" << endl;
    cout << "Expected: 0, Actual: " << charToInt('0') << endl;
    cout << "Expected: 5, Actual: " << charToInt('5') << endl;
    cout << "Expected: 9, Actual: " << charToInt('9') << endl;
}

// 5. shiftAlphaCharacter
void testShiftAlphaCharacter() {
    cout << "\nTesting shiftAlphaCharacter()" << endl;
    cout << "Expected: a, Actual: " << shiftAlphaCharacter('a', 0) << endl;
    cout << "Expected: C, Actual: " << shiftAlphaCharacter('X', 5) << endl;
    cout << "Expected: V, Actual: " << shiftAlphaCharacter('X', 50) << endl;
    cout << "Expected: y, Actual: " << shiftAlphaCharacter('c', -4) << endl;
    cout << "Expected: A, Actual: " << shiftAlphaCharacter('Z', 1) << endl;
}

// 6. caesarCipher
void testCaesarCipher() {
    cout << "\nTesting caesarCipher()" << endl;
    cout << "Expected: Cuuj cu qj 11 f.c., Actual: " << caesarCipher("Meet me at 11 p.m.", 42, true) << endl;
    cout << "Expected: Meet me at 11 p.m., Actual: " << caesarCipher("Cuuj cu qj 11 f.c.", 42, false) << endl;
    cout << "Expected: Khoor, Actual: " << caesarCipher("Hello", 3, true) << endl;
}

// 7. vigenereCipher
void testVigenereCipher() {
    cout << "\nTesting vigenereCipher()" << endl;
    cout << "Expected: Euyb dv ee 11 f.g., Actual: " << vigenereCipher("Meet me at 11 p.m.", "Squirrel!", true) << endl;
    cout << "Expected: Meet me at 11 p.m., Actual: " << vigenereCipher("Euyb dv ee 11 f.g.", "Squirrel!", false) << endl;
    cout << "Expected: Lxfopv, Actual: " << vigenereCipher("HELLO", "AB", true) << endl;
}

// 8. mixKey
void testMixKey() {
    cout << "\nTesting mixKey()" << endl;
    cout << "Expected: POLYBIUSACDEFGHJKMNQRTVWXZ0123456789, Actual: " << mixKey("POLYBIUS") << endl;
    cout << "Expected: 183ABCDEFGHIJKLMNOPQRSTUVWXYZ0245679, Actual: " << mixKey("183") << endl;
}

// 9. fillGrid (test via mixKey + findInGrid)
void testFillGrid() {
    cout << "\nTesting fillGrid() (via findInGrid)" << endl;
    char grid[SIZE][SIZE];
    string content = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    fillGrid(grid, content);
    cout << "Expected: 00, Actual: " << findInGrid('A', grid) << endl;
    cout << "Expected: 42, Actual: " << findInGrid('0', grid) << endl;
}

// 10. findInGrid
void testFindInGrid() {
    cout << "\nTesting findInGrid()" << endl;
    char grid[SIZE][SIZE];
    string key = "TESTKEY";
    string mixed = mixKey(key);
    fillGrid(grid, mixed);
    cout << "Expected: 00, Actual: " << findInGrid('T', grid) << endl;
    cout << "Expected: 03, Actual: " << findInGrid('K', grid) << endl;
}

// 11. polybiusSquare
void testPolybiusSquare() {
    cout << "\nTesting polybiusSquare()" << endl;
    char grid[SIZE][SIZE];
    string key = "183";
    string plaintext = "EECS 183 IS THE BEST";
    string ciphertext = "11110533 000102 1533 341411 04113334";
    cout << "Encrypt Expected: " << ciphertext << ", Actual: " << polybiusSquare(grid, key, plaintext, true) << endl;
    cout << "Decrypt Expected: " << plaintext << ", Actual: " << polybiusSquare(grid, key, ciphertext, false) << endl;
}
