#pragma once
#include "Attack.hpp"

class Fireball : public Attack {
public:
    void execute(PokeDouille* attacker, PokeDouille* defender) override;
    std::string getName() const override;
};
