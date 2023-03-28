#include "Guarana.h"

Guarana::Guarana(World* world, position_t pos) : Plant(world, pos, GUARANA_NAME, GUARANA_SIGN, GUARANA_STRENGTH, PLANT_INIT){}

Organism* Guarana::Reproduction(position_t posOfStaticParent)
{
	position_t tmpPos = this->FindPlaceForChild(posOfStaticParent);
	position_t nullPos = NULL_POSITION;
	if (tmpPos.x == nullPos.x && tmpPos.y == nullPos.y)
		return nullptr;
	else
		return new Guarana(this->world, tmpPos);
}

Collisions Guarana::Collision(Organism* attacker)
{
	this->WriteThatPlantWasEaten(attacker->GetName());
	this->Die();
	return GUARANA_BOOST;
}