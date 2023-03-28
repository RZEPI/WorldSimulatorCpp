#pragma once
#include "Plant.h"

class SosHogweed :
    public Plant
{
protected:
    const int strength = SOSHOGWEED_STRENGTH;
    const char* nameOfClass = SOSHOGWEED_NAME;
    const char signOfClass = SOSHOGWEED_SIGN;
    Organism* Reproduction(position_t posOfStaticParent);
    Collisions CollisionWithNeighField(string attackersName);
public:
    void Action(World* world) override;
    SosHogweed(World* world, position_t pos);
    Collisions Collision(Organism* attacker) override;
};

