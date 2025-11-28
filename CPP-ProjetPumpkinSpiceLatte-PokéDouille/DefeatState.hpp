#pragma once
#include "BattleState.hpp"

class DefeatState : public BattleState {
public:
    void handle(BattleContext* context) override;
};