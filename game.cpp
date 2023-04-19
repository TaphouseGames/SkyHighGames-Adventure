#include <iostream>
#include <string>
#include <map>
#include <functional>
#include "game.h"
#include "answer.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::function;
using std::map;
using std::vector;

extern map<string, function<void()>> inputHandlers;
extern function<void(Player&)> currentLevelHandler;


void handlerCreator(vector<string> allowedInputs, function<void()> applyFunc) {
    for (const auto& type: allowedInputs) {
        inputHandlers[type] = applyFunc;
    }
}

void intro(Player& player) {
    string intro = "Welcome to 'SkyHigh Games: The Job Seeker's Adventure'! In this text-based adventure game, "
                   "you will take on the role of someone who dreams of working at SkyHigh Games, the best and game "
                   "development company in the world. With your skills and determination, you will embark on a journey "
                   "through the exciting world of game development, facing challenges and making decisions that will "
                   "determine your success in landing the job of your dreams. Do you have what it takes to impress the "
                   "SkyHigh Games hiring team and become a part of their elite team of developers? The adventure awaits!";

    cout << intro << endl;
    cout << endl << "Please enter your name: " << endl;
    getline(cin, player.name);

    cout << endl << "Welcome, " << player.name << " nice to meet you." << endl;

    currentLevelHandler = jobPost;
}

void jobPost(Player& player) {
    Answer answer = Answer(2, 4);
    string intro = "As you browse through the WorkWithIndies website, a new job posting catches your eye. It's for an "
                   "Engineer position at SkyHigh Games. This is your chance to prove yourself and land a job in the "
                   "gaming industry.";

    cout << endl << intro << endl;
    cout << endl << "What do you do?" << endl;

    vector<string> goodAnswers = {"apply", "application", "resume", "submit"};

    function success = [&player, answer]() {
        answer.applyQuestionReward(player);
        cout << endl << "You click on the apply button and are redirected to an engineer application form. You fill in all "
                        "information and submit your resume." << endl;
        cout << endl << "As the days pass by, you eagerly check your email in anticipation of a response from SkyHigh Games. "
                        "Then, at last, you receive an invitation to do an interview. Without delay, you promptly respond to "
                        "schedule one. Congratulations " << player.name << "." << endl;
        currentLevelHandler = preInterview;
    };

    vector<string> badAnswers = {"procrastinate", "video games", "read", "nothing"};

    function fail = [&player, answer]() {
        answer.applyQuestionPenalty(player);
        currentLevelHandler = gameOver;
    };

    handlerCreator(goodAnswers, success);
    handlerCreator(badAnswers, fail);
}

void preInterview(Player &player) {
    Answer answer = Answer(2, 4);
    string intro = "You have one week until the interview. ";

    cout << endl << intro << endl;
    cout << endl << "What do you do to prepare?" << endl;

    vector<string> goodAnswers = {"study", "prepare", "code"};

    function success = [&player, answer]() {
        answer.applyQuestionReward(player);
        currentLevelHandler = interviewRound1;
    };

    vector<string> badAnswers = {"nothing", "twiddle thumbs", "video games"};

    function fail = [&player, answer]() {
        answer.applyQuestionPenalty(player);
        currentLevelHandler = gameOver;
    };

    handlerCreator(goodAnswers, success);
    handlerCreator(badAnswers, fail);
}

void interviewRound1(Player& player) {
    Answer answer = Answer(3, 5);
    string intro = "It is finally time for the interview. You are looking and feeling your best. Time to answer some "
                   "questions. Interview question 1: Does C++ support multithreading?";

    cout << endl << intro << endl;
    cout << "What do you say?" << endl;

    vector<string> goodAnswers = {"yes", "yea", "for sure", "you betcha"};

    function success = [&player, answer]() {
        answer.applyQuestionReward(player);
        currentLevelHandler = interviewRound2;
    };

    vector<string> badAnswers = {"no", "not", "nope"};

    function fail = [&player, answer]() {
        answer.applyQuestionPenalty(player);
        currentLevelHandler = gameOver;
    };

    handlerCreator(goodAnswers, success);
    handlerCreator(badAnswers, fail);
}

void interviewRound2(Player& player) {
    Answer answer = Answer(4, 6);
    string intro = "Interview question 2: Name a data type in C++.";

    cout << endl << intro << endl;
    cout << "What do you say?" << endl;

    vector<string> goodAnswers = {"char", "short", "float", "long", "double", "bool", "enum", "struct", "int"};

    function success = [&player, answer]() {
        answer.applyQuestionReward(player);
        currentLevelHandler = getHired;
    };

    vector<string> badAnswers = {"auto", "nullptr", "sizeof", "const", "typedef", "using", "decltype"};

    function fail = [&player, answer]() {
        answer.applyQuestionPenalty(player);
        currentLevelHandler = gameOver;
    };

    handlerCreator(goodAnswers, success);
    handlerCreator(badAnswers, fail);
}

void gameOver(Player& player) {
    cout << endl << "Sorry " << player.name << " you didn't apply yourself and as a result you did not get the job." << endl;
    cout << "Type 'continue'" << endl;

    inputHandlers["continue"] = []() {
        currentLevelHandler = endOrRestart;
    };

}

void getHired(Player& player) {
    string intro = "After demonstrating your coding skills, you finally receive the news you've been hoping for: you "
                   "landed the job at SkyHigh Games! On your first day, you're greeted by the sound of enthusiastic "
                   "greetings from your new colleagues. You can hardly believe that you're finally a part of this "
                   "incredible team. Over the next few months, you immerse yourself in your work, taking on challenging"
                   " projects, collaborating with talented colleagues, and pushing the boundaries of what's possible in "
                   "game development. Your hard work and dedication pay off in spades, and you become a respected and "
                   "valued member of the team, and your passion for gaming inspires others to push themselves to new "
                   "heights. As you look back on your journey, you realize that the challenges you faced along the way "
                   "only made you stronger and more determined. You feel a deep sense of pride and accomplishment, "
                   "knowing that you've achieved your dreams and become a part of something truly special. With a smile "
                   "on your face and a sense of excitement for the future, you know that your adventure is just "
                   "beginning. You can't wait to see where your career at SkyHigh Games will take you next.";

    cout << endl << "Congratulations " << player.name << " you got the job!" << endl;
    cout << endl << intro << endl;
    cout << endl << "Type 'continue'" << endl;

    inputHandlers["continue"] = []() {
        currentLevelHandler = endOrRestart;
    };
}

void endOrRestart(Player& player) {
    cout << endl << "You ended up with " << player.points << " points." << endl;
    cout << "Type 'exit' to end program or 'restart' to try again." << endl;

    inputHandlers["restart"] = [&player]() {
        currentLevelHandler = intro;
        player.points = 0;
        intro(player);
    };
}