#pragma warning(disable:4996)

#include "DuckyParser.h"
#include "HidCom.h"

#include <fstream>	
#include <string>

using namespace std;

int main(int argc, char *argv[]) 
{
	if (argc >= 3) {
		// Get parameters
		char* deviceFileName =  argv[1];
		char* codeFileName = argv[2];

		// Init device com and parser
		HidCommunication hidCom(deviceFileName);
		DuckyParser parser(&hidCom);
	
		// Init key parsing map
		parser.initKeyMap();

		// Init read from file
		string str;
		ifstream readFile(codeFileName);

		// Parse each line
		while (getline(readFile, str)) {
			parser.parseProgram(str);
		}
	}

}