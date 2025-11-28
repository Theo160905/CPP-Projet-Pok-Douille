#pragma once
#include <string>
#include <vector>
#include "Attack.hpp"

class PokeDouille {
public:
    std::string name;
    int hp;
    std::vector<Attack*> attacks;
    Attack* chargingAttack;

public:
    PokeDouille(std::string n, int health);
    void addAttack(Attack* atk);
    void takeDamage(int dmg);
    std::string getName() const;
    int getHp() const;
    Attack* chooseAttack(int index);

    void setChargingAttack(Attack* atk) { chargingAttack = atk; }
    Attack* getChargingAttack() const { return chargingAttack; }
    bool isCharging() const { return chargingAttack != nullptr; }
    void releaseCharge() { chargingAttack = nullptr; }
};