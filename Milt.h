#pragma once
#include "Plant.h"

class Milt :
    public Plant
{
protected:
    const int strength = MILT_STRENGTH;
    const char* nameOfClass = MILT_NAME;
    const char signOfClass = MILT_SIGN;
    Organism* Reproduction(position_t posOfStaticParent);
public:
    void Action(World* world) override;
    Milt(World* world, position_t pos);
};

