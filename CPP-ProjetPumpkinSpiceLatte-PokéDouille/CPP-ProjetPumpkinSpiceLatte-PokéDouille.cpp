// CPP-ProjetPumpkinSpiceLatte-PokéDouille.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "PokeDouille.hpp"
#include "FastAttack.hpp"
#include "Fireball.hpp"

int main() {
    srand(static_cast<unsigned>(time(0)));

    PokeDouille player("Pikadouille", 50);
    PokeDouille enemy("Salamouchette", 50);

    FastAttack fast;
    Fireball fire;

    player.addAttack(&fast);
    player.addAttack(&fire);

    enemy.addAttack(&fast);
    enemy.addAttack(&fire);


    std::cout << "=== Combat Poké Douille ===\n";

    while (player.getHp() > 0 && enemy.getHp() > 0) {
        // --- Tour du joueur ---
        std::cout << "\nTes PV : " << player.getHp()
            << " | PV ennemi : " << enemy.getHp() << "\n";
        std::cout << "Choisis une attaque :\n";
        for (size_t i = 0; i < 2; ++i) {
            std::cout << i << " - " << player.chooseAttack(i)->getName() << "\n";
        }

        int choice;
        std::cin >> choice;

        if (choice < 0 || choice > 1) choice = 0;
        Attack* atk = player.chooseAttack(choice);
        atk->execute(&player, &enemy);

        if (enemy.getHp() <= 0) break;

        // --- Tour de l'ennemi ---
        int enemyChoice = rand() % 2;
        Attack* enemyAtk = enemy.chooseAttack(enemyChoice);
        enemyAtk->execute(&enemy, &player);
    }

    if (player.getHp() > 0) {
        std::cout << "\nTu as gagné ! \n";
    }
    else {
        std::cout << "\nTu as perdu... \n";
    }

    return 0;
}
