#pragma once
#include <string>
class PokeDouille;

class Attack {
public:
    virtual void execute(PokeDouille* attacker, PokeDouille* defender) = 0;
    virtual std::string getName() const = 0;
    virtual ~Attack() {}
};
