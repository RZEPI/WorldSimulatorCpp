#pragma once
#include "Organism.h"
class Plant :
    public Organism
{
protected:
    virtual Organism* Reproduction(position_t posOfStaticParent) =0;
    void WriteThatPlantWasEaten(string attackersName);
    position_t FindPlaceForChild(position_t posOfStaticParent) override;
    virtual Collisions Collision(Organism* attacker);
    void WritePlantsReplicated();
public:
    void Action(World* world) override;
    Plant(World* world, position_t pos, const char* nameOfClass, const char signForClass, int strength, int initiative);
};

