#include "BasicAttack.hpp"
#include "PokeDouille.hpp"
#include <iostream>

BasicAttack::BasicAttack(std::string name, int dmg, int pp)
    : Attack(pp), attackName(name), damage(dmg) {
}

void BasicAttack::execute(PokeDouille* attacker, PokeDouille* defender) {
    if (!canUse()) {
        std::cout << "Plus de PP pour cette attaque !\n";
        return;
    }

    std::cout << attacker->getName() << " utilise " << attackName << " !\n";
    defender->takeDamage(damage);
    std::cout << defender->getName() << " perd " << damage << " PV !\n";
    usePP();
    std::cout << "PP restants : " << getCurrentPP() << "/" << getMaxPP() << "\n";
}

std::string BasicAttack::getName() const {
    return attackName;
}