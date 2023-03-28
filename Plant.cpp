#include "Plant.h"

Plant::Plant(World* world, position_t pos, const char* nameOfClass, const char signForClass, int strength, int initiative) : Organism(world, pos, nameOfClass, signForClass, strength, initiative){}

void Plant::WritePlantsReplicated()
{
	string mess = "roslina gatunku ";
	mess += this->GetName();
	mess += " rozsiala sie";
	this->world->AddToString(mess);
}

position_t Plant::FindPlaceForChild(position_t posOfStaticParent)
{
	bool allowToPass = false;
	position_t tmpPos;
	int i = 0;
	while (!allowToPass)
	{
		tmpPos = Organism::GetRandomisedPos(posOfStaticParent);
		if (Organism::CheckIsInBounds(tmpPos, this->world->GetMeasurements()))
			if (CheckIfPositionIsOccupied(this->world, tmpPos) == nullptr)
			{
				this->WritePlantsReplicated();
				return tmpPos;
				allowToPass = true;
			}
		i++;
		if (i > DIRECTIONS)
			allowToPass = true;
	}
	return NULL_POSITION;
	
}

void Plant::Action(World* world)
{
	srand(time(NULL));
	int replicationChance = rand() % CHANCE_FOR_PLANT_TO_REPLICATE;
	if (replicationChance == 0 && this->GetAge() > AGE_TO_REPLICATE)
		world->AddOrganismToWorld(Reproduction(this->GetPosition()));
	this->age++;
}

Collisions Plant::Collision(Organism* attacker)
{
	this->WriteThatPlantWasEaten(attacker->GetName());
	this->Die();
	return MOVE;
}

void Plant::WriteThatPlantWasEaten(string attackersName)
{
	string mess = attackersName;
	mess += " zjada ";
	mess += this->GetName();
	this->world->AddToString(mess);
}