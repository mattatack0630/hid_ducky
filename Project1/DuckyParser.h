#pragma once
#include "HidCom.h"
#include <cstring>
#include "Key.h"
#include <map>

class DuckyParser {
public:
	HidCommunication* hidCom;

	map<string, const Key*> keyMap;
	void initKeyMap();

	DuckyParser(HidCommunication*);
	void parseProgram(string);
	void parseLine(string);
};
