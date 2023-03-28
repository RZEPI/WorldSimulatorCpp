#include "Fox.h"

Fox::Fox(World* world, position_t pos) : Animal(world, pos, FOX_NAME, FOX_SIGN, FOX_STRENGTH, FOX_INIT){}

Fox::Fox(World* world, position_t pos, int strength) : Animal(world, pos, FOX_NAME, FOX_SIGN, strength, FOX_INIT) {}

bool Fox::IsSameGenere(Organism* defender)
{
	return dynamic_cast<Fox*>(defender) != nullptr;
}

Organism* Fox::Reproduction(position_t posOfStaticParent)
{
	position_t tmpPos = this->FindPlaceForChild(posOfStaticParent);
	position_t nullPos = NULL_POSITION;
	if (tmpPos.x == nullPos.x && tmpPos.y == nullPos.y)
		return nullptr;
	else
		return new Fox(this->world, tmpPos);
}

void Fox::Action(World* world)
{
	bool allowToMove = false;
	while (!allowToMove)
	{
		position_t tmpPos = Organism::GetRandomisedPos(this->GetPosition());
		if (Organism::CheckIsInBounds(tmpPos, world->GetMeasurements()))
		{
			Organism* defender = this->CheckIfPositionIsOccupied(world, tmpPos);
			if (defender != nullptr && this != defender)
			{
				if (defender->GetStrength() > this->GetStrength())
					allowToMove = false;
				else if (IsSameGenere(defender))
				{
					world->AddOrganismToWorld(Reproduction(defender->GetPosition()));
					this->SetAgeToZero();
					defender->SetAgeToZero();
				}
				else
				{
					string mess = this->GetName();
					mess += " atakuje ";
					mess += defender->GetName();
					world->AddToString(mess);
					this->HandleCollision(defender->Collision(this), tmpPos);
				}
			}
			else
			{
				this->SetPosition(tmpPos);
			}
			allowToMove = true;
		}
	}
	this->age++;
}