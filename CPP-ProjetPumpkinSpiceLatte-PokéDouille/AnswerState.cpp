#include "AnswerState.hpp"
#include "EnemyTurnState.hpp"
#include "PlayerTurnState.hpp"
#include <iostream>
#include <cstdlib>

AnswerState::AnswerState(bool wasPlayerTurn) : wasPlayerTurn_(wasPlayerTurn) {}

void AnswerState::handle(BattleContext* context) {
    std::cout << "\nAppuie sur ENTREE pour continuer...\n";
    std::cin.get();

    system("cls");

    // Passer au prochain tour
    if (wasPlayerTurn_) {
        context->setState(new EnemyTurnState());
    }
    else {
        context->setState(new PlayerTurnState());
    }
}