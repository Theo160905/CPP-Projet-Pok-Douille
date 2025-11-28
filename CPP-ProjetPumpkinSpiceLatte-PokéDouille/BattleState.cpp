#include "BattleState.hpp"

void BattleState::set_context(BattleContext* context) {
    this->context_ = context;
}

BattleContext::BattleContext(BattleState* state, PokeDouille* player, PokeDouille* enemy)
    : currentState_(nullptr), player_(player), enemy_(enemy), battleEnded_(false) {
    this->setState(state);
}

BattleContext::~BattleContext() {
    delete currentState_;
}

void BattleContext::setState(BattleState* state) {
    if (this->currentState_ != nullptr)
        delete this->currentState_;
    this->currentState_ = state;
    this->currentState_->set_context(this);
}

void BattleContext::update() {
    this->currentState_->handle(this);
}

bool BattleContext::isBattleEnded() const {
    return battleEnded_;
}

void BattleContext::endBattle() {
    battleEnded_ = true;
}

PokeDouille* BattleContext::getPlayer() {
    return player_;
}

PokeDouille* BattleContext::getEnemy() {
    return enemy_;
}