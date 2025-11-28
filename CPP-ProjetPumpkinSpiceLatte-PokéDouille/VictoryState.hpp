// ========== VictoryState.hpp ==========
#pragma once
#include "BattleState.hpp"

class VictoryState : public BattleState {
public:
    void handle(BattleContext* context) override;
};