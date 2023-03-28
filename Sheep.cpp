#include "Sheep.h"

Sheep::Sheep(World* world, position_t pos) : Animal(world, pos, SHEEP_NAME, SHEEP_SIGN, SHEEP_STRENGTH, SHEEP_INIT){}

Sheep::Sheep(World* world, position_t pos, int strength) : Animal(world, pos, SHEEP_NAME, SHEEP_SIGN, strength, SHEEP_INIT) {}

Organism* Sheep::Reproduction(position_t posOfStaticParent)
{
	position_t tmpPos = this->FindPlaceForChild(posOfStaticParent);
	position_t nullPos = NULL_POSITION;
	if (tmpPos.x == nullPos.x && tmpPos.y == nullPos.y)
		return nullptr;
	else
		return new Sheep(this->world, tmpPos);
}

bool Sheep::IsSameGenere(Organism* defender)
{
	return dynamic_cast<Sheep*>(defender) != nullptr;
}