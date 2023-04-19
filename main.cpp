#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <cstring>
#include "game.h"
#include "player.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::function;
using std::map;

const int HINT_POINT_PENALTY = 2;
const int UNRECOGNIZED_POINT_PENALTY = 1;

map<string, function<void()>> inputHandlers;
function<void(Player&)> currentLevelHandler;

Player player;


void updateInputHandlers();
void getUserInput();


int main() {
    intro(player);

    while (currentLevelHandler) {
        updateInputHandlers();
        currentLevelHandler(player);
        getUserInput();
    }

    return 0;
}

void updateInputHandlers() {
    inputHandlers.clear();

    inputHandlers["hint"] = []() {
        player.points -= HINT_POINT_PENALTY;
        cout << "Losing " << HINT_POINT_PENALTY << " points for using a hint." << endl;
        cout << endl << "Try using one of these words: " << endl << endl;
        for (const auto &command: inputHandlers) {
            cout << command.first << endl;
        }
    };

    inputHandlers["exit"] = []() {
        exit(0);
    };
}

void getUserInput() {
    string userInput;
    getline(cin, userInput);

    for (const auto &command: inputHandlers) {
        if (strstr(userInput.c_str(),command.first.c_str())) {
            userInput = command.first;
            break;
        }
    }

    if (inputHandlers.find(userInput) != inputHandlers.end()) {
        inputHandlers[userInput]();
    } else {
        player.points -= UNRECOGNIZED_POINT_PENALTY;
        cout << "Losing " << UNRECOGNIZED_POINT_PENALTY << " points for an unrecognized input." << endl;
        cout << "Sorry I did not recognized that input, type 'hint' for a list of recognized keywords" << endl << endl;
    }
}