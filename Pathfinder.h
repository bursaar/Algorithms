#pragma once
#include "Cell.h"
#include "nodes.h"
#include "Maze.h"

class cPathfinder
{
public:

	/*
	===	Member Variables ===
	*/

	cCell cell_currentNodeMap[25][25];

	/*
	===	Member Functions ===
	*/

	//==========================================================================================================
	// CREATE NODE MAP
	// Create the nodemap given an argument of an exsiting generated maze.
	// The current workflow would be:
	// Create maze object -> Populate maze from serialised gencode -> Create pathfinding layer
	void create(cMaze m_MazeToMap)

	{
		// We set the initial variables:
		int xindex = 0;             // This is the X co-ordinate in the 2D array of cells.
		int yindex = 0;			    // This is given a starting value of zero that will be augmented within the yindex while loop.
		int cellindex = 0;		    // Each node has its own index, this is provided in case it's useful for pathfinding later.


		// Now we create two nested while loops to create pairs of lines (yindex)
		// from 0 & 1 up to 24 & 25. We won't be printing or using line 25 (the 26th line).

		while (yindex < 25)
		{
			while (xindex < 25)
			{
				switch (m_MazeToMap.mCurrentMaze[xindex][yindex].state)
				{
				case 0:
					cell_currentNodeMap[xindex][yindex].state = 0;
					cell_currentNodeMap[xindex][yindex].index = cellindex;
					cellindex++;
					break;

				case 1:
					cell_currentNodeMap[xindex][yindex].state = 1;
					cell_currentNodeMap[xindex][yindex].index = cellindex;
					cellindex++;
					break;

				case 3:
					cell_currentNodeMap[xindex][yindex].state = 0;
					cell_currentNodeMap[xindex][yindex].index = cellindex;
					cellindex++;
					break;

				case 4:
					cell_currentNodeMap[xindex][yindex].state = 1;
					cell_currentNodeMap[xindex][yindex].index = cellindex;
					cellindex++;
					break;
				}

				xindex++;

			}

			xindex = 0;
			yindex++;

			
		}

		return;

	};

	//========================================================================================================== 
	// LOOK AROUND																								
	// This function will return a gridloc array with a maximum of four elements. These (max) four locations	
	// are the only legal moves left to the entity in the given cell.											
	//==========================================================================================================
	void LookAround(gridloc gl_whereAmI, gridloc(&gl_clearToMove)[4]) {

		/*
		The idea here is to give the function a variable and an array.

		It will calculate where around the gl_whereAmI is free to move
		and will pass the answers by reference to a user-supplied
		2 x 2 array (N, E, S, W) which will essentially contain the next
		legal moves available to the player.

		N	[0]
		E	[1]
		S	[2]
		W	[3]

		If the element contains the origin (0, 0) then it is considered blank.

		*/

		if (cell_currentNodeMap[gl_whereAmI.xloc][gl_whereAmI.yloc - 1].state == 0)		//North check (0, -1) to go into [0]
		{
			gl_clearToMove[0].xloc = gl_whereAmI.xloc;
			gl_clearToMove[0].yloc = gl_whereAmI.yloc - 1;
		}
		else {
			gl_clearToMove[0].xloc = 0;
			gl_clearToMove[0].yloc = 0;
		}

		if (cell_currentNodeMap[gl_whereAmI.xloc + 1][gl_whereAmI.yloc].state == 0)		//East check (1, 0) to go into [1]
		{
			gl_clearToMove[1].xloc = gl_whereAmI.xloc + 1;
			gl_clearToMove[1].yloc = gl_whereAmI.yloc;
		} else {
			gl_clearToMove[1].xloc = 0;
			gl_clearToMove[1].yloc = 0;
		}

		if (cell_currentNodeMap[gl_whereAmI.xloc][gl_whereAmI.yloc + 1].state == 0)		//South check (0, +1) to go into [2]
		{
			gl_clearToMove[2].xloc = gl_whereAmI.xloc;
			gl_clearToMove[2].yloc = gl_whereAmI.yloc + 1;
		} else {
			gl_clearToMove[2].xloc = 0;
			gl_clearToMove[2].yloc = 0;
		}

		if (cell_currentNodeMap[gl_whereAmI.xloc - 1][gl_whereAmI.yloc].state == 0)		//West check (-1, 0) to go into [3]
		{
			gl_clearToMove[3].xloc = gl_whereAmI.xloc - 1;
			gl_clearToMove[3].yloc = gl_whereAmI.yloc;
		} else {
			gl_clearToMove[3].xloc = 0;
			gl_clearToMove[3].yloc = 0;
		}

		{

		}


	}

	//==========================================================================================================
	// PRINT MAZE
	// Print the maze to the screen. Pass an argument of 1 to print a label on the nodemap.
	//==========================================================================================================
	void print(bool b_printLabel = 0) {
		int xpos = 0;   // Create a variable to track the x axis
		int ypos = 0;   // Create a variable to track the y axis

		// If the argument 1 is passed, it prints a label, otherwise it remains unwritten.
		if (b_printLabel = 1) {
			cout << "Node Map." << endl;
		}

		// Next is a while loop that prints one horizontal line at a time, moving
		// down the grid vertically as each lines completes, left to right.

		while (ypos < 25) {

			// First it runs another while loop that prints from left to right.

			while (xpos < 25) {

				// It takes the current X & Y co-ordinates and prints the state, followed by a space,

				cout << cell_currentNodeMap[xpos][ypos].state << " ";

				// Then it increments the X co-ordinate by one and loops again, moving to the next one on the right.

				xpos++;
			}

			// Once the X loop has gone all the way to the right, it attempts to go one more, then jumps out to this point.

			// Here we print a carriage return
			cout << endl;

			// Then we reset the X co-ordinate to 0 to start us off again on the left.
			xpos = 0;

			// Then we increment the Y co-ordinate by one and loop again, being caught by the X loop again.
			ypos++;
		}

		return;
	}
};