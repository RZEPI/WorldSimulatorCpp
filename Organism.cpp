#include "Organism.h"
#include <ctime>
#include <string>
#include <cstdlib>

void Organism::Die()
{
	this->alive = false;
}

bool Organism::IsAlive() const
{
	return this->alive;
}

void Organism::GiveBoost(const int value)
{
	this->strength += value;
}

position_t Organism::GetPosition() const
{
	return this->position;
}

int Organism::GetAge() const
{
	return this->age;
}

int Organism::GetInitiative() const
{
	return this->initiative;
}

int Organism::GetStrength() const
{
	return this->strength;
}

char Organism::GetSign() const
{
	return this->signForClass;
}
const char* Organism::GetName() const
{
	return this->nameOfClass;
}

void Organism::SetStrength(int value)
{
	this->strength = value;
}

void Organism::SetPosition(position_t newPos)
{
	this->position = newPos;
}

void Organism::SetInitiative(int initiative)
{
	this->initiative = initiative;
}

void Organism::SetNameOfClass(const char* nameOfClass)
{
	this->nameOfClass = nameOfClass;
}

void Organism::SetSignForClass(const char signForClass)
{
	this->signForClass = signForClass;
}

int Organism::GetID() const
{
	switch (this->GetSign())
	{
	case WOLF_SIGN:
		return WOLF;
		break;
	case SHEEP_SIGN:
		return SHEEP;
		break;
	case FOX_SIGN:
		return FOX;
		break;
	case TURTLE_SIGN:
		return TURTLE;
		break;
	case ANTYLOPE_SIGN:
		return ANTYLOPE;
		break;
	case GRASS_SIGN:
		return GRASS;
		break;
	case MILT_SIGN:
		return MILT;
		break;
	case GUARANA_SIGN:
		return GUARANA;
		break;
	case BELLADONNA_SIGN:
		return BELLADONNA;
		break;
	case SOSHOGWEED_SIGN:
		return SOSHOGWEED;
		break;
	case HUMAN_SIGN:
		return HUMAN;
	}
}

void Organism::HandleCollision(Collisions typeOfCollison, position_t destPos)
{
	string mess;
	Organism* defender = Organism::CheckIfPositionIsOccupied(world, destPos);
	switch (typeOfCollison)
	{
	case DEATH:
		mess = this->GetName();
		this->Die();
		mess += " umiera";
		break;
	case HUMAN_ALZUERES_SHIELD:
		destPos = Organism::GetRandomisedPos(destPos);
		mess = this->GetName();
		if (defender == nullptr)
			this->SetPosition(destPos);
		else
		{
			Collisions col = defender->Collision(this);
			this->HandleCollision(col, destPos);
		}
		mess += " zostal odbity przez Tarcze Alzura";
		break;
	case TURTLE_COUNTER:
		mess = this->GetName();
		mess += " zostal odbity przez zlowia";
		break;
	case GUARANA_BOOST:
		mess = this->GetName();
		this->SetStrength(this->GetStrength() + GUARANA_BOOST_VAL);
		mess += " dostal +3 bonusu do sily";
		this->SetPosition(destPos);
		break;
	case MOVE:
		this->SetPosition(destPos);
		break;
	}
	this->world->AddToString(mess);
}

void Organism::SetMove(char key)
{
	this->actionKey = key;
}

position_t Organism::ChoosePos(int num, position_t tmpPos)
{
	switch (num)
	{
	case UP:
		tmpPos.y = tmpPos.y - 1;
		break;
	case UP_RIGHT:
		tmpPos.y = tmpPos.y - 1;
		tmpPos.x = tmpPos.x + 1;
		break;
	case UP_LEFT:
		tmpPos.y = tmpPos.y - 1;
		tmpPos.x = tmpPos.x - 1;
		break;
	case DOWN:
		tmpPos.y = tmpPos.y + 1;
		break;
	case DOWN_RIGHT:
		tmpPos.x = tmpPos.x + 1;
		tmpPos.y = tmpPos.y + 1;
		break;
	case DOWN_LEFT:
		tmpPos.x = tmpPos.x - 1;
		tmpPos.y = tmpPos.y + 1;
		break;
	case RIGHT:
		tmpPos.x = tmpPos.x + 1;
		break;
	case LEFT:
		tmpPos.x = tmpPos.x - 1;
		break;
	}
	return tmpPos;
}

bool Organism::CheckIsInBounds(position_t tmpPos, position_t worldMeausrements)
{
	if (tmpPos.y >= 0 && tmpPos.y < worldMeausrements.y && tmpPos.x < worldMeausrements.x && tmpPos.x >= 0)
		return true;
	else
		return false;
}

position_t Organism::GetRandomisedPos(position_t tmpPos)
{
	srand(time(NULL));
	int randNum = rand() % 8;
	return Organism::ChoosePos(randNum, tmpPos);
}

Organism::Organism(World* world, position_t pos, const char* nameOfClass, char signForClass, int strength, int initiative)
{
	this->world = world;
	this->SetPosition(pos);
	this->SetStrength(strength);
	this->SetInitiative(initiative);
	this->SetNameOfClass(nameOfClass);
	this->SetSignForClass(signForClass);
	world->AddOrganismToWorld(this);
}

void Organism::IsInDeadRange()
{
	string mess = this->GetName();
	mess += " znalazl sie w zasiegu barszczu sosnowskiego i umiera";
	this->world->AddToString(mess);
	this->Die();
}

void Organism::SetAgeToZero()
{
	this->age = 0;
}

Organism* Organism::CheckIfPositionIsOccupied(World* world, position_t pos)
{
	for (int i = 0; i < world->GetOrganismsSize(); i++)
	{
		position_t tmpPos = world->GetOrganismsOnIndex(i)->GetPosition();
		if (pos.x == tmpPos.x && pos.y == tmpPos.y)
			return world->GetOrganismsOnIndex(i);
	}
	return nullptr;
}

Organism::~Organism()
{
	this->Die();
}
