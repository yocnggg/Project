/**
 * Copyright 2025 University of Michigan EECS183
 *
 * Player.cpp
 * Project UID 95f0d1fcee98fd521df7bce6625c2263
 *
 * Zihao.yang
 * yocnggg
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include <fstream>

#include "Player.h"


Player::Player() {
    name = "";
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}

Player::Player(string name_val) {
    name = name_val;
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}

void Player::init_grid() {
    // go through every row
    for (int row = 0; row < MAX_GRID_SIZE; row++) {
        // go through every column
        for (int col = 0; col < MAX_GRID_SIZE; col++) {
            grid[row][col] = EMPTY_LETTER;
            guess_grid[row][col] = EMPTY_LETTER;
        }
    }
    return;
}

string Player::get_name() {
    return name;
}

int Player::get_num_ships() {
    return num_ships;
}

int Player::get_remaining_ships() {
    return remaining_ships;
}

char Player::get_grid_at(int row, int col) {
    return grid[row][col];
}

char Player::get_guess_grid_at(int row, int col) {
    return guess_grid[row][col];
}

void Player::add_ship(Ship ship) {
    // check if we already have max ships
    if (num_ships >= MAX_NUM_SHIPS) {
        return;
    }

    // add the ship to the array
    ships[num_ships] = ship;
    num_ships = num_ships + 1;
    remaining_ships = remaining_ships + 1;

  
    Position startPos = ship.get_start();
    Position endPos = ship.get_end();

    
    if (ship.is_horizontal()) {
        
        int startCol = startPos.get_col();
        int endCol = endPos.get_col();
        int minCol = 0;
        int maxCol = 0;

        if (startCol < endCol) {
            minCol = startCol;
            maxCol = endCol;
        } else {
            minCol = endCol;
            maxCol = startCol;
        }

        
        int row = startPos.get_row();
        for (int col = minCol; col <= maxCol; col++) {
            grid[row][col] = SHIP_LETTER;
        }
    } else {
       
        int startRow = startPos.get_row();
        int endRow = endPos.get_row();
        int minRow = 0;
        int maxRow = 0;

        if (startRow < endRow) {
            minRow = startRow;
            maxRow = endRow;
        } else {
            minRow = endRow;
            maxRow = startRow;
        }

        
        int col = startPos.get_col();
        for (int row = minRow; row <= maxRow; row++) {
            grid[row][col] = SHIP_LETTER;
        }
    }

    return;
}

void Player::attack(Player &opponent, Position pos) {
    int row = pos.get_row();
    int col = pos.get_col();

   
    if (opponent.grid[row][col] == SHIP_LETTER) {
        // it's a hit
        opponent.grid[row][col] = HIT_LETTER;
        guess_grid[row][col] = HIT_LETTER;
        cout << name << " " << pos << " hit" << endl;

        
        for (int i = 0; i < opponent.num_ships; i++) {
            if (opponent.ships[i].has_position(pos)) {
                opponent.ships[i].hit();

               
                if (opponent.ships[i].has_sunk()) {
                    opponent.remaining_ships = opponent.remaining_ships - 1;
                    announce_ship_sunk(opponent.ships[i].get_size());
                }
                break;
            }
        }
    } else {
        // it's a miss
        opponent.grid[row][col] = MISS_LETTER;
        guess_grid[row][col] = MISS_LETTER;
        cout << name << " " << pos << " miss" << endl;
    }

    return;
}

void Player::announce_ship_sunk(int size) {
    if (size == 2) {
        cout << "Congratulations " << name << "! You sunk a Destroyer" << endl;
    } else if (size == 3) {
        cout << "Congratulations " << name << "! You sunk a Submarine" << endl;
    } else if (size == 4) {
        cout << "Congratulations " << name << "! You sunk a Battleship" << endl;
    } else if (size == 5) {
        cout << "Congratulations " << name << "! You sunk a Carrier" << endl;
    }

    return;
}

bool Player::load_grid_file(string filename) {
    ifstream ins;
    ins.open(filename);

    // check if file opened
    if (ins.fail()) {
        return false;
    }

    Position startPos;
    Position endPos;

    // read each ship from the file
    while (ins >> startPos >> endPos) {
        Ship newShip(startPos, endPos);
        add_ship(newShip);
    }

    ins.close();
    return true;
}

bool Player::destroyed() {
    if (remaining_ships == 0) {
        return true;
    }
    return false;
}

// Your code goes above this line.
// Don't change the implementations below!

void Player::print_grid() {
    ::print_grid(grid);
}

void Player::print_guess_grid() {
    ::print_grid(guess_grid);
}

