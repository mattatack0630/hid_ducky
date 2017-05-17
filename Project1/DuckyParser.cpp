#include "DuckyParser.h"
#include <vector>
#include <regex>
#include <thread>
#include <chrono>

#define COMMAND_DELM ';'
#define COMMAND_SEP_DELM ' '
#define PRESS	string("PRESS")
#define RELEASE string("RELEASE")
#define TYPE	string("TYPE")
#define STRING	string("STRING")
#define DELAY	string("DELAY")

using namespace std;

// **** This method definatly needs some fixing! ****
vector<string> split(const string& str, const char r, bool ignoreQoute){
	string current = "";
	vector<string> list;
	
	for (size_t i = 0; i<str.length(); i++) {

		char c = str[i];
		char cb = i > 0 ? str[i - 1] : 0;

		if (c == r) {
			list.push_back(current);
			current = string("");
		}
		else if (c == '\"' && cb != '\\' && ignoreQoute) {
			i++;
			char c1 = str[i];
			char cb1 = i > 0 ? str[i - 1] : 0;

			// keep going until -> c1 is a qoute and cb1 is not a escape
			while (!(c1 == '\"' && cb1 != '\\')){

				if (c1 == '\\') {
					current += str[i + 1];
					i+=2;
				} else {
					current += str[i];
					i++;
				}

				c1 = str[i];
				cb1 = i > 0 ? str[i - 1] : 0;
			}
		}
		else {
			current += c;
		}
	}

	if (current != "")
		list.push_back(current);

	return list;
}

// Trim whitespace from front and back of string
string trim(const string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}


DuckyParser::DuckyParser(HidCommunication* _com) 
{
	hidCom = _com;
}

// Parse a program, or multiple lines
void DuckyParser::parseProgram(string lines)
{
	// Split the string by command line delimiter (;)
	vector<string> lines_split = split(lines, COMMAND_DELM, false);

	// Parse each line
	for (string line : lines_split) {
		parseLine(trim(line));
	}
}

// Parse one command at a time (COMMAND : KEY)
void DuckyParser::parseLine(string line) 
{
	// split the command into two parts, command and value
	vector<string> data = split(line, COMMAND_SEP_DELM, true);
	
	// check to make sure command has approprate amount of data
	if (data.size() >= 2) {
		string command = data.at(0); // command at index 0
		string value = data.at(1); // value at index 1
		
		// check to see which command is being called

		if (command == PRESS) {
			hidCom->press(*keyMap[value]);
		}
		if (command == RELEASE) {
			hidCom->release(*keyMap[value]);
		}
		if (command == TYPE) {
			hidCom->type(*keyMap[value]);
		}
		if (command == STRING) {
			for (int i = 0; i < value.size(); i++) {
				string c = "";
				c += value[i];
				Key key = *keyMap[c];
				hidCom->type(key);
			}
		}
		if (command == DELAY) {
			// stall the program on delay command
			auto start = chrono::system_clock::now();
			while (true) {
				auto end = chrono::system_clock::now();
				chrono::duration<double> diff = end - start;
				if (diff.count() > stod(value)) break;
			}
		}
	}
}

