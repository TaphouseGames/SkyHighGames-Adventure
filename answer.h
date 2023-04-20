#pragma once

#include "player.h"

class Answer {
public:
    Answer(const int point_penalty, const int point_reward);
    int wrongPointPenalty;
    int correctPointReward;
    void applyQuestionPenalty(Player& player) const;
    void applyQuestionReward(Player& player) const;
};
