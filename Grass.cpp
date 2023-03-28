#include "Grass.h"

Grass::Grass(World* world, position_t pos) : Plant(world, pos, GRASS_NAME, GRASS_SIGN, GRASS_STRENGTH, PLANT_INIT){}

Organism* Grass::Reproduction(position_t posOfStaticParent)
{
	position_t tmpPos = this->FindPlaceForChild(posOfStaticParent);
	position_t nullPos = NULL_POSITION;
	if (tmpPos.x == nullPos.x && tmpPos.y == nullPos.y)
		return nullptr;
	else
		return new Grass(this->world,tmpPos);
}