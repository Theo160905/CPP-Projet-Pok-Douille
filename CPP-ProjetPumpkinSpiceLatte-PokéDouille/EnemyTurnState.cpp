#include "EnemyTurnState.hpp"
#include "DefeatState.hpp"
#include "AnswerState.hpp"
#include <iostream>
#include <cstdlib>

void EnemyTurnState::handle(BattleContext* context) {
    PokeDouille* player = context->getPlayer();
    PokeDouille* enemy = context->getEnemy();

    std::cout << "\n=== TOUR DE L'ENNEMI ===\n";

    int enemyChoice = rand() % 2;
    Attack* enemyAtk = enemy->chooseAttack(enemyChoice);

    std::cout << enemy->getName() << " utilise " << enemyAtk->getName() << " !\n";
    enemyAtk->execute(enemy, player);

    // Vérifier si le joueur est KO
    if (player->getHp() <= 0) {
        context->setState(new DefeatState());
    }
    else {
        context->setState(new AnswerState(false));
    }
}