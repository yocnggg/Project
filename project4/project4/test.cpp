/**
 * Copyright 2025 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Project 4: Battleship
 *
 * Contains functions for testing classes in the project. 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"
#include "utility.h"

using namespace std;

void test_position();
void test_ship();
void test_player();
void test_game();
void test_project_setup();

void startTests() {
    test_project_setup();
    test_position();
    test_ship();
    test_player();
    test_game();

    return;
}

void test_position() {
    cout << "--- Testing Position ---" << endl;

    // default constructor
    Position p1;
    cout << "Default: (" << p1.get_row() << "," << p1.get_col() << ") expected (0,0)" << endl;

    // non-default constructor (int)
    Position p2(3, 5);
    cout << "Int ctor (3,5): (" << p2.get_row() << "," << p2.get_col() << ") expected (3,5)" << endl;

    // check_range via int constructor - out of bounds
    Position p3(-1, 10);
    cout << "Int ctor (-1,10): (" << p3.get_row() << "," << p3.get_col() << ") expected (0,7)" << endl;

    Position p4(0, 0);
    cout << "Int ctor (0,0): (" << p4.get_row() << "," << p4.get_col() << ") expected (0,0)" << endl;

    Position p5(7, 7);
    cout << "Int ctor (7,7): (" << p5.get_row() << "," << p5.get_col() << ") expected (7,7)" << endl;

    // non-default constructor (char)
    Position p6('1', 'A');
    cout << "Char ctor ('1','A'): (" << p6.get_row() << "," << p6.get_col() << ") expected (0,0)" << endl;

    Position p7('3', 'C');
    cout << "Char ctor ('3','C'): (" << p7.get_row() << "," << p7.get_col() << ") expected (2,2)" << endl;

    Position p8('8', 'H');
    cout << "Char ctor ('8','H'): (" << p8.get_row() << "," << p8.get_col() << ") expected (7,7)" << endl;

    // case insensitive
    Position p9('1', 'a');
    cout << "Char ctor ('1','a'): (" << p9.get_row() << "," << p9.get_col() << ") expected (0,0)" << endl;

    Position p10('5', 'e');
    cout << "Char ctor ('5','e'): (" << p10.get_row() << "," << p10.get_col() << ") expected (4,4)" << endl;

    // set_row, set_col
    Position p11;
    p11.set_row(5);
    p11.set_col(3);
    cout << "After set (5,3): (" << p11.get_row() << "," << p11.get_col() << ") expected (5,3)" << endl;

    p11.set_row(-5);
    cout << "After set_row(-5): row=" << p11.get_row() << " expected 0" << endl;

    p11.set_col(100);
    cout << "After set_col(100): col=" << p11.get_col() << " expected 7" << endl;

    // write
    Position p12(0, 0);
    cout << "Write (0,0): " << p12 << " expected (1,A)" << endl;

    Position p13(7, 7);
    cout << "Write (7,7): " << p13 << " expected (8,H)" << endl;

    Position p14(2, 5);
    cout << "Write (2,5): " << p14 << " expected (3,F)" << endl;

    // read format "1A"
    Position p15;
    istringstream iss1("1A");
    iss1 >> p15;
    cout << "Read '1A': (" << p15.get_row() << "," << p15.get_col() << ") expected (0,0)" << endl;

    // read format "(1,A)"
    Position p16;
    istringstream iss2("(3,F)");
    iss2 >> p16;
    cout << "Read '(3,F)': (" << p16.get_row() << "," << p16.get_col() << ") expected (2,5)" << endl;

    // read lowercase
    Position p17;
    istringstream iss3("(1,a)");
    iss3 >> p17;
    cout << "Read '(1,a)': (" << p17.get_row() << "," << p17.get_col() << ") expected (0,0)" << endl;

    Position p18;
    istringstream iss4("5e");
    iss4 >> p18;
    cout << "Read '5e': (" << p18.get_row() << "," << p18.get_col() << ") expected (4,4)" << endl;

    // read edge cases
    Position p19;
    istringstream iss5("8H");
    iss5 >> p19;
    cout << "Read '8H': (" << p19.get_row() << "," << p19.get_col() << ") expected (7,7)" << endl;

    cout << "--- Position Tests Complete ---" << endl << endl;
}

void test_ship() {
    cout << "--- Testing Ship ---" << endl;

    // default constructor
    Ship s1;
    cout << "Default size: " << s1.get_size() << " expected 0" << endl;
    cout << "Default start: " << s1.get_start() << " expected (1,A)" << endl;
    cout << "Default end: " << s1.get_end() << " expected (1,A)" << endl;
    cout << "Default has_sunk: " << s1.has_sunk() << " expected 1" << endl;

    // non-default constructor horizontal
    Position start1(0, 0);
    Position end1(0, 2);
    Ship s2(start1, end1);
    cout << "Horiz ship size: " << s2.get_size() << " expected 3" << endl;
    cout << "is_horizontal: " << s2.is_horizontal() << " expected 1" << endl;

    // non-default constructor vertical
    Position start2(2, 0);
    Position end2(6, 0);
    Ship s3(start2, end2);
    cout << "Vert ship size: " << s3.get_size() << " expected 5" << endl;
    cout << "is_horizontal: " << s3.is_horizontal() << " expected 0" << endl;

    // end before start
    Position start3(7, 4);
    Position end3(3, 4);
    Ship s4(start3, end3);
    cout << "Reversed ship size: " << s4.get_size() << " expected 5" << endl;

    // has_position - horizontal
    Position start4(0, 3);
    Position end4(0, 5);
    Ship s5(start4, end4);
    cout << "has_pos (0,3): " << s5.has_position(Position(0, 3)) << " expected 1" << endl;
    cout << "has_pos (0,4): " << s5.has_position(Position(0, 4)) << " expected 1" << endl;
    cout << "has_pos (0,5): " << s5.has_position(Position(0, 5)) << " expected 1" << endl;
    cout << "has_pos (0,2): " << s5.has_position(Position(0, 2)) << " expected 0" << endl;
    cout << "has_pos (0,6): " << s5.has_position(Position(0, 6)) << " expected 0" << endl;
    cout << "has_pos (1,4): " << s5.has_position(Position(1, 4)) << " expected 0" << endl;

    // has_position - vertical
    Position start5(2, 0);
    Position end5(4, 0);
    Ship s6(start5, end5);
    cout << "has_pos (2,0): " << s6.has_position(Position(2, 0)) << " expected 1" << endl;
    cout << "has_pos (3,0): " << s6.has_position(Position(3, 0)) << " expected 1" << endl;
    cout << "has_pos (4,0): " << s6.has_position(Position(4, 0)) << " expected 1" << endl;
    cout << "has_pos (1,0): " << s6.has_position(Position(1, 0)) << " expected 0" << endl;
    cout << "has_pos (5,0): " << s6.has_position(Position(5, 0)) << " expected 0" << endl;
    cout << "has_pos (3,1): " << s6.has_position(Position(3, 1)) << " expected 0" << endl;

    // has_position - reversed
    Position start6(5, 0);
    Position end6(3, 0);
    Ship s7(start6, end6);
    cout << "Reversed has_pos (4,0): " << s7.has_position(Position(4, 0)) << " expected 1" << endl;
    cout << "Reversed has_pos (3,0): " << s7.has_position(Position(3, 0)) << " expected 1" << endl;
    cout << "Reversed has_pos (5,0): " << s7.has_position(Position(5, 0)) << " expected 1" << endl;

    // hit and has_sunk
    Ship s8(Position(0, 0), Position(0, 1));
    cout << "has_sunk before hits: " << s8.has_sunk() << " expected 0" << endl;
    s8.hit();
    cout << "has_sunk after 1 hit: " << s8.has_sunk() << " expected 0" << endl;
    s8.hit();
    cout << "has_sunk after 2 hits: " << s8.has_sunk() << " expected 1" << endl;
    s8.hit();
    cout << "has_sunk after 3 hits (extra): " << s8.has_sunk() << " expected 1" << endl;

    // ship of size 2
    Ship s9(Position(0, 0), Position(0, 1));
    cout << "Size 2 ship: " << s9.get_size() << " expected 2" << endl;

    // ship of size 4
    Ship s10(Position(0, 0), Position(0, 3));
    cout << "Size 4 ship: " << s10.get_size() << " expected 4" << endl;

    cout << "--- Ship Tests Complete ---" << endl << endl;
}

void test_player() {
    cout << "--- Testing Player ---" << endl;

    // default constructor
    Player p1;
    cout << "Default name: '" << p1.get_name() << "' expected ''" << endl;
    cout << "Default num_ships: " << p1.get_num_ships() << " expected 0" << endl;
    cout << "Default remaining: " << p1.get_remaining_ships() << " expected 0" << endl;
    cout << "Default grid (0,0): " << p1.get_grid_at(0, 0) << " expected -" << endl;
    cout << "Default guess (0,0): " << p1.get_guess_grid_at(0, 0) << " expected -" << endl;

    // non-default constructor
    Player p2("Alice");
    cout << "Name: " << p2.get_name() << " expected Alice" << endl;
    cout << "Num ships: " << p2.get_num_ships() << " expected 0" << endl;
    cout << "Remaining: " << p2.get_remaining_ships() << " expected 0" << endl;

    // add_ship
    Ship ship1(Position(0, 0), Position(0, 2));
    p2.add_ship(ship1);
    cout << "After add_ship, num_ships: " << p2.get_num_ships() << " expected 1" << endl;
    cout << "Remaining: " << p2.get_remaining_ships() << " expected 1" << endl;
    cout << "Grid (0,0): " << p2.get_grid_at(0, 0) << " expected *" << endl;
    cout << "Grid (0,1): " << p2.get_grid_at(0, 1) << " expected *" << endl;
    cout << "Grid (0,2): " << p2.get_grid_at(0, 2) << " expected *" << endl;
    cout << "Grid (0,3): " << p2.get_grid_at(0, 3) << " expected -" << endl;

    // add vertical ship
    Ship ship2(Position(2, 5), Position(4, 5));
    p2.add_ship(ship2);
    cout << "After 2nd ship, num_ships: " << p2.get_num_ships() << " expected 2" << endl;
    cout << "Grid (2,5): " << p2.get_grid_at(2, 5) << " expected *" << endl;
    cout << "Grid (3,5): " << p2.get_grid_at(3, 5) << " expected *" << endl;
    cout << "Grid (4,5): " << p2.get_grid_at(4, 5) << " expected *" << endl;

    // attack - hit
    Player attacker("Bob");
    Player defender("Eve");
    defender.add_ship(Ship(Position(0, 0), Position(0, 1)));

    cout << "Attacking (0,0):" << endl;
    attacker.attack(defender, Position(0, 0));
    cout << "Defender grid (0,0): " << defender.get_grid_at(0, 0) << " expected O" << endl;
    cout << "Attacker guess (0,0): " << attacker.get_guess_grid_at(0, 0) << " expected O" << endl;

    // attack - miss
    cout << "Attacking (1,1):" << endl;
    attacker.attack(defender, Position(1, 1));
    cout << "Defender grid (1,1): " << defender.get_grid_at(1, 1) << " expected X" << endl;
    cout << "Attacker guess (1,1): " << attacker.get_guess_grid_at(1, 1) << " expected X" << endl;

    // attack - sink ship
    cout << "Remaining before sink: " << defender.get_remaining_ships() << " expected 1" << endl;
    cout << "Attacking (0,1) to sink:" << endl;
    attacker.attack(defender, Position(0, 1));
    cout << "Remaining after sink: " << defender.get_remaining_ships() << " expected 0" << endl;
    cout << "Destroyed: " << defender.destroyed() << " expected 1" << endl;

    // load_grid_file
    Player p3("Test");
    bool loaded = p3.load_grid_file("grid1.txt");
    cout << "Loaded grid1.txt: " << loaded << " expected 1" << endl;
    cout << "Num ships: " << p3.get_num_ships() << " expected 5" << endl;
    cout << "Grid (7,1): " << p3.get_grid_at(7, 1) << " expected *" << endl;
    cout << "Grid (7,2): " << p3.get_grid_at(7, 2) << " expected *" << endl;

    // load non-existent file
    Player p4("Test2");
    bool loaded2 = p4.load_grid_file("nonexistent.txt");
    cout << "Load nonexistent: " << loaded2 << " expected 0" << endl;

    // add_ship max limit
    Player p5("Max");
    p5.add_ship(Ship(Position(0, 0), Position(0, 1)));
    p5.add_ship(Ship(Position(1, 0), Position(1, 1)));
    p5.add_ship(Ship(Position(2, 0), Position(2, 1)));
    p5.add_ship(Ship(Position(3, 0), Position(3, 1)));
    p5.add_ship(Ship(Position(4, 0), Position(4, 1)));
    cout << "After 5 ships: " << p5.get_num_ships() << " expected 5" << endl;
    p5.add_ship(Ship(Position(5, 0), Position(5, 1)));
    cout << "After 6th add: " << p5.get_num_ships() << " expected 5" << endl;

    // destroyed
    Player p6("D");
    cout << "No ships destroyed: " << p6.destroyed() << " expected 1" << endl;

    // load grid2.txt with mixed formats
    Player p7("Mixed");
    bool loaded3 = p7.load_grid_file("grid2.txt");
    cout << "Loaded grid2.txt: " << loaded3 << " expected 1" << endl;
    cout << "Num ships: " << p7.get_num_ships() << " expected 5" << endl;

    // announce_ship_sunk
    Player p8("Tester");
    cout << "Announce size 2: ";
    p8.announce_ship_sunk(2);
    cout << "Announce size 3: ";
    p8.announce_ship_sunk(3);
    cout << "Announce size 4: ";
    p8.announce_ship_sunk(4);
    cout << "Announce size 5: ";
    p8.announce_ship_sunk(5);

    cout << "--- Player Tests Complete ---" << endl << endl;
}

void test_game() {
    cout << "--- Testing Game ---" << endl;

    // default constructor
    Game g1;
    cout << "Default p1 name: '" << g1.get_p1().get_name() << "' expected ''" << endl;
    cout << "Default p2 name: '" << g1.get_p2().get_name() << "' expected ''" << endl;

    // non-default constructor with files
    Player player1("Alice");
    Player player2("CPU");
    Game g2(player1, "grid1.txt", player2, "grid2.txt");
    cout << "P1 name: " << g2.get_p1().get_name() << " expected Alice" << endl;
    cout << "P2 name: " << g2.get_p2().get_name() << " expected CPU" << endl;
    cout << "P1 num_ships: " << g2.get_p1().get_num_ships() << " expected 5" << endl;
    cout << "P2 num_ships: " << g2.get_p2().get_num_ships() << " expected 5" << endl;

    // check_valid_move
    Game g3(Player("Bob"), "grid1.txt", Player("CPU"), "grid2.txt");
    cout << "Valid '1A': " << g3.check_valid_move("1A") << " expected 1" << endl;
    cout << "Valid '8H': " << g3.check_valid_move("8H") << " expected 1" << endl;
    cout << "Valid '1a': " << g3.check_valid_move("1a") << " expected 1" << endl;
    cout << "Valid '5e': " << g3.check_valid_move("5e") << " expected 1" << endl;
    cout << "Invalid '12B' (too long): ";
    cout << g3.check_valid_move("12B") << " expected 0" << endl;
    cout << "Invalid '' (empty): ";
    cout << g3.check_valid_move("") << " expected 0" << endl;
    cout << "Invalid '9A' (row OOB): ";
    cout << g3.check_valid_move("9A") << " expected 0" << endl;
    cout << "Invalid '0A' (row OOB): ";
    cout << g3.check_valid_move("0A") << " expected 0" << endl;
    cout << "Invalid '1I' (col OOB): ";
    cout << g3.check_valid_move("1I") << " expected 0" << endl;
    cout << "Invalid '3P' (col OOB): ";
    cout << g3.check_valid_move("3P") << " expected 0" << endl;
    cout << "Invalid 'ABC' (length 3): ";
    cout << g3.check_valid_move("ABC") << " expected 0" << endl;

    // non-default constructor with empty grids (random)
    Player player3("Test");
    Player player4("CPU");
    Game g4(player3, "", player4, "");
    cout << "P1 ships (random): " << g4.get_p1().get_num_ships() << endl;
    cout << "P2 ships (random): " << g4.get_p2().get_num_ships() << endl;

    cout << "--- Game Tests Complete ---" << endl << endl;
}

void test_project_setup() {
    // open file to verify setup
    ifstream ins;
    ins.open("grid1.txt");

    // check for fail state
    if (ins.fail()) {
        cout << "Project was not created correctly." << endl;
        cout << "Text files are not in the correct folder." << endl;
        cout << "Check the project specification "
            << "for how to set up your project." << endl;
    }
    else {
        cout << "Project set up correctly, file opened." << endl;
    }

    return;
}

