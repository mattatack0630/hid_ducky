#pragma once
#include <vector>

using namespace std;

class Key {
public:
	vector<char> buttons;
	vector<char> mods;
	
	Key(int, const char*);
	Key(int, int, const char*, const char*);

	bool operator==(Key);
};

const char MOD_CTRL_L =		1;
const char MOD_SHIFT_L =	2; 
const char MOD_ALT_L =		4;
const char MOD_GUI_L =		8;
const char MOD_CTRL_R =		16;
const char MOD_SHIFT_R =		32;
const char MOD_ALT_R =		64;
const char MOD_GUI_R =		128;

const Key KEY_A_L(1, new char[1] {'\x04'});
const Key KEY_B_L(1, new char[1]{ '\x05' });
const Key KEY_C_L(1, new char[1]{ '\x06' });
const Key KEY_D_L(1, new char[1]{ '\x07' });
const Key KEY_E_L(1, new char[1]{ '\x08' });
const Key KEY_F_L(1, new char[1]{ '\x09' });
const Key KEY_G_L(1, new char[1]{ '\x0A' });
const Key KEY_H_L(1, new char[1]{ '\x0B' });
const Key KEY_I_L(1, new char[1]{ '\x0C' });
const Key KEY_J_L(1, new char[1]{ '\x0D' });
const Key KEY_K_L(1, new char[1]{ '\x0E' });
const Key KEY_L_L(1, new char[1]{ '\x0F' });
const Key KEY_M_L(1, new char[1]{ '\x10' });
const Key KEY_N_L(1, new char[1]{ '\x11' });
const Key KEY_O_L(1, new char[1]{ '\x12' });
const Key KEY_P_L(1, new char[1]{ '\x13' });
const Key KEY_Q_L(1, new char[1]{ '\x14' });
const Key KEY_R_L(1, new char[1]{ '\x15' });
const Key KEY_S_L(1, new char[1]{ '\x16' });
const Key KEY_T_L(1, new char[1]{ '\x17' });
const Key KEY_U_L(1, new char[1]{ '\x18' });
const Key KEY_V_L(1, new char[1]{ '\x19' });
const Key KEY_W_L(1, new char[1]{ '\x1A' });
const Key KEY_X_L(1, new char[1]{ '\x1B' });
const Key KEY_Y_L(1, new char[1]{ '\x1C' });
const Key KEY_Z_L(1, new char[1]{ '\x1D' });

