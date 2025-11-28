#pragma once
#include "BattleState.hpp"

class PlayerTurnState : public BattleState {
public:
    void handle(BattleContext* context) override;
};