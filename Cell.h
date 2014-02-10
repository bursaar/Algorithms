//
//  Cell.h
//  Maze Runner
//
//  Created by Ben Keenan on 06/01/2014.
//  Copyright (c) 2014 Ben Keenan. All rights reserved.
//

#ifndef __Maze_Runner__Cell__
#define __Maze_Runner__Cell__


#include <iostream>
#include "nodes.h"

using namespace std;

class cCell {

public:
    int index;
    int state;
    
	// Assign the instance of the cell an index and a state.
	void setCell(int pCellIndex, int pCellState);

};


//===============================================================================================
// Functions that exist outside of the class but are useful for operations involving the class
// or similar.
//===============================================================================================

// PRINT CO-ORDS
// Pass a four-element array of grid locations and get an on-screen printout of the array.
void PrintCoOrds(gridloc list[4]);

#endif /* defined(__Maze_Runner__Cell__) */
