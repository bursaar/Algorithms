#ifndef __Maze_Runner__character__
#define __Maze_Runner__character__

#include <iostream>
#include "Cell.h"
#include "Maze.h"
#include "nodes.h"
#include "Pathfinder.h"

using namespace std;

class Character {
	/*
	===	Member Variables ==
	*/
	char ch_characterSymbol;		// The symbol to appear on the screen when the player or NPC is visible.
	bool bl_visible;				// Can this instance be seen? 0 no, 1 yes.
	bool bl_controllable;			// Can this character be controlled? 0 no, 1 yes.
	char ch_name[25];				// Name of the character.



	/*
	===	Member Functions ==
	*/



};


#endif