// init the key map, used to parse string into a Key obj
void DuckyParser::initKeyMap()
{
	keyMap["a"] = &KEY_A_L;
	keyMap["b"] = &KEY_B_L;
	keyMap["c"] = &KEY_C_L;
	keyMap["d"] = &KEY_D_L;
	keyMap["e"] = &KEY_E_L;
	keyMap["f"] = &KEY_F_L;
	keyMap["g"] = &KEY_G_L;
	keyMap["h"] = &KEY_H_L;
	keyMap["i"] = &KEY_I_L;
	keyMap["j"] = &KEY_J_L;
	keyMap["k"] = &KEY_K_L;
	keyMap["l"] = &KEY_L_L;
	keyMap["m"] = &KEY_M_L;
	keyMap["n"] = &KEY_N_L;
	keyMap["o"] = &KEY_O_L;
	keyMap["p"] = &KEY_P_L;
	keyMap["q"] = &KEY_Q_L;
	keyMap["r"] = &KEY_R_L;
	keyMap["s"] = &KEY_S_L;
	keyMap["t"] = &KEY_T_L;
	keyMap["u"] = &KEY_U_L;
	keyMap["v"] = &KEY_V_L;
	keyMap["w"] = &KEY_W_L;
	keyMap["x"] = &KEY_X_L;
	keyMap["y"] = &KEY_Y_L;
	keyMap["z"] = &KEY_Z_L;

	keyMap["A"] = &KEY_A_U;
	keyMap["B"] = &KEY_B_U;
	keyMap["C"] = &KEY_C_U;
	keyMap["D"] = &KEY_D_U;
	keyMap["E"] = &KEY_E_U;
	keyMap["F"] = &KEY_F_U;
	keyMap["G"] = &KEY_G_U;
	keyMap["H"] = &KEY_H_U;
	keyMap["I"] = &KEY_I_U;
	keyMap["J"] = &KEY_J_U;
	keyMap["K"] = &KEY_K_U;
	keyMap["L"] = &KEY_L_U;
	keyMap["M"] = &KEY_M_U;
	keyMap["N"] = &KEY_N_U;
	keyMap["O"] = &KEY_O_U;
	keyMap["P"] = &KEY_P_U;
	keyMap["Q"] = &KEY_Q_U;
	keyMap["R"] = &KEY_R_U;
	keyMap["S"] = &KEY_S_U;
	keyMap["T"] = &KEY_T_U;
	keyMap["U"] = &KEY_U_U;
	keyMap["V"] = &KEY_V_U;
	keyMap["W"] = &KEY_W_U;
	keyMap["X"] = &KEY_X_U;
	keyMap["Y"] = &KEY_Y_U;
	keyMap["Z"] = &KEY_Z_U;

	keyMap["1"] = &KEY_1;
	keyMap["2"] = &KEY_2;
	keyMap["3"] = &KEY_3;
	keyMap["4"] = &KEY_4;
	keyMap["5"] = &KEY_5;
	keyMap["6"] = &KEY_6;
	keyMap["7"] = &KEY_7;
	keyMap["8"] = &KEY_8;
	keyMap["9"] = &KEY_9;
	keyMap["0"] = &KEY_0;

	keyMap["!"] = &KEY_EXLAMATION;
	keyMap["@"] = &KEY_AT;
	keyMap["#"] = &KEY_POUND;
	keyMap["$"] = &KEY_CURRENCY;
	keyMap["%"] = &KEY_PERCENT;
	keyMap["^"] = &KEY_UP_CARROT;
	keyMap["*"] = &KEY_ASTERICK;
	keyMap["&"] = &KEY_AMPERSAND;
	keyMap["("] = &KEY_LEFT_PERENTH;
	keyMap[")"] = &KEY_RIGHT_PERENTH;

	keyMap["-"] = &KEY_DASH;
	keyMap["="] = &KEY_EQUAL;
	keyMap["["] = &KEY_SQR_LEFT_BRACKET;
	keyMap["]"] = &KEY_SQR_RIGHT_BRACKET;
	keyMap["\\"] = &KEY_BACK_SLASH;
	keyMap[";"] = &KEY_SEMICOLON;
	keyMap["'"] = &KEY_APOSTROPHY;
	keyMap["`"] = &KEY_UP_APSTROPHY;
	keyMap[","] = &KEY_COMMA;
	keyMap["."] = &KEY_PERIOD;
	keyMap["/"] = &KEY_FORWARD_SLASH;

	keyMap["_"] = &KEY_UNDERSCORE;
	keyMap["+"] = &KEY_ADDITION;
	keyMap["["] = &KEY_LEFT_BRACKET;
	keyMap["]"] = &KEY_RIGHT_BRACKET;
	keyMap["|"] = &KEY_PIPE;
	keyMap[":"] = &KEY_COLON;
	keyMap["\""] = &KEY_QOUTES;
	keyMap["~"] = &KEY_TILDA;
	keyMap["<"] = &KEY_LEFT_CARROT;
	keyMap[">"] = &KEY_RIGHT_CARROT;
	keyMap["?"] = &KEY_QUESTION_MARK;

	keyMap["F1"] = &KEY_F1;
	keyMap["F2"] = &KEY_F2;
	keyMap["F3"] = &KEY_F3;
	keyMap["F4"] = &KEY_F4;
	keyMap["F5"] = &KEY_F5;
	keyMap["F6"] = &KEY_F6;
	keyMap["F7"] = &KEY_F7;
	keyMap["F8"] = &KEY_F8;
	keyMap["F9"] = &KEY_F9;
	keyMap["F10"] = &KEY_F10;
	keyMap["F11"] = &KEY_F11;
	keyMap["F12"] = &KEY_F12;
	keyMap["F13"] = &KEY_F13;
	keyMap["F14"] = &KEY_F14;
	keyMap["F15"] = &KEY_F15;
	keyMap["F16"] = &KEY_F16;
	keyMap["F17"] = &KEY_F17;
	keyMap["F18"] = &KEY_F18;
	keyMap["F19"] = &KEY_F19;
	keyMap["F20"] = &KEY_F20;
	keyMap["F21"] = &KEY_F21;
	keyMap["F22"] = &KEY_F22;
	keyMap["F23"] = &KEY_F23;
	keyMap["F24"] = &KEY_F24;

	keyMap["HOME"] =	&KEY_HOME;
	keyMap["PG_UP"] =	&KEY_PG_UP;
	keyMap["PG_DOWN"] = &KEY_PG_DOWN;
	keyMap["DEL"] =		&KEY_DEL;
	keyMap["END"] =		&KEY_END;
	keyMap["RIGHT_CP"] =&KEY_RIGHT_CP;
	keyMap["LEFT_CP"] = &KEY_LEFT_CP;
	keyMap["DOWN_CP"] = &KEY_DOWN_CP;
	keyMap["DOWN_CP"] = &KEY_UP_CP;
	keyMap["NUM_LOCK"] =&KEY_NUM_LOCK;
	keyMap["ENTER_A"] = &KEY_ENTER_A;

	keyMap["ENTER"] =		&KEY_ENTER;
	keyMap["BACK_SPACE"] =	&KEY_BACK_SPACE;
	keyMap[" "] =			&KEY_SPACE;
	keyMap["	"] =		&KEY_TAB;
	keyMap["ESCAPE"] =		&KEY_ESCAPE;
	keyMap["CAPS_LOCK"] =	&KEY_CAPS_LOCK;

	keyMap["SHIFT"] =	&KEY_SHIFT_R;
	keyMap["ALT"] =		&KEY_ALT_R;
	keyMap["CTRL"] =	&KEY_CTRL_R;
	keyMap["GUI"] =		&KEY_GUI_R;

	keyMap["SHIFT_R"] =	&KEY_SHIFT_R;
	keyMap["SHIFT_L"] = &KEY_SHIFT_L;
	keyMap["ALT_R"] =	&KEY_ALT_R;
	keyMap["ALT_L"] =	&KEY_ALT_L;
	keyMap["CTRL_R"] =	&KEY_CTRL_R;
	keyMap["CTRL_L"] =	&KEY_CTRL_L;
	keyMap["GUI_R"] =	&KEY_GUI_R;
	keyMap["GUI_L"] =	&KEY_GUI_L;
}