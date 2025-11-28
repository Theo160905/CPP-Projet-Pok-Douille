#pragma once
#include "Attack.hpp"

class BasicAttack : public Attack {
private:
    std::string attackName;
    int damage;

public:
    BasicAttack(std::string name, int dmg, int pp);
    void execute(PokeDouille* attacker, PokeDouille* defender) override;
    std::string getName() const override;
};