#pragma once
#include "Organism.h"
#include "declarations.h"
class Animal :
    public Organism
{
protected:
    virtual bool IsSameGenere(Organism* defender) = 0;
    virtual Organism* Reproduction(position_t posOfStaticParent) = 0;
    Animal(World* world, position_t pos, const char* nameOfClass, char signForClass, int strength, int initiative);
    position_t FindPlaceForChild(position_t posOfStaticParent) override;
    void WriteAnimalsReplicated();
public:
    virtual void Action(World* world);
    Collisions Collision(Organism* attacker) override;

};

