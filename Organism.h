#pragma once
#include <iostream>
#include "World.h"
#include "declarations.h"

class World;

class Organism
{
protected:
	World* world;
	int strength;
	int initiative;
	int age = 0;
	bool alive = true;
	bool CheckIsInBounds(position_t tmpPos, position_t worldMeasurements);
	const char* nameOfClass;
	char signForClass = ' ';
	char actionKey;
	position_t position;
	position_t ChoosePos(int num, position_t tmpPos);
	position_t GetRandomisedPos(position_t tmpPos);
	virtual position_t FindPlaceForChild(position_t posOfStaticParent) = 0;
	Organism* CheckIfPositionIsOccupied(World* world, position_t pos);
	virtual Organism* Reproduction(position_t posOfStaticParent) = 0;
	Organism(World* world, position_t pos, const char* nameOfClass, const char signForClass, int strength, int initiative);
	void SetInitiative(int initiative);
	void SetNameOfClass(const char* nameOfClass);
	void SetSignForClass(const char signForClass);
	void SetStrength(int value);
	void HandleCollision(Collisions typeOfAction, position_t destPos);
	void Die();
public:
	int GetID() const;
	void SetAgeToZero();
	void IsInDeadRange();
	void SetMove(char actionKey);
	virtual void Action(World* world) = 0;
	void SetPosition(position_t newPos);
	void GiveBoost(const int value);
	bool IsAlive() const;
	char GetSign() const;
	const char* GetName() const;
	int GetAge() const;
	position_t GetPosition() const;
	int GetInitiative() const;
	int GetStrength() const;
	virtual Collisions Collision(Organism* attacker) = 0;
	virtual ~Organism();
};

