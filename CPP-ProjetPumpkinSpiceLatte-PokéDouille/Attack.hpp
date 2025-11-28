#pragma once
#include <string>

class PokeDouille;

class Attack {
protected:
    int currentPP;
    int maxPP;

public:
    Attack(int pp) : currentPP(pp), maxPP(pp) {}

    virtual void execute(PokeDouille* attacker, PokeDouille* defender) = 0;
    virtual std::string getName() const = 0;
    virtual ~Attack() {}

    bool canUse() const { return currentPP > 0; }
    void usePP() { if (currentPP > 0) currentPP--; }
    void restorePP() { currentPP = maxPP; }
    int getCurrentPP() const { return currentPP; }
    int getMaxPP() const { return maxPP; }

    virtual bool needsCharging() const { return false; }
};