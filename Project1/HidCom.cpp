#include "HidCom.h"
#include <stdio.h>
#include <algorithm>
#include <fstream>

using namespace std;

HidCommunication::HidCommunication(const char* _file) {
	hidFile = _file;
}

// Print keys and mods to device file
void HidCommunication::sendKeys() {

	vector<char> keyCodes = compileKeys();
	char modBits = compileMods();

	ofstream stream;
	stream.open(hidFile);

	stream << modBits;
	stream << '\x00';

	for (char c : keyCodes) {
		stream << c;
	}

	stream.close();
}

// Push all of the key buttons into a vector
vector<char> HidCommunication::compileKeys()
{
	vector<char> keyCodes;

	// Push back key buttons into a singular vector
	for (Key key : keysDown) {
		for (char c : key.buttons) {
			// check if already in vector
			if (find(keyCodes.begin(), keyCodes.end(), c) == keyCodes.end()) {
				keyCodes.push_back(c);
			}
		}
	}

	// Push back remaining null characters
	while (keyCodes.size() < MAX_KEYS) {
		keyCodes.push_back('\x00');
	}

	return keyCodes;
}

// Push all of the key mods into a bitmap
char HidCommunication::compileMods() 
{
	char bitmap = 0;
	
	// Bit-wise OR into bitmap
	for (Key key : keysDown) {
		for (char c : key.mods) {
			bitmap |= c;
		}
	}

	return bitmap;
}

// Type a key
void HidCommunication::type(Key _key) {
	add(_key); // add the key
	sendKeys(); // print the change
	remove(_key); // remove the key 
	sendKeys(); // print the change
}

// Press a key
void HidCommunication::press(Key _key) {
	add(_key); // add the key
	sendKeys(); // print the change
}

// Release a key 
void HidCommunication::release(Key _key) {
	remove(_key); // remove the key
	sendKeys(); // print the change
}

// Add a key to the keyDown list
void HidCommunication::add(Key _key) {
	keysDown.push_back(_key); 
}

// Remove a key from the keyDown list
void HidCommunication::remove(Key _key) {
	int i = 0;
	for (Key key : keysDown) {
		if (key == _key) {
			break;
		}
		i++;
	}

	if (i < keysDown.size()) {
		keysDown.erase(keysDown.begin() + i);
	}
}