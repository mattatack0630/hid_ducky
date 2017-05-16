#include "Key.h"
#include <cstdarg>

Key::Key(int buttonAmt, const char* _buttons)
{
	for (int i = 0; i < buttonAmt; i++) {
		buttons.push_back(_buttons[i]);
	}
}

bool Key::operator==(Key other)
{
	bool b = true;
	
	for (int i = 0; i < buttons.size(); i++) {
		char c = buttons.at(i);
		char oc = other.buttons.at(i);

		if (c != oc) {
			b = false;
		}
	}


	return b;
}
