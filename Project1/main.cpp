#pragma warning(disable:4996)

#include "DuckyParser.h"
#include "HidCom.h"

#include <stdio.h>
#include <fstream>	
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	//char* deviceFileName = argv[1];
	//char* codeFileName = argv[2];


	//FILE* file = fopen("test.txt", "wb");

	HidCommunication hidCom("test.txt");
	DuckyParser parser(&hidCom);
	parser.initKeyMap();


	string str;
	ifstream readFile("Read.txt");

	while (getline(readFile, str)){
		parser.parseProgram(str);
	}

	//cin.get();

	//fclose(file);
}