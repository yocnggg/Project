/**
 * test.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277t
 *
 * Zihao.Yang
 * yocnggg
 *
 * EECS 183: Project 2
 * Winter 2026
 *
 * Testing functions for your rps.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <iostream>
#include <string>

using namespace std;


//************************************************************************
// You will implement the following functions in rps.cpp
//************************************************************************
string getName(int playerNumber);
int getMenuChoice();
bool isMoveGood(char move);
char getMove(string playerName);
bool isRoundWinner(char move, char opponentMove);
void announceRoundWinner(string winnerName);
int doRound(string p1Name, string p2Name);
void announceWinner(string winnerName);
string doGame(string p1Name, string p2Name, int gameType);

//************************************************************************
// The following functions were already implemented for you in rps.cpp
//************************************************************************
void printInitialHeader();
void printMenu();
void printErrorMessage(int errorNumber);
void printCloser();

//************************************************************************
// Testing function declarations. Function definition is below main.
//************************************************************************
void test_isMoveGood();
void test_isRoundWinner();
void test_announceRoundWinner();
void test_announceWinner();


void startTests() {
    cout << "\nExecuting your test cases\n";

        test_isMoveGood();
        test_isRoundWinner();
        test_announceRoundWinner();
        test_announceWinner();

        return;
    }

//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you
// to recieve full points when submitting test.cpp
// NOTE: We will only grade your tests for the following functions
//       * isMoveGood()
//       * isRoundWinner()
//       * announceRoundWinner()
//       * announceWinner()
//************************************************************************

void test_isMoveGood() {
    cout << "Now testing function isMoveGood()\n";
    
    cout << "'r': Expected: 1, Actual: " << isMoveGood('r') << endl;
    cout << "'q': Expected: 0, Actual: " << isMoveGood('q') << endl;
    cout << "'P': Expected: 1, Actual: " << isMoveGood('P') << endl;
    cout << "'1': Expected: 0, Actual: " << isMoveGood('1') << endl;
    return;
}

void test_isRoundWinner() {
    cout << "test_isRoundWinner" << endl;

    cout << "r vs s Expected 1 Actual "
             << isRoundWinner('r', 's') << endl;

    cout << "s vs p Expected 1 Actual "
             << isRoundWinner('s', 'p') << endl;

    cout << "p vs r Expected 1 Actual "
             << isRoundWinner('p', 'r') << endl;

    cout << "r vs r Expected 0 Actual "
             << isRoundWinner('r', 'r') << endl;
    }

void test_announceRoundWinner() {
    cout << "test_announceRoundWinner" << endl;

    cout << "Expected: Alice wins the round!" << endl;
        announceRoundWinner("Alice");

    cout << "Expected: This round is a draw!" << endl;
        announceRoundWinner("");
    }

void test_announceWinner() {
    cout << "test_announceWinner" << endl;

    cout << "Expected: Congratulations Alice!" << endl;
    cout << "Expected: You won EECS 183 Rock-Paper-Scissors!" << endl;
        announceWinner("Alice");

    cout << "Expected: No winner!" << endl;
        announceWinner("");
    }
