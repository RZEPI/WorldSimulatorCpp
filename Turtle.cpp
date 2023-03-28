#include "Turtle.h"

Turtle::Turtle(World* world, position_t pos) : Animal(world, pos, TURTLE_NAME, TURTLE_SIGN, TURTLE_STRENGTH, TURTLE_INIT){}

Turtle::Turtle(World* world, position_t pos, int strength) : Animal(world, pos, TURTLE_NAME, TURTLE_SIGN, strength, TURTLE_INIT) {}

Organism* Turtle::Reproduction(position_t posOfStaticParent)
{
	position_t tmpPos = this->FindPlaceForChild(posOfStaticParent);
	position_t nullPos = NULL_POSITION;
	if (tmpPos.x == nullPos.x && tmpPos.y == nullPos.y)
		return nullptr;
	else
		return new Turtle(this->world, tmpPos);
}

bool Turtle::IsSameGenere(Organism* defender)
{
	return dynamic_cast<Turtle*>(defender) != nullptr;
}

void Turtle::Action(World* world)
{
	srand(time(NULL));
	int moved = rand() % 4;
	if (moved == 3)
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
					if (IsSameGenere(defender))
					{
						if (this->GetAge() > 0 && defender->GetAge() > AGE_TO_REPLICATE)
						{
							world->AddOrganismToWorld(Reproduction(defender->GetPosition()));
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
	}
	this->age++;
}

Collisions Turtle::Collision(Organism* attacker)
{
	if (attacker->GetStrength() > STRENGTH_TO_KILL_TURTLE)
	{
		string mess = this->GetName();
		mess += " umiera";
		this->world->AddToString(mess);
		this->Die();
		return MOVE;
	}
	else
		return TURTLE_COUNTER;
}