#pragma once
#include "Animal.h"

class Antylope :
    public Animal
{
protected:
    int age = 0;
    int strength = ANTYLOPE_STRENGTH;
    int initiative = ANTYLOPE_INIT;
    position_t pos;
    const char* nameOfClass = ANTYLOPE_NAME;
    const char signForClass = ANTYLOPE_SIGN;
    bool IsSameGenere(Organism* defender) override;
    Organism* Reproduction(position_t posOfStaticParent) override;
public:
    void Action(World* world) override;
    Antylope(World* world, position_t pos);
    Antylope(World* world, position_t pos, int strength);
    Collisions Collision(Organism* attacker) override;
};

