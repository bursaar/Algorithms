#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Serialiser
{
public:
	Serialiser();

	enum en_ReadOrWrite {READ, WRITE};	// 0 = READ, 1 = Write to file
	bool bl_ReadOrWrite;				// 0 = Read from file, 1 = Write to file - Temporary

	string mFilename = "";
	string mExtension = "";

	ifstream Read(string pFilename, string pExtension);
	ifstream Read();

	~Serialiser();
};

