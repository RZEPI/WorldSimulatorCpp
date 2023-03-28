#pragma once
#include "Plant.h"

class Grass :
    public Plant
{
protected:
    const int strength = GRASS_STRENGTH;
    const char* nameOfClass = GRASS_NAME;
    const char signOfClass = GRASS_SIGN;
    Organism* Reproduction(position_t posOfStaticParent);
public:
    Grass(World* world, position_t pos);
};

