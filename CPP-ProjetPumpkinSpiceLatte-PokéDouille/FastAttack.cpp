#include "FastAttack.hpp"
#include "PokeDouille.hpp"
#include <iostream>

void FastAttack::execute(PokeDouille* attacker, PokeDouille* defender) {
    int damage = 10;
    defender->takeDamage(damage);
    std::cout << attacker->getName() << " utilise " << getName()
        << " et inflige " << damage << " dégâts à "
        << defender->getName() << "!\n";
}

std::string FastAttack::getName() const {
    return "Attaque Rapide";
}
