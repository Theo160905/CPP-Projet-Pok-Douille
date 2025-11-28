#include "ChargedAttack.hpp"
#include "PokeDouille.hpp"
#include <iostream>

ChargedAttack::ChargedAttack(std::string name, int dmg, int pp)
    : Attack(pp), attackName(name), damage(dmg) {
}

void ChargedAttack::execute(PokeDouille* attacker, PokeDouille* defender) {
    if (!canUse()) {
        std::cout << "Plus de PP pour cette attaque !\n";
        return;
    }

    // Premier tour : charge l'attaque
    if (!attacker->isCharging()) {
        std::cout << attacker->getName() << " commence a charger " << attackName << " !\n";
        attacker->setChargingAttack(this);
        usePP();
        std::cout << "PP restants : " << getCurrentPP() << "/" << getMaxPP() << "\n";
        return;
    }

    // Deuxième tour : attaque !
    std::cout << attacker->getName() << " libere " << attackName << " !\n";
    defender->takeDamage(damage);
    std::cout << defender->getName() << " perd " << damage << " PV !\n";
    attacker->releaseCharge();  // Réinitialiser
}

std::string ChargedAttack::getName() const {
    return attackName;
}