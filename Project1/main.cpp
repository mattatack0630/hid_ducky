#pragma warning(disable:4996)
#include <iostream>
#include "HidCom.h"
#include <stdio.h>
#include "DuckyParser.h"
#include <cstring>

using namespace std;

int main() 
{
	FILE* file = fopen("test.txt","wb");

	HidCommunication hidCom(file);
	DuckyParser parser(&hidCom);
	parser.initKeyMap();

	parser.parseProgram(string("PRESS A; PRESS B; RELEASE A"));

	fclose(file);
}