#pragma once
#include "Animal.h"

class Fox :
    public Animal
{
protected:
    int age = 0;
    int strength = FOX_STRENGTH;
    int initiative = FOX_INIT;
    position_t pos;
    const char* nameOfClass = FOX_NAME;
    const char signForClass = FOX_SIGN;
    bool IsSameGenere(Organism* defender) override;
    Organism* Reproduction(position_t posOfStaticParent) override;
public:
    void Action(World* world) override;
    Fox(World* world, position_t pos);
    Fox(World* world, position_t pos, int strength);
};

