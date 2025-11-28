#include "VictoryState.hpp"
#include <iostream>

void VictoryState::handle(BattleContext* context) {
    std::cout << "\n=== VICTOIRE ===\n";
    std::cout << "Tu as gagne ! Felicitations !\n";
    std::cout << "PV restants : " << context->getPlayer()->getHp() << "\n";
    context->endBattle();
}