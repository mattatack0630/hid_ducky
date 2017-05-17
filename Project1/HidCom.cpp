#include "HidCom.h"
#include <stdio.h>
#include <algorithm>
#include <fstream>

using namespace std;

HidCommunication::HidCommunication(const char* _file) {
	hidFile = _file;
}

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

vector<char> HidCommunication::compileKeys()
{
	vector<char> keyCodes;

	for (Key key : keysDown) {
		for (char c : key.buttons) {
			if (find(keyCodes.begin(), keyCodes.end(), c) == keyCodes.end()) {
				keyCodes.push_back(c);
			}
		}
	}

	while (keyCodes.size() < MAX_KEYS + 1) {
		keyCodes.push_back('\x00');
	}

	return keyCodes;
}

char HidCommunication::compileMods() 
{
	char bitmap = 0;
	
	for (Key key : keysDown) {
		for (char c : key.mods) {
			bitmap |= c;
		}
	}

	return bitmap;
}

void HidCommunication::type(Key _key) {
	add(_key);
	sendKeys();
	remove(_key);
	sendKeys();
}

void HidCommunication::press(Key _key) {
	add(_key);
	sendKeys();
}

void HidCommunication::release(Key _key) {
	remove(_key);
	sendKeys();
}

void HidCommunication::add(Key _key) {
	keysDown.push_back(_key);
}

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