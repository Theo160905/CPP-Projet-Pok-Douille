#pragma once
#include "PokeDouille.hpp"

class BattleContext;

class BattleState {
protected:
    BattleContext* context_;
public:
    virtual ~BattleState() {}
    void set_context(BattleContext* context);
    virtual void handle(BattleContext* context) = 0;
};

class BattleContext {
private:
    BattleState* currentState_;
    PokeDouille* player_;
    PokeDouille* enemy_;
    bool battleEnded_;

public:
    BattleContext(BattleState* state, PokeDouille* player, PokeDouille* enemy);
    ~BattleContext();

    void setState(BattleState* state);
    void update();

    bool isBattleEnded() const;
    void endBattle();

    PokeDouille* getPlayer();
    PokeDouille* getEnemy();
};