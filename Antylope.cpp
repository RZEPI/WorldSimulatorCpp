#include "Antylope.h"

Antylope::Antylope(World* world, position_t pos): Animal(world, pos, ANTYLOPE_NAME, ANTYLOPE_SIGN, ANTYLOPE_STRENGTH, ANTYLOPE_INIT){}

Antylope::Antylope(World* world, position_t pos, int strength) : Animal(world, pos, ANTYLOPE_NAME, ANTYLOPE_SIGN, strength, ANTYLOPE_INIT){}

Organism* Antylope::Reproduction(position_t posOfStaticParent)
{
	position_t tmpPos = this->FindPlaceForChild(posOfStaticParent);
	position_t nullPos = NULL_POSITION;
	if (tmpPos.x == nullPos.x && tmpPos.y == nullPos.y)
		return nullptr;
	else
		return new Antylope(this->world, tmpPos);
}

bool Antylope::IsSameGenere(Organism* defender)
{
	return dynamic_cast<Antylope*>(defender) != nullptr;
}

void Antylope::Action(World* world)
{
	bool allowToMove = false;
	while (!allowToMove)
	{
		position_t tmpPos = Organism::GetRandomisedPos(this->GetPosition());
		tmpPos = Organism::GetRandomisedPos(tmpPos);
		if (CheckIsInBounds(tmpPos, world->GetMeasurements()))
		{
			Organism* defender = this->CheckIfPositionIsOccupied(world, tmpPos);
			if (defender != nullptr && this != defender)
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
Collisions Antylope::Collision(Organism* attacker)
{
	srand(time(NULL));
	int escape = rand() % 2;
	string mess;
	position_t destPos = this->GetPosition();
	if (escape == 0)
	{
		mess = this->GetName();
		for (int i = 0; i < 8; i++)
		{
			destPos = ChoosePos(i, destPos);
			if (this->CheckIfPositionIsOccupied(world, destPos) != nullptr && CheckIsInBounds(destPos, world->GetMeasurements()))
			{
				this->SetPosition(destPos);
				break;
			}
		}
		mess += " ucieka";
		world->AddToString(mess);
		return MOVE;
	}
	else
	{
		if (attacker->GetStrength() < this->GetStrength())
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
}