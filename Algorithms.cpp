// Algorithms.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include "Maze.h"
#include "Pathfinder.h"
#include "Interface.h"
#include <tchar.h>
#include <fstream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// Front matter
	// ============

	cout << "MAZE RUNNER";
	SkipLine(3);
	cout << "Created by Ben Keenan";
	SkipLine();
	cout << "ben@ben.ie | +353 87 935 0483";
	SkipLine();
	cout << "Student No. CD9000002O";
	SkipLine();
	cout << "Portfolio 1, Project 2";
	SkipLine(2);
	cout << "This is a simple test of my";
	SkipLine();
	cout << "data serialisation algorithm";
	SkipLine(2);
	cout << "Please maximize your window and choose an option.";
	SkipLine(2);
	cout << "0. Quit" << endl << "1. Test game." << endl << "2. Demo code." << endl << "3. Write data." << endl << "4. Read data." << endl << "Choice: ";



	// Simple menu system
	//===================

	int choice;		// Menu choice from the start of the program.
	cin >> choice;



	while (choice != 0)	// Loop checking that the choice isn't set to 0, which means exit.
	{
		// Default generator code for maze object - used in opetions 1 (play) and 2 (demo), and by default in 3 (write).
		bool LevelOneCode[338] = { 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		//====================//
		// CHOICE: READ DATA //
		//==================//
		if (choice == 4)
		{
			// UI to demo data serialisation.
			cout << "Type level name to load. Names are case-sensitive. Type 0 or Quit to end the program." << endl << "Level name: ";
			string filename;	// Default value.
			cin >> filename;
			string str_extension = ".lvl";		// File extension - invisible to user in-program.
			if (filename == "0"					// Add ability to quit.
				|| filename == "quit" 
				|| filename == "Quit" 
				|| filename == "stop"
				|| filename == "Stop"
				|| filename == "QUIT"
				|| filename == "STOP") choice = 0;
			filename.append(str_extension);		// Append file extension to level name input from user.
			std::ifstream arrayData(filename);	

			int arrayIndex = 0;					// Set basic array index to make it possible to count through the lines & array elements. Start value should be 0.
			bool LevelReadCode[338];			// Boolean array variable used to store the read code.
			string line;						// String object to write into when looping through the file.

			if (arrayData.is_open())					// Check to see that file is open
			{
				while (getline(arrayData, line))		// Cycle through each line, reading into the "line" string variable.
				{
					if (line == "0")					// If the line is a 0
					{
						LevelReadCode[arrayIndex] = 0;	// Change the current element in the boolean array into a zero
						arrayIndex++;					// Increment the index
					}
					if (line == "1")					// If the line is a 1
					{
						LevelReadCode[arrayIndex] = 1;	// Change the current element in the boolean array into a one
						arrayIndex++;					// Increment the index
					}
				}
				arrayData.close();						// Cleanup - close out file.

				cMaze TestMaze(LevelReadCode);	// Create maze instance from loaded data.
				cPathfinder SolveTestMaze;		// Create pathfinder instance.
				SolveTestMaze.create(TestMaze);	// Create nodemap in pathfinder.
				SolveTestMaze.print();			// Print nodemap to screen.

				SkipLine(3);

				std::cout << "0. Quit" << endl << "1. Test game." << endl << "2. Demo code." << endl << "3. Write data." << endl << "4. Read data." << endl << "Choice: ";
				cin >> choice;

			}
		}
		//=====================//
		// CHOICE: WRITE DATA //
		//===================//
		if (choice == 3)
		{
			cout << "Type level name to load. Names are case-sensitive." << endl << "Level name: ";
			string filename = "TestLevel.txt";
			cin >> filename;
			string str_extension = ".lvl";
			filename.append(str_extension);

			std::fstream arrayData(filename, std::ios::app);

			int arrayIndex = 0;

			if (arrayData.is_open())
			{
				while (arrayIndex < 338)
				{
					arrayData << LevelOneCode[arrayIndex] << endl;		// Put the current value of the element at the current position in the array into the file and break to a new line.
					arrayIndex++;										// Increment the value of the index.
				}

				arrayData.close();										// Cleanup - close out file.
			}

			cout << "0. Quit" << endl << "1. Test game." << endl << "2. Demo code." << endl << "3. Write data." << endl << "4. Read data." << endl << "Choice: ";
			cin >> choice;

		}

		//====================//
		// CHOICE: DEMO CODE //
		//==================//
		if (choice == 2) {

			// Create Maze
			// =========================

			// Maze object.
			cMaze LevelOne(LevelOneCode);

			// Name for Maze Object
			char LevelOneName[25] = "Test_Game_Example_01";

			SkipLine();

			getchar();

			// Print proper values of maze.
			// =========================
			LevelOne.print();
			SkipLine();

			getchar();

			// Perform pathfinding pass.
			// =========================

			cPathfinder pthLevelOne;		// Pathfinder instance with nodemap. One per level. Kept separate from maze for portability.

			pthLevelOne.create(LevelOne);	// Populate nodemap of the entire maze.

			gridloc gl_tempLegalMoves[4];	// Array to hold the current legal moves.
			gridloc gl_tempLookHere;		// Create location to check for legal moves *from*

			gl_tempLookHere.xloc = 1;		// Assign values to x & y - in this case the node at (1, 1)
			gl_tempLookHere.yloc = 1;

			// Examine next legal moves.
			pthLevelOne.LookAround(gl_tempLookHere, gl_tempLegalMoves);

			cout << "This is the node map (should be identical).";

			SkipLine(2);
			pthLevelOne.print();

			SkipLine();

			getchar();

			cout << "These are the moves available at ";

			gl_tempLookHere.printLoc(gl_tempLookHere); // TODO find a more elegant implementation where it doesn't need to be passed itself.

			cout << ":";

			SkipLine();

			PrintCoOrds(gl_tempLegalMoves);

			SkipLine(2);

			cout << "0. Quit" << endl << "1. Test game." << endl << "2. Demo code." << endl << "3. Write data." << endl << "4. Read data." << endl << "Choice: ";
			cin >> choice;

		}

		//====================//
		// CHOICE: PLAY GAME //
		//==================//
		if (choice == 1)
		{

			// Generator code for maze object.
			bool LevelOneCode[338] = { 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

			// Maze object.
			cMaze LevelOne(LevelOneCode);

			// Name for Maze Object
			char LevelOneName[25] = "Let_Us_Play";

			std::cout << "0. Quit" << endl << "1. Test game." << endl << "2. Demo code." << endl << "3. Write data." << endl << "4. Read data." << endl << "Choice: ";
			cin >> choice;
		}
	}

	std::cout << "Press enter to quit.";

	SkipLine();

	getchar();
	return 0;
}

