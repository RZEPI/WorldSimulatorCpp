#pragma once
#include "Animal.h"
#include <conio.h>

class Human :
    public Animal
{
protected:
    int age = 0;
    int durationOfAbility = 0;
    int cooldownOfAbility = 0;
    int strength = HUMAN_STRENGTH;
    int initiative = HUMAN_INIT;
    position_t pos;
    const char* nameOfClass = HUMAN_NAME;
    const char signForClass = HUMAN_SIGN;
    Collisions Collision(Organism* attacker) override;
    bool effectOfAbility = false;
    bool IsSameGenere(Organism* defender) override;
    Organism* Reproduction(position_t posOfStaticParent) override;
    void Ability();//Alzure's shield
public:
    char GetMove() const;
    void Action(World* world) override;
    Human(World* world, position_t pos);
    Human(World* world, position_t pos, int strength);
    bool GetEffect() const;
};

