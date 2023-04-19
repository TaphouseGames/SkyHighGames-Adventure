#pragma once

#include "player.h"

class Answer {
public:
    Answer(const int point_penalty, const int point_reward);
    int wrong_point_penalty;
    int correct_point_reward;
    void applyQuestionPenalty(Player& player) const;
    void applyQuestionReward(Player& player) const;
};
