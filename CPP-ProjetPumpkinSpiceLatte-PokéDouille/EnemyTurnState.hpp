#pragma once
#include "BattleState.hpp"

class EnemyTurnState : public BattleState {
public:
    void handle(BattleContext* context) override;
};