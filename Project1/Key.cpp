#include "Key.h"
#include <cstdarg>

// No Modifer constructor
Key::Key(int buttonAmt, const char* _buttons)
{
	// push back each button into member vector
	for (int i = 0; i < buttonAmt; i++) {
		buttons.push_back(_buttons[i]);
	}
}

// Modifer constuctor
Key::Key(int buttonAmt, int modsAmt, const char* _buttons, const char* _mods)
{
	// push back each button into member vector
	for (int i = 0; i < buttonAmt; i++) {
		buttons.push_back(_buttons[i]);
	}

	// puch back each modifer into memeber vector
	for (int i = 0; i < modsAmt; i++) {
		mods.push_back(_mods[i]);
	}
}

// Check equality
bool Key::operator==(Key other)
{
	// intial they are equal
	bool b = true; 
	
	// check if button vectors are the same size
	if (buttons.size() == other.buttons.size()) {
		// compare each button (have to be in same order)
		for (int i = 0; i < buttons.size(); i++) {
			char c = buttons.at(i);
			char oc = other.buttons.at(i);

			// not equal
			if (c != oc) {
				b = false;
			}
		}
	}

	// return equals bool
	return b;
}
