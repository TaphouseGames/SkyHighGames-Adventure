#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <cstring>
#include "Act1.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::function;
using std::map;

map<string, function<void(string&)>> inputHandlers;
function<void(string&)> currentLevelHandler;

int main() {
    string playerName;

    cout << inputHandlers.size() << endl;
    intro(playerName);

    inputHandlers["hint"] = [](string& playerName) {
        cout << endl << "Try using one of these words: " << endl << endl;
        for (const auto &command: inputHandlers) {
            cout << command.first << endl;
        }
    };

    while (currentLevelHandler) {
        currentLevelHandler(playerName);

        string userInput;
        getline(cin, userInput);

        for (const auto &command: inputHandlers) {
            if (strstr(userInput.c_str(),command.first.c_str())) {
                userInput = command.first;
                break;
            }
        }

        if (inputHandlers.find(userInput) != inputHandlers.end()) {
            inputHandlers[userInput](playerName);
        } else {
            cout << "Sorry I did not recognized that command, type 'hint' for a list of recognized keywords" << endl << endl;
        }
    }

    return 0;
}