const Key KEY_A_U(1, 1, new char[1]{ '\x04' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_B_U(1, 1, new char[1]{ '\x05' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_C_U(1, 1, new char[1]{ '\x06' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_D_U(1, 1, new char[1]{ '\x07' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_E_U(1, 1, new char[1]{ '\x08' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_F_U(1, 1, new char[1]{ '\x09' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_G_U(1, 1, new char[1]{ '\x0A' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_H_U(1, 1, new char[1]{ '\x0B' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_I_U(1, 1, new char[1]{ '\x0C' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_J_U(1, 1, new char[1]{ '\x0D' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_K_U(1, 1, new char[1]{ '\x0E' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_L_U(1, 1, new char[1]{ '\x0F' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_M_U(1, 1, new char[1]{ '\x10' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_N_U(1, 1, new char[1]{ '\x11' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_O_U(1, 1, new char[1]{ '\x12' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_P_U(1, 1, new char[1]{ '\x13' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_Q_U(1, 1, new char[1]{ '\x14' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_R_U(1, 1, new char[1]{ '\x15' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_S_U(1, 1, new char[1]{ '\x16' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_T_U(1, 1, new char[1]{ '\x17' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_U_U(1, 1, new char[1]{ '\x18' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_V_U(1, 1, new char[1]{ '\x19' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_W_U(1, 1, new char[1]{ '\x1A' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_X_U(1, 1, new char[1]{ '\x1B' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_Y_U(1, 1, new char[1]{ '\x1C' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_Z_U(1, 1, new char[1]{ '\x1D' }, new char[1]{ MOD_SHIFT_L });

const Key KEY_1(1, new char[1]{ '\x1E' });
const Key KEY_2(1, new char[1]{ '\x1F' });
const Key KEY_3(1, new char[1]{ '\x20' });
const Key KEY_4(1, new char[1]{ '\x21' });
const Key KEY_5(1, new char[1]{ '\x22' });
const Key KEY_6(1, new char[1]{ '\x23' });
const Key KEY_7(1, new char[1]{ '\x24' });
const Key KEY_8(1, new char[1]{ '\x25' });
const Key KEY_9(1, new char[1]{ '\x26' });
const Key KEY_0(1, new char[1]{ '\x27' });

const Key KEY_EXLAMATION	(1, 1, new char[1]{ '\x1E' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_AT			(1, 1, new char[1]{ '\x1F' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_POUND			(1, 1, new char[1]{ '\x20' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_CURRENCY		(1, 1, new char[1]{ '\x21' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_PERCENT		(1, 1, new char[1]{ '\x22' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_UP_CARROT		(1, 1, new char[1]{ '\x23' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_ASTERICK		(1, 1, new char[1]{ '\x24' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_AMPERSAND		(1, 1, new char[1]{ '\x25' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_LEFT_PERENTH	(1, 1, new char[1]{ '\x26' }, new char[1]{ MOD_SHIFT_L });
const Key KEY_RIGHT_PERENTH	(1, 1, new char[1]{ '\x27' }, new char[1]{ MOD_SHIFT_L });

const Key KEY_DASH				(1, new char[1]{ '\x2D' });
const Key KEY_EQUAL				(1, new char[1]{ '\x2E' });
const Key KEY_SQR_LEFT_BRACKET	(1, new char[1]{ '\x2F' });
const Key KEY_SQR_RIGHT_BRACKET	(1, new char[1]{ '\x30' });
const Key KEY_BACK_SLASH		(1, new char[1]{ '\x31' });
const Key KEY_SEMICOLON			(1, new char[1]{ '\x33' });
const Key KEY_APOSTROPHY		(1, new char[1]{ '\x34' });
const Key KEY_UP_APSTROPHY		(1, new char[1]{ '\x35' });
const Key KEY_COMMA				(1, new char[1]{ '\x36' });
const Key KEY_PERIOD			(1, new char[1]{ '\x37' });
const Key KEY_FORWARD_SLASH		(1, new char[1]{ '\x38' });

const Key KEY_UNDERSCORE	(1, 1, new char[1]{ '\x2D'  }, new char[1]{ MOD_SHIFT_L });
const Key KEY_ADDITION		(1, 1, new char[1]{ '\x2E'  }, new char[1]{ MOD_SHIFT_L });
const Key KEY_LEFT_BRACKET	(1, 1, new char[1]{ '\x2F'  }, new char[1]{ MOD_SHIFT_L });
const Key KEY_RIGHT_BRACKET	(1, 1, new char[1]{ '\x30'  }, new char[1]{ MOD_SHIFT_L });
const Key KEY_PIPE			(1, 1, new char[1]{ '\x31'  }, new char[1]{ MOD_SHIFT_L });
const Key KEY_COLON			(1, 1, new char[1]{ '\x33'  }, new char[1]{ MOD_SHIFT_L });
const Key KEY_QOUTES		(1, 1, new char[1]{ '\x34'  }, new char[1]{ MOD_SHIFT_L });
const Key KEY_TILDA			(1, 1, new char[1]{ '\x35'  }, new char[1]{ MOD_SHIFT_L });
const Key KEY_LEFT_CARROT	(1, 1, new char[1]{ '\x36'  }, new char[1]{ MOD_SHIFT_L });
const Key KEY_RIGHT_CARROT	(1, 1, new char[1]{ '\x37'  }, new char[1]{ MOD_SHIFT_L });
const Key KEY_QUESTION_MARK	(1, 1, new char[1]{ '\x38'  }, new char[1]{ MOD_SHIFT_L });

const Key KEY_F1	(1, new char[1]{ '\x3A' });
const Key KEY_F2	(1, new char[1]{ '\x3B' });
const Key KEY_F3	(1, new char[1]{ '\x3C' });
const Key KEY_F4	(1, new char[1]{ '\x3D' });
const Key KEY_F5	(1, new char[1]{ '\x3E' });
const Key KEY_F6	(1, new char[1]{ '\x3F' });
const Key KEY_F7	(1, new char[1]{ '\x40' });
const Key KEY_F8	(1, new char[1]{ '\x41' });
const Key KEY_F9	(1, new char[1]{ '\x42' });
const Key KEY_F10	(1, new char[1]{ '\x43' });
const Key KEY_F11	(1, new char[1]{ '\x44' });
const Key KEY_F12	(1, new char[1]{ '\x45' });
const Key KEY_F13	(1, new char[1]{ '\x68' });
const Key KEY_F14	(1, new char[1]{ '\x69' });
const Key KEY_F15	(1, new char[1]{ '\x6A' });
const Key KEY_F16	(1, new char[1]{ '\x6B' });
const Key KEY_F17	(1, new char[1]{ '\x6C' });
const Key KEY_F18	(1, new char[1]{ '\x6D' });
const Key KEY_F19	(1, new char[1]{ '\x6E' });
const Key KEY_F20	(1, new char[1]{ '\x6F' });
const Key KEY_F21	(1, new char[1]{ '\x70' });
const Key KEY_F22	(1, new char[1]{ '\x71' });
const Key KEY_F23	(1, new char[1]{ '\x72' });
const Key KEY_F24	(1, new char[1]{ '\x73' });

const Key KEY_HOME		(1, new char[1]{ '\x4A' });
const Key KEY_PG_UP		(1, new char[1]{ '\x4B' });
const Key KEY_PG_DOWN	(1, new char[1]{ '\x4E' });
const Key KEY_DEL		(1, new char[1]{ '\x4C' });
const Key KEY_END		(1, new char[1]{ '\x4D' });
const Key KEY_RIGHT_CP	(1, new char[1]{ '\x4F' });
const Key KEY_LEFT_CP	(1, new char[1]{ '\x50' });
const Key KEY_DOWN_CP	(1, new char[1]{ '\x51' });
const Key KEY_UP_CP		(1, new char[1]{ '\x52' });
const Key KEY_NUM_LOCK	(1, new char[1]{ '\x53' });
const Key KEY_ENTER_A	(1, new char[1]{ '\x58' });

const Key KEY_ENTER		(1, new char[1]{ '\x28' });
const Key KEY_BACK_SPACE(1, new char[1]{ '\x2A' });
const Key KEY_SPACE		(1, new char[1]{ '\x2C' });
const Key KEY_TAB		(1, new char[1]{ '\x2B' });
const Key KEY_ESCAPE	(1, new char[1]{ '\x29' });
const Key KEY_CAPS_LOCK (1, new char[1]{ '\x39' });

const Key KEY_SHIFT_R	(0, 1, new char[0]{}, new char[1]{ MOD_SHIFT_R });
const Key KEY_SHIFT_L	(0, 1, new char[0]{}, new char[1]{ MOD_SHIFT_L });
const Key KEY_ALT_R		(0, 1, new char[0]{}, new char[1]{ MOD_ALT_R });
const Key KEY_ALT_L		(0, 1, new char[0]{}, new char[1]{ MOD_ALT_L });
const Key KEY_CTRL_R	(0, 1, new char[0]{}, new char[1]{ MOD_CTRL_R });
const Key KEY_CTRL_L	(0, 1, new char[0]{}, new char[1]{ MOD_CTRL_L });
const Key KEY_GUI_R		(0, 1, new char[0]{}, new char[1]{ MOD_GUI_R });
const Key KEY_GUI_L		(0, 1, new char[0]{}, new char[1]{ MOD_GUI_L });

//const Key KEY_SHIFT_R	(1, new char[1]{ '\xE5' });
//const Key KEY_SHIFT_L	(1, new char[1]{ '\xE1' });
//const Key KEY_ALT_R		(1, new char[1]{ '\xE6' });
//const Key KEY_ALT_L		(1, new char[1]{ '\xE2' });
//const Key KEY_CTRL_R	(1, new char[1]{ '\xE4' });
//const Key KEY_CTRL_L	(1, new char[1]{ '\xE0' });
//const Key KEY_WIN_R		(1, new char[1]{ '\xE7' });
//const Key KEY_WIN_L		(1, new char[1]{ '\xE3' });