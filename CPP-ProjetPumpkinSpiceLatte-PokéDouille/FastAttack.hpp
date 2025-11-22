#pragma once
#include "Attack.hpp"

class FastAttack : public Attack {
public:
    void execute(PokeDouille* attacker, PokeDouille* defender) override;
    std::string getName() const override;
};
