#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "declarations.h"
#include "Organism.h"

using namespace std;

class Organism;

class World
{
private:
	string actionsAtTurn;
	position_t measurements = {DEFAULT_X, DEFAULT_Y};
	vector<Organism*> organisms;
	Organism* humanPtr;
	void SetMeasurements(position_t measurements);
	position_t RandomisePosition();
	void CreateEcosystem(position_t posOfOrg, int iterator);
	void CreateEcosystem(int organismID, position_t posOfOrg, int strength);
	string WriteActions() const;
	void ClearActions();
	void ClearOrganisms();
	void AddSaveToFile();
	void SetPlayersMove(char actionKey);
public:
	void HandleAction(char actionKey);
	bool GameOver();
	void AddToString(string mess);
	void AddOrganismToWorld(Organism* newOrg);
	int GetOrganismsSize() const;
	Organism* GetOrganismsOnIndex(int index) const;
	void PrintWorld() const;
	void ExecuteTurn();
	void TestFnc() const;
	position_t GetMeasurements() const;
	World();
	World(string action);
	World(position_t mesaurements);
	~World();
};

