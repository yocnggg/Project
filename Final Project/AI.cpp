/*
 * Copyright 2023 University of Michigan EECS183
 *
 * AI.cpp
 * Project UID 848fee0125dbb5eb53ed294f20dbef81
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */

#include "AI.h"
#include <cassert>

// This file is used only in the Reach, not the Core.

string getAIMoveString(const BuildingState& buildingState) {
    // check if any idle elevator is on a floor with people
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (!buildingState.elevators[i].isServicing) {
            int curFloor = buildingState.elevators[i].currentFloor;
            if (buildingState.floors[curFloor].numPeople > 0) {
                return "e" + to_string(i) + "p";
            }
        }
    }

    // find floor with the angriest person
    int bestFloor = -1;
    int bestAnger = -1;

    for (int f = 0; f < NUM_FLOORS; f++) {
        for (int p = 0; p < buildingState.floors[f].numPeople; p++) {
            if (buildingState.floors[f].people[p].angerLevel > bestAnger) {
                bestAnger = buildingState.floors[f].people[p].angerLevel;
                bestFloor = f;
            }
        }
    }

    if (bestFloor == -1) {
        return "";
    }

    // find closest idle elevator
    int bestElev = -1;
    int bestDist = NUM_FLOORS + 1;

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (!buildingState.elevators[i].isServicing) {
            int dist = buildingState.elevators[i].currentFloor - bestFloor;
            if (dist < 0) {
                dist = -dist;
            }
            if (dist > 0 && dist < bestDist) {
                bestDist = dist;
                bestElev = i;
            }
        }
    }

    if (bestElev != -1) {
        return "e" + to_string(bestElev) + "f" + to_string(bestFloor);
    }

    return "";
}

string getAIPickupList(const Move& move, const BuildingState& buildingState, 
                       const Floor& floorToPickup) {
    int numPeople = floorToPickup.getNumPeople();
    if (numPeople == 0) {
        return "";
    }

    int elevFloor = buildingState.elevators[move.getElevatorId()].currentFloor;

    string upList = "";
    string downList = "";
    int maxUpAnger = -1;
    int maxDownAnger = -1;

    for (int i = 0; i < numPeople; i++) {
        int target = floorToPickup.getPersonByIndex(i).getTargetFloor();
        int anger = floorToPickup.getPersonByIndex(i).getAngerLevel();
        if (target > elevFloor) {
            upList += to_string(i);
            if (anger > maxUpAnger) {
                maxUpAnger = anger;
            }
        } else {
            downList += to_string(i);
            if (anger > maxDownAnger) {
                maxDownAnger = anger;
            }
        }
    }

    if (maxUpAnger >= maxDownAnger && !upList.empty()) {
        return upList;
    } else if (!downList.empty()) {
        return downList;
    }
    return upList;
}
