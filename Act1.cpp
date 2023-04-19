#include <iostream>
#include <string>
#include <map>
#include <functional>
#include "Act1.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::function;
using std::map;

extern map<string, function<void(string&)>> inputHandlers;
extern function<void(string&)> currentLevelHandler;

void intro(string& playerName) {
    string intro = "Welcome to 'SkyHigh Games: The Job Seeker's Adventure'! In this text-based adventure game, "
                   "you will take on the role of someone who dreams of working at SkyHigh Games, the best and "
                   "most prestigious game development company in the world. With your skills and determination, you "
                   "will embark on a journey through the exciting world of game development, facing challenges and "
                   "making decisions that will determine your success in landing the job of your dreams. Do you have "
                   "what it takes to impress the SkyHigh Games hiring team and become a part of their elite team of "
                   "developers? The adventure awaits!";

    cout << intro << endl;
    cout << "Please enter your name: " << endl;
    getline(cin, playerName);

    cout << "Welcome, " << playerName << " nice to meet you." << endl;

    currentLevelHandler = jobPost;
}

void jobPost(string& playerName) {
    string intro = "As you browse through the WorkWithIndies website, a new job posting catches your eye. It's for an "
                   "Engineer position at SkyHigh Games. The job posting is fresh and you know it won't stay up for long."
                   " This is your chance to prove yourself and land a job in the gaming industry.";

    cout << intro << endl;
    cout << "What do you do?" << endl;

    inputHandlers["apply"] = [](string& playerName) {
        cout << "You click on the apply button and are redirected to an engineer application form. You fill in all "
                "information and submit your resume." << endl;
    };

    inputHandlers["procrastinate"] = [](string& playerName) {
        // code for entering the cabin
    };

    inputHandlers["procrastinate"] = [](string& playerName) {
        // code for entering the cabin
    };
}

void interview(string& playerName) {

}