/**
 * main.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277c
 *
 * EECS 183: Project 2
 * Winter 2026
 *
 * main() function for Project 2 RPS
 * selects between executing your test cases
 * and the game Rock Paper Scissors
 */

#include <iostream>
#include <string>

using namespace std;

//************************************************************************
// Function declarations. Function definitions are in rps.cpp and test.cpp
//************************************************************************
void rps();
void startTests();

int main() {
    
    cout << "-------------------------------" << endl
         << "EECS 183 Project 2 Menu Options" << endl
         << "-------------------------------" << endl;
    cout << "1) Execute testing functions in test.cpp" << endl;
    cout << "2) Execute rps() function to play game" << endl;    
    cout << "Choice --> ";

    int choice;
    cin >> choice;

    // remove the return character from the cin stream buffer
    string junk;
    getline(cin, junk);

    if (choice == 1) {
        startTests();
    }
    else if (choice == 2) {
        rps();
    }
    
    return 0;
}
