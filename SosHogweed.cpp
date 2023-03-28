#include "SosHogweed.h"
#include "Animal.h"

SosHogweed::SosHogweed(World* world, position_t pos) : Plant(world, pos, SOSHOGWEED_NAME, SOSHOGWEED_SIGN, SOSHOGWEED_STRENGTH, PLANT_INIT) {}

Organism* SosHogweed::Reproduction(position_t posOfStaticParent)
{
	position_t tmpPos = this->FindPlaceForChild(posOfStaticParent);
	position_t nullPos = NULL_POSITION;
	if (tmpPos.x == nullPos.x && tmpPos.y == nullPos.y)
		return nullptr;
	else
		return new SosHogweed(this->world, tmpPos);
}

Collisions SosHogweed::Collision(Organism* attacker)
{
	this->WriteThatPlantWasEaten(attacker->GetName());
	this->Die();
	return DEATH;
}

void SosHogweed::Action(World* world)
{
	for (int i = 0; i < 8; i++)
	{
		position_t tmpPos = ChoosePos(i, this->GetPosition());
		Organism* orgInRange = Organism::CheckIfPositionIsOccupied(world, tmpPos);
		if (orgInRange == nullptr)
			continue;
		else if (dynamic_cast<Animal*>(orgInRange) != nullptr && orgInRange->IsAlive())
			orgInRange->IsInDeadRange();
	}
	srand(time(NULL));
	int replicationChance = rand() % CHANCE_FOR_PLANT_TO_REPLICATE;
	if (replicationChance == 0 && this->GetAge() > AGE_TO_REPLICATE)
		this->world->AddOrganismToWorld(Reproduction(this->GetPosition()));
	this->age++;
}
Collisions SosHogweed::CollisionWithNeighField(string attackersName)
{
	string mess = attackersName + " stoi przy ";
	mess += this->GetName();
	this->world->AddToString(mess);
	return DEATH;
}