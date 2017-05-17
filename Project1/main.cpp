#pragma warning(disable:4996)

#include "DuckyParser.h"
#include "HidCom.h"

#include <stdio.h>
#include <fstream>	
#include <string>

using namespace std;

int main(int argc, char *argv[]) 
{
	char* deviceFileName = argv[1];
	char* codeFileName = argv[2];

	FILE* file = fopen(deviceFileName, "wb");

	HidCommunication hidCom(file);
	DuckyParser parser(&hidCom);
	parser.initKeyMap();


	string str;
	ifstream readFile(codeFileName);

	while (getline(readFile, str)){
		parser.parseProgram(str);
	}

	fclose(file);
}