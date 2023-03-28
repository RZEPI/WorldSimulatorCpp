#include "Human.h"

Human::Human(World* world, position_t pos) : Animal(world, HUMANS_START_POS, HUMAN_NAME, HUMAN_SIGN, HUMAN_STRENGTH, HUMAN_INIT) {}

Human::Human(World* world, position_t pos, int strength) : Animal(world, pos, HUMAN_NAME, HUMAN_SIGN, strength, HUMAN_INIT) {}

bool Human::GetEffect() const
{
	return this->effectOfAbility;
}

char Human::GetMove() const
{
	return this->actionKey;
}

bool Human::IsSameGenere(Organism* defender) { return false; }
Organism* Human::Reproduction(position_t pos) { return nullptr; }

void Human::Action(World* world)
{
	position_t tmpPos = this->GetPosition();
	switch (this->GetMove())
	{
	case KEY_UP:
		tmpPos = Organism::ChoosePos(UP, tmpPos);
		break;
	case KEY_RIGHT:
		tmpPos = Organism::ChoosePos(RIGHT, tmpPos);
		break;
	case KEY_DOWN:
		tmpPos = Organism::ChoosePos(DOWN, tmpPos);
		break;
	case KEY_LEFT:
		tmpPos = Organism::ChoosePos(LEFT, tmpPos);
		break;
	case KEY_SPACE:
		this->Ability();
		break;
	} 
	this->SetMove(NULL);
	if (Organism::CheckIsInBounds(tmpPos, world->GetMeasurements()))
	{
		Organism* defender = Organism::CheckIfPositionIsOccupied(world, tmpPos);

		if (defender == nullptr)
			this->SetPosition(tmpPos);
		else if (this != defender)
		{
			string mess = this->GetName();
			mess += " atakuje ";
			mess += defender->GetName();
			world->AddToString(mess);
			this->HandleCollision(defender->Collision(this), tmpPos);
		}
	}
	if (this->GetEffect())
	{
		if (this->durationOfAbility != 1)
			this->durationOfAbility--;
		else
		{
			this->world->AddToString("Tarcza Alzura wylaczona");
			this->effectOfAbility = false;
		}
	}
	else
		if(this->cooldownOfAbility != 0)
			this->cooldownOfAbility--;

	this->age++;
}

void Human::Ability()
{
	if (!(this->GetEffect()))
	{
		if (this->cooldownOfAbility == 0)
		{
			this->world->AddToString("Czlowiek uzywa umiejetnosci Tarcza Alzura");
			this->durationOfAbility = DURATION_OF_ABILITY;
			this->effectOfAbility = true;
			this->cooldownOfAbility = COOLDOWN_OF_ABILITY;
		}
	}
}

Collisions Human::Collision(Organism* attacker)
{
	if(this->GetEffect())
	{
		return HUMAN_ALZUERES_SHIELD;
	}
	else
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
}