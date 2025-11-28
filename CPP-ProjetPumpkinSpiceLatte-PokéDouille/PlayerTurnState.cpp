#include "PlayerTurnState.hpp"
#include "VictoryState.hpp"
#include "AnswerState.hpp"
#include <iostream>
#include <limits>

void PlayerTurnState::handle(BattleContext* context) {
    PokeDouille* player = context->getPlayer();
    PokeDouille* enemy = context->getEnemy();

    // Si le joueur est en train de charger une attaque
    if (player->isCharging()) {
        std::cout << "\n=== TON TOUR (ATTAQUE EN CHARGE) ===\n";
        std::cout << "Tes PV : " << player->getHp()
            << " | PV ennemi : " << enemy->getHp() << "\n";

        // L'attaque chargée se déclenche automatiquement
        Attack* chargingAtk = player->getChargingAttack();
        chargingAtk->execute(player, enemy);

        if (enemy->getHp() <= 0) {
            context->setState(new VictoryState());
        }
        else {
            context->setState(new AnswerState(true));
        }
        return;
    }

    std::cout << "\n=== TON TOUR ===\n";
    std::cout << "Tes PV : " << player->getHp()
        << " | PV ennemi : " << enemy->getHp() << "\n";
    std::cout << "Choisis une attaque :\n";

    for (size_t i = 0; i < player->attacks.size(); ++i) {
        Attack* atk = player->chooseAttack(i);
        std::cout << i << " - " << atk->getName()
            << " (" << atk->getCurrentPP() << "/" << atk->getMaxPP() << " PP)";
        if (!atk->canUse()) std::cout << " [INDISPONIBLE]";
        std::cout << "\n";
    }

    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (choice < 0 || choice > player->attacks.size()) choice = 0;

    Attack* atk = player->chooseAttack(choice);

    if (!atk->canUse()) {
        std::cout << "Cette attaque n'a plus de PP !\n";
        return;
    }

    atk->execute(player, enemy);

    if (enemy->getHp() <= 0) {
        context->setState(new VictoryState());
    }
    else {
        context->setState(new AnswerState(true));
    }
}