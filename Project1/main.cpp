#pragma warning(disable:4996)
#include <iostream>
#include "HidCom.h"
#include <stdio.h>

using namespace std;

int main() 
{
	FILE* file = fopen("test.txt","w");

	HidCommunication hidCom(file);

	hidCom.type(KEY_H);
	hidCom.type(KEY_E);
	hidCom.type(KEY_L);
	hidCom.type(KEY_L);
	hidCom.type(KEY_O);

	hidCom.type(KEY_W);
	hidCom.type(KEY_O);
	hidCom.type(KEY_R);
	hidCom.type(KEY_L);
	hidCom.type(KEY_D);

	fclose(file);
}