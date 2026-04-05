/**
 * Copyright 2025 University of Michigan EECS183
 *
 * Ship.cpp
 * Project UID 95f0d1fcee98fd521df7bce6625c2263
 *
 * Zihao.yang
 * yocnggg
 *
 * Project 4: Battleship
 *
 * <#description#>
 */




#include <cmath>

#include "Ship.h"


Ship::Ship() {
    start = Position();
    end = Position();
    size = 0;
    num_hits = 0;
}

Ship::Ship(Position start_in, Position end_in) {
    start = start_in;
    end = end_in;
    num_hits = 0;

    if (is_horizontal()) {
        size = abs(start.get_col() - end.get_col()) + 1;
    } else {
        size = abs(start.get_row() - end.get_row()) + 1;
    }
}

Position Ship::get_start() {
    return start;
}

Position Ship::get_end() {
    return end;
}

int Ship::get_size() {
    return size;
}

bool Ship::is_horizontal() {
    return start.get_row() == end.get_row();
}

bool Ship::has_position(Position pos) {
    if (is_horizontal()) {
        if (pos.get_row() != start.get_row()) {
            return false;
        }
        int minCol = start.get_col() < end.get_col() ?
                     start.get_col() : end.get_col();
        int maxCol = start.get_col() > end.get_col() ?
                     start.get_col() : end.get_col();
        return pos.get_col() >= minCol && pos.get_col() <= maxCol;
    } else {
        if (pos.get_col() != start.get_col()) {
            return false;
        }
        int minRow = start.get_row() < end.get_row() ?
                     start.get_row() : end.get_row();
        int maxRow = start.get_row() > end.get_row() ?
                     start.get_row() : end.get_row();
        return pos.get_row() >= minRow && pos.get_row() <= maxRow;
    }
}

void Ship::hit() {
    if (num_hits < size) {
        num_hits++;
    }
}

bool Ship::has_sunk() {
    return num_hits == size;
}
