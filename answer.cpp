#include <iostream>
#include "answer.h"

using std::cout;
using std::endl;


Answer::Answer(const int pointPenalty, const int pointReward) {
    wrongPointPenalty = pointPenalty;
    correctPointReward = pointReward;
}

void Answer::applyQuestionPenalty(Player &player) const {
    cout << endl << "Losing " << wrongPointPenalty << " points for wrong answer" << endl;
    player.points -= wrongPointPenalty;
}

void Answer::applyQuestionReward(Player &player) const {
    cout << endl << "Gaining " << correctPointReward << " points for correct answer" << endl;
    player.points += correctPointReward;
}

