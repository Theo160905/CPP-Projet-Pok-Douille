#pragma once
#include <string>
#include <vector>
#include "Attack.hpp"

class PokeDouille {
private:
    std::string name;
    int hp;
    std::vector<Attack*> attacks;

public:
    PokeDouille(std::string n, int health);
    void addAttack(Attack* atk);
    void takeDamage(int dmg);
    std::string getName() const;
    int getHp() const;
    Attack* chooseAttack(int index);
};