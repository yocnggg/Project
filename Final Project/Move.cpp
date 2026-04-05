/*
 * Copyright 2023 University of Michigan EECS183
 *
 * Move.cpp
 * Project UID 848fee0125dbb5eb53ed294f20dbef81
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */
 
#include <cmath>
#include <sstream>
#include <stdio.h>      
#include <stdlib.h>
#include "Move.h"

using namespace std;

Move::Move(string commandString) : Move() {
    if (commandString == "") {
        isPass = true;
    } else if (commandString == "S" || commandString == "s") {
        isSave = true;
    } else if (commandString == "Q" || commandString == "q") {
        isQuit = true;
    } else {
        stringstream ss(commandString);
        char e;
        ss >> e;
        ss >> elevatorId;
        char type;
        ss >> type;
        if (type == 'f') {
            ss >> targetFloor;
        } else if (type == 'p') {
            isPickup = true;
        }
    }
}

bool Move::isValidMove(Elevator elevators[NUM_ELEVATORS]) const {
    if (isPass || isQuit || isSave) {
        return true;
    }

    if (elevatorId < 0 || elevatorId >= NUM_ELEVATORS) {
        return false;
    }
    if (elevators[elevatorId].isServicing()) {
        return false;
    }

    if (!isPickup) {
        if (targetFloor < 0 || targetFloor >= NUM_FLOORS) {
            return false;
        }
        if (targetFloor == elevators[elevatorId].getCurrentFloor()) {
            return false;
        }
    }

    return true;
}

void Move::setPeopleToPickup(const string& pickupList, const int currentFloor, 
                             const Floor& pickupFloor) {
    numPeopleToPickup = 0;
    totalSatisfaction = 0;

    for (int i = 0; i < (int)pickupList.length(); i++) {
        int index = pickupList[i] - '0';
        peopleToPickup[numPeopleToPickup] = index;
        numPeopleToPickup++;

        Person p = pickupFloor.getPersonByIndex(index);
        totalSatisfaction += (MAX_ANGER - p.getAngerLevel());
    }

    targetFloor = pickupFloor.getPersonByIndex(peopleToPickup[0]).getTargetFloor();
    for (int i = 1; i < numPeopleToPickup; i++) {
        int pTarget = pickupFloor.getPersonByIndex(peopleToPickup[i]).getTargetFloor();
        if (abs(pTarget - currentFloor) > abs(targetFloor - currentFloor)) {
            targetFloor = pTarget;
        }
    }
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Move::Move() {
    elevatorId = -1;
    targetFloor = -1;
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
	isPass = false;
    isPickup = false;
    isSave = false;
    isQuit = false;
}

bool Move::isPickupMove() const {
    return isPickup;
}

bool Move::isPassMove() const {
	return isPass;
}

bool Move::isSaveMove() const {
	return isSave;
}

bool Move::isQuitMove() const {
	return isQuit;
}

int Move::getElevatorId() const {
    return elevatorId;
}

int Move::getTargetFloor() const {
    return targetFloor;
}

int Move::getNumPeopleToPickup() const {
    return numPeopleToPickup;
}

int Move::getTotalSatisfaction() const {
    return totalSatisfaction;
}

void Move::setTargetFloor(int inTargetFloor) {
    targetFloor = inTargetFloor;
}

void Move::copyListOfPeopleToPickup(int newList[MAX_PEOPLE_PER_FLOOR]) const {
    for (int i = 0; i < numPeopleToPickup; ++i) {
        newList[i] = peopleToPickup[i];
    }
}
