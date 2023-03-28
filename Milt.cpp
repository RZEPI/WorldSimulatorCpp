#include "Milt.h"


Milt::Milt(World* world, position_t pos) : Plant(world, pos, MILT_NAME, MILT_SIGN, MILT_STRENGTH, PLANT_INIT) {}

Organism* Milt::Reproduction(position_t posOfStaticParent)
{
	position_t tmpPos = this->FindPlaceForChild(posOfStaticParent);
	position_t nullPos = NULL_POSITION;
	if (tmpPos.x == nullPos.x && tmpPos.y == nullPos.y)
		return nullptr;
	else
		return new Milt(this->world, tmpPos);
}

void Milt::Action(World* world)
{
	for (int i = 0; i < TRIES_OF_MILT_REPLICATION; i++)
	{
		srand(time(NULL));
		int replicationChance = rand() % CHANCE_FOR_PLANT_TO_REPLICATE;
		if (replicationChance == 0 && this->GetAge()!= 0)
		{
			world->AddOrganismToWorld(Reproduction(this->GetPosition()));
			break;
		}
	}	
	this->age++;
}