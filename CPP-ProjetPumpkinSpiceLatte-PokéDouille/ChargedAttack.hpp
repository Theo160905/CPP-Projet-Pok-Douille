#pragma once
#include "Attack.hpp"

class ChargedAttack : public Attack {
private:
    std::string attackName;
    int damage;

public:
    ChargedAttack(std::string name, int dmg, int pp);
    void execute(PokeDouille* attacker, PokeDouille* defender) override;
    std::string getName() const override;
    bool needsCharging() const override { return true; }  // Indique que c'est une attaque chargée
};