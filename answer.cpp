#include <iostream>
#include "answer.h"

using std::cout;
using std::endl;


Answer::Answer(const int point_penalty, const int point_reward) {
    wrong_point_penalty = point_penalty;
    correct_point_reward = point_reward;
}

void Answer::applyQuestionPenalty(Player &player) const {
    cout << endl << "Losing " << wrong_point_penalty << " points for wrong answer" << endl;
    player.points -= wrong_point_penalty;
}

void Answer::applyQuestionReward(Player &player) const {
    cout << endl << "Gaining " << correct_point_reward << " points for correct answer" << endl;
    player.points += correct_point_reward;
}

