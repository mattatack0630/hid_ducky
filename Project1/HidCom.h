#pragma once
#include <stdio.h>
#include "Key.h"
#include <vector>

class HidCommunication {
public:
	int MAX_KEYS = 5;
	vector<Key> keysDown;
	FILE* hidFile;

	HidCommunication(FILE*);

	void sendKeys();
	void type(Key);
	void press(Key);
	void release(Key);

private:
	void add(Key);
	void remove(Key);
	vector<char> compileKeys();
	char compileMods();
};