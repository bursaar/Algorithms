#include "Serialiser.h"


Serialiser::Serialiser()
{
}

ifstream Serialiser::Read(string pFilename, string pExtension)
{
	pFilename.append(pExtension);

	std::ifstream ifs_readData(pFilename);
	
	return ifs_readData;
}

ifstream Serialiser::Read()
{
	string nFilename = mFilename;
	string nExtension = mExtension;

	if (nFilename.length > 0)
	{
		string nFilename.append(nExtension);

		std::ifstream ifs_readData(nFilename);
	}

	return ifs_readData;

}

Serialiser::~Serialiser()
{
}
