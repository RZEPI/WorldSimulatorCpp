#pragma once
#include "Animal.h"

class Turtle :
    public Animal
{
protected:
    int age = 0;
    position_t pos;
    int strength = TURTLE_STRENGTH;
    int initiative = TURTLE_INIT;
    const char* nameOfClass = TURTLE_NAME;
    bool IsSameGenere(Organism* defender) override;
    const char signForClass = TURTLE_SIGN;
    Organism* Reproduction(position_t posOfStaticParent) override;
public:
    void Action(World* world) override;
    Collisions Collision(Organism* attacker) override;
    Turtle(World* world, position_t pos);
    Turtle(World* world, position_t pos, int strength);
};

