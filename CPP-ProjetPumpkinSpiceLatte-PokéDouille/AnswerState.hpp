#pragma once
#include "BattleState.hpp"

class AnswerState : public BattleState {
private:
    bool wasPlayerTurn_;
public:
    AnswerState(bool wasPlayerTurn);
    void handle(BattleContext* context) override;
};