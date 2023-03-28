#include "Belladonna.h"

Belladonna::Belladonna(World* world, position_t pos) : Plant(world, pos, BELLADONNA_NAME, BELLADONNA_SIGN, BELLADONNA_STRENGTH, PLANT_INIT){}

Organism* Belladonna::Reproduction(position_t posOfStaticParent)
{
	position_t tmpPos = this->FindPlaceForChild(posOfStaticParent);
	position_t nullPos = NULL_POSITION;
	if (tmpPos.x == nullPos.x && tmpPos.y == nullPos.y)
		return nullptr;
	else
		return new Belladonna(this->world, tmpPos);
}

Collisions Belladonna::Collision(Organism* attacker)
{
	this->WriteThatPlantWasEaten(attacker->GetName());
	this->Die();
	return DEATH;
}