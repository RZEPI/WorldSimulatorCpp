#pragma once
#include "Plant.h"

class Guarana :
    public Plant
{
protected:
    const int strength = GUARANA_STRENGTH;
    const char* nameOfClass = GUARANA_NAME;
    const char signOfClass = GUARANA_SIGN;
    Organism* Reproduction(position_t posOfStaticParent);
public:
    Guarana(World* world, position_t pos);
    Collisions Collision(Organism* attacker) override;
};

