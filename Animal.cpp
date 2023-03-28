#include "Animal.h"

void Animal::WriteAnimalsReplicated()
{
	string mess = "zwierzeta o gatunku ";
	mess += this->GetName();
	mess += " sie rozmnozyly";
	world->AddToString(mess);
}

position_t Animal::FindPlaceForChild(position_t posOfStaticParent)
{
	bool allowToPass = false;
	int i = 0;
	position_t tmpPos;
	while (!allowToPass)
	{
		tmpPos = Organism::GetRandomisedPos(posOfStaticParent);
		if (Organism::CheckIsInBounds(tmpPos, world->GetMeasurements()))
			if (CheckIfPositionIsOccupied(world, tmpPos) == nullptr)
			{
				allowToPass = true;
				this->WriteAnimalsReplicated();
				return tmpPos;
			}
		i++;
		if (i > DIRECTIONS)
			allowToPass = true;
			
	}
	return NULL_POSITION;
}

Animal::Animal(World* world, position_t pos, const char* nameOfClass, char signForClass, int strength, int initiative) : Organism(world, pos, nameOfClass, signForClass, strength, initiative){}

void Animal::Action(World* world)
{
	bool allowToMove = false;
	while (!allowToMove)
	{
		position_t tmpPos = Organism::GetRandomisedPos(this->GetPosition());
		if (Organism::CheckIsInBounds(tmpPos, world->GetMeasurements()))
		{
			Organism* defender = this->CheckIfPositionIsOccupied(world, tmpPos);
			if (defender != nullptr)
			{
				if (IsSameGenere(defender))
				{
					if (this->GetAge() > 0 && defender->GetAge() > AGE_TO_REPLICATE)
					{
						world->AddOrganismToWorld(Reproduction(tmpPos));
						this->SetAgeToZero();
						defender->SetAgeToZero();
					}
				}
				else
				{
					string mess = this->GetName();
					mess += " atakuje ";
					mess += defender->GetName();
					world->AddToString(mess);
					this->HandleCollision(defender->Collision(this), tmpPos);
				}
				
				allowToMove = true;
			}
			else
			{
				this->SetPosition(tmpPos);
				allowToMove = true;
			}
		}
	}
	this->age++;
}

Collisions Animal::Collision(Organism* attacker)
{
	if (this->GetStrength() > attacker->GetStrength())
	{
		return DEATH;
	}
	else
	{
		string mess = this->GetName();
		mess += " umiera";
		this->world->AddToString(mess);
		this->Die();
		return MOVE;
	}
}