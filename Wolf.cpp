#include "Wolf.h"

bool Wolf::IsSameGenere(Organism* defender)
{
	return dynamic_cast<Wolf*>(defender) != nullptr;
}

Wolf::Wolf(World* world, position_t pos):Animal(world, pos, WOLF_NAME, WOLF_SIGN, WOLF_SIGN, WOLF_INIT){}

Wolf::Wolf(World* world, position_t pos, int strength) : Animal(world, pos, WOLF_NAME, WOLF_SIGN, strength, WOLF_INIT) {}

Organism* Wolf::Reproduction(position_t posOfStaticParent)
{
	position_t tmpPos = this->FindPlaceForChild(posOfStaticParent);
	position_t nullPos = NULL_POSITION;
	if (tmpPos.x == nullPos.x && tmpPos.y == nullPos.y)
		return nullptr;
	else
		return new Wolf(this->world, tmpPos);
}