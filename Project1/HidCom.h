#pragma once
#include <stdio.h>
#include "Key.h"
#include <vector>

class HidCommunication {
public:
	int MAX_KEYS = 6; // Max amount of keys that can be pressed
	vector<Key> keysDown; // Keys currently being pressed
	const char* hidFile; // Device file name

	// Constructor
	HidCommunication(const char* file); 

	// Print keys to device file
	void sendKeys();
	
	// Actions
	void type(Key);
	void press(Key);
	void release(Key);

private:
	// Add and remove keys
	void add(Key);
	void remove(Key);
	// Compile keys and mods into a vector/bitmap
	vector<char> compileKeys();
	char compileMods();
};