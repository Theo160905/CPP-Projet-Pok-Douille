#include "Fireball.hpp"
#include "PokeDouille.hpp"
#include <iostream>

void Fireball::execute(PokeDouille* attacker, PokeDouille* defender) {
    int damage = 15;
    defender->takeDamage(damage);
    std::cout << attacker->getName() << " utilise " << getName()
        << " et inflige " << damage << " dégâts à "
        << defender->getName() << "!\n";
}

std::string Fireball::getName() const {
    return "BOULE DE FEU";
}