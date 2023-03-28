#pragma once
#include "Plant.h"



class Belladonna :
    public Plant
{
protected:
    const int strength = BELLADONNA_STRENGTH;
    const char* nameOfClass = BELLADONNA_NAME;
    const char signOfClass = BELLADONNA_SIGN;
    Organism* Reproduction(position_t posOfStaticParent);
public:
    Belladonna(World* world, position_t pos);
    Collisions Collision(Organism* attacker) override;
};

