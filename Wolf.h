#pragma once
#include "Animal.h"

class Wolf :
    public Animal
{
protected:
    int age = 0;
    position_t pos;
    int strength = WOLF_STRENGTH;
    int initiative = WOLF_INIT;
    const char* nameOfClass = WOLF_NAME;
    const char signForClass = WOLF_SIGN;
    bool IsSameGenere(Organism* defender) override;
    Organism* Reproduction(position_t posOfStaticParent) override;
public:
    Wolf(World* world, position_t pos);
    Wolf(World* world, position_t pos, int strength);
};

