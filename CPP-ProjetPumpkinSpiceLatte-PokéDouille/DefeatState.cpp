#include "DefeatState.hpp"
#include <iostream>

void DefeatState::handle(BattleContext* context) {
    std::cout << "\n=== DEFAITE ===\n";
    std::cout << "Tu as perdu... Réessaye !\n";
    std::cout << "PV ennemis restants : " << context->getEnemy()->getHp() << "\n";
    context->endBattle();
}