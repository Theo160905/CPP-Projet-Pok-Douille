// CPP-ProjetPumpkinSpiceLatte-PokéDouille.cpp

#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

#include "PokeDouille.hpp"
#include "BasicAttack.hpp"
#include "ChargedAttack.hpp"
#include "BattleState.hpp"
#include "PlayerTurnState.hpp"
#include "EnemyTurnState.hpp"
#include "AnswerState.hpp"
#include "VictoryState.hpp"
#include "DefeatState.hpp"


int main(){
    std::cout <<
        R"(
                                            
 _ _ _     _                      _____     
| | | |___| |___ ___ _____ ___   |_   _|___ 
| | | | -_| |  _| . |     | -_|    | | | . |
|_____|___|_|___|___|_|_|_|___|    |_| |___|
                                            
)";
    std::this_thread::sleep_for(std::chrono::seconds(5)); //wait 5 sec

    std::cout <<
R"(
$$$$$$$\   $$$$$$\  $$\   $$\ $$$$$$$$\ $$$$$$$\   $$$$$$\  $$\   $$\ $$$$$$\ $$\       $$\       $$$$$$$$\ 
$$  __$$\ $$  __$$\ $$ | $$  |$$  _____|$$  __$$\ $$  __$$\ $$ |  $$ |\_$$  _|$$ |      $$ |      $$  _____|
$$ |  $$ |$$ /  $$ |$$ |$$  / $$ |      $$ |  $$ |$$ /  $$ |$$ |  $$ |  $$ |  $$ |      $$ |      $$ |      
$$$$$$$  |$$ |  $$ |$$$$$  /  $$$$$\    $$ |  $$ |$$ |  $$ |$$ |  $$ |  $$ |  $$ |      $$ |      $$$$$\    
$$  ____/ $$ |  $$ |$$  $$<   $$  __|   $$ |  $$ |$$ |  $$ |$$ |  $$ |  $$ |  $$ |      $$ |      $$  __|   
$$ |      $$ |  $$ |$$ |\$$\  $$ |      $$ |  $$ |$$ |  $$ |$$ |  $$ |  $$ |  $$ |      $$ |      $$ |      
$$ |       $$$$$$  |$$ | \$$\ $$$$$$$$\ $$$$$$$  | $$$$$$  |\$$$$$$  |$$$$$$\ $$$$$$$$\ $$$$$$$$\ $$$$$$$$\ 
\__|       \______/ \__|  \__|\________|\_______/  \______/  \______/ \______|\________|\________|\________|                                                                                                                                                                       
)";

    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("cls"); //effacer toutes la console

    // Création des Pokédouilles
    PokeDouille player("Bubblastea", 200);
    PokeDouille enemy("Capucciono", 200);

    BasicAttack fastAttack("Perle-Canon", 10, 35);
    BasicAttack heavyAttack("Tourbillon Lait-The", 25, 10);
    BasicAttack megaPunch("Mega Poing", 40, 5);
    ChargedAttack laser("Ultralaser", 70, 5);
    
    player.addAttack(&fastAttack);
    player.addAttack(&laser);
    player.addAttack(&heavyAttack);

    enemy.addAttack(&fastAttack);
    enemy.addAttack(&megaPunch);

    std::cout << "=== POKEDOUILLE - COMBAT ===\n";
    std::cout << player.getName() << " VS " << enemy.getName() << "\n";

    BattleContext battle(new PlayerTurnState(), &player, &enemy);

    while (!battle.isBattleEnded()) {battle.update();}
    
    std::cout << "\n=== FIN DU COMBAT ===\n";
    return 0;

}