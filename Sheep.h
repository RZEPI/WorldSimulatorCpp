#pragma once
#include "Animal.h"

class Sheep :
    public Animal
{
protected:
    int age = 0;
    position_t pos;
    int strength = SHEEP_STRENGTH;
    int initiative = SHEEP_INIT;
    const char* nameOfClass = SHEEP_NAME;
    const char signForClass = SHEEP_SIGN;
    bool IsSameGenere(Organism* defender) override;
    Organism* Reproduction(position_t posOfStaticParent) override;
public:
    Sheep(World* world, position_t pos);
    Sheep(World* world, position_t pos, int strength);
};

