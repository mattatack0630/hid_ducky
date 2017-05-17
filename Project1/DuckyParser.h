#pragma once
#include "HidCom.h"
#include <cstring>
#include "Key.h"
#include <map>

class DuckyParser {
public:
	// Communication to the hid device
	HidCommunication* hidCom;

	// Key parsing map
	map<string, const Key*> keyMap;
	void initKeyMap();

	// Parsing
	DuckyParser(HidCommunication*);
	void parseProgram(string);
	void parseLine(string);
};