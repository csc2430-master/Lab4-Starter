// Title: Lab 4 - main.cpp
//
// Purpose: Program for testing the Battleship "grid" ADT.
//
// Class: CSC 2430 Winter 2020
// Authors: Max Benson and <please fill this in>
//
#include <iostream>
#include <assert.h>
#include "grid.h"
#include "helperCode.h"

//Forward declarations
void ManuallyPlaceShips(Grid& grid, Ship ships[], int countShips);
bool TestSaveLoad(Grid& grid);

//
// Main program:
//
// This program exercises the grid functions implmemented in this lab.  It starts by offering the user the choice
// whether to randomly place ships on the grid, or manually place them.  If manual placement is selected, then it
// will ask for the location that user wants for each of the five ships.
//
// After ships have been placed on the grid, it will save the ship configuration to a file of the user's choosing
// and then reload the placement from file into a new grid.  The two grids are then compared to make sure they
// are the same.
int main() {
    string command;
    Ship   shipsToPlace[] =  { { "Submarine", 3 },
                               { "Battleship", 4 },
                               { "Destroyer",  3 },
                               { "PatrolBoat", 2 },
                               { "Carrier",    5 } };
    Grid grid;

    // Determine how ships should be placed
    do {
        cout << "Enter M to manually place ships, R to randomly place ships: ";
        cin >> command;
    } while (command != "M" && command != "R");

    // Place the ships on the grid
    if (command == "M") {
        ManuallyPlaceShips(grid, shipsToPlace, sizeof(shipsToPlace)/sizeof(shipsToPlace[0]));
    }
    else if (command == "R") {
        int randomSeed;

        // Prompt for random seed to use
        cout << "Enter seed for random number generator: ";
        cin >> randomSeed;
        srand(randomSeed);

        // Do the random placement
        RandomlyPlaceShips(grid, shipsToPlace, sizeof(shipsToPlace)/sizeof(shipsToPlace[0]));

    }

    // Print the ships to verify correctness
    PrintGrid(grid);

    // Test save and reload configuration
    if (TestSaveLoad(grid)) {
        cout << "Load worked properly" << endl;
    }

    return 0;
}

// This function prompts the user for the desired location for each of the five ships
//      So long as a ship placement does not extend outside the grid or overlap previous
//      ships that have been added the ship will be placed as the user specifies.  Otherwise
//      the user will be asked again until a acceptable placement is enter.
//  Parameters:
//      grid - a grid
//      ships - the array of ships to be placed
//      countShips - number of ships in the array
//  Returns:
//      nothing
//  Possible Errors:
//      none
void ManuallyPlaceShips(Grid& grid, Ship ships[], int countShips) {
    Init(grid);
    for (int i = 0; i < countShips; i ++ ) {
        bool firstTime;
        int isVertical;
        int startRow;
        int startColumn;

        PrintGrid(grid);

        firstTime = true;
        do {
            string hOrV;

            // If we are retrying print message
            if (!firstTime) {
                cout << "Ship could not be added, please try again." << endl;
            }
            else {
                firstTime = false;
            }

            // Ask user where to place the ship
            do {
                cout << "Place your " << ships[i].name << " horizontally or vertically?  Enter H or V: ";
                cin >> hOrV;
            } while( hOrV != "H" && hOrV != "V");
            isVertical = (hOrV == "V");

            if (isVertical) {
                cout << "Enter row and column of upper end of ship as numbers: ";
            }
            else {
                cout << "Enter row and column of left end of ship as numbers: ";
            }
            cin >> startRow >> startColumn;
        } while( !AddShip( grid, ships[i].name, ships[i].size, isVertical, startRow, startColumn)) ;
    }
}

// This function tests the grid save and load functionality.  It will prompt the
//      the user for a file name to same the grid to.  It will save the grid
//      then reload the ship configuration into a new grid.  It then verifies
//      that the original grid and the new one are identical.
//  Parameters:
//      grid - a grid
//  Returns:
//      true if no errors on save or load and grids identical or false otherwise
//  Possible Errors:
//      error opening either file
//      file write error
//      file read error
//      saved and loaded configurations don't match
bool TestSaveLoad(Grid& grid) {
    // *** You need to implement this function
    assert(false);
}
