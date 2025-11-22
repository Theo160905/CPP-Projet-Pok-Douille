#include "PokeDouille.hpp"

PokeDouille::PokeDouille(std::string n, int health) : name(n), hp(health) {}

void PokeDouille::addAttack(Attack* atk) { attacks.push_back(atk); }

void PokeDouille::takeDamage(int dmg) { hp -= dmg; if (hp < 0) hp = 0; }

std::string PokeDouille::getName() const { return name; }

int PokeDouille::getHp() const { return hp; }

Attack* PokeDouille::chooseAttack(int index) { return attacks[index]; }
