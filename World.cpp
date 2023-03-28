#include "World.h"
#include "Human.h"
#include "Antylope.h"
#include "Belladonna.h"
#include "Fox.h"
#include "Grass.h"
#include "Guarana.h"
#include "Human.h"
#include "Milt.h"
#include "Sheep.h"
#include "SosHogweed.h"
#include "Turtle.h"
#include "Wolf.h"


position_t World::RandomisePosition()
{
	srand(time(NULL));
	bool allowToPass = false;
	position_t tmpPos;
	while (!allowToPass)
	{
		tmpPos.x = rand() % (this->GetMeasurements().x -1);
		tmpPos.y = rand() % (this->GetMeasurements().y -1);
		if (tmpPos.x != 0 && tmpPos.y != 0)
			allowToPass = true;
	}
	return tmpPos;
}

//file:
//first line x y of board
//rest of them organisms
// ID of orgniasm || x || y || strength
void World::AddSaveToFile()
{
	ofstream saveOfGame;
	saveOfGame.open("save.txt");
	saveOfGame << this->GetMeasurements().x << " " <<  this->GetMeasurements().y << '\n';
	for (int i = 0; i < this->GetOrganismsSize(); i++)
	{
		if (this->organisms[i]->IsAlive())
		{
			saveOfGame << this->organisms[i]->GetID() << " " << this->organisms[i]->GetPosition().x << " " << this->organisms[i]->GetPosition().y << " "  <<  this->organisms[i]->GetStrength() << '\n';
		}
	}
	cout << "Zapisano stan gry do pliku save.txt" << endl;
	saveOfGame.close();
	this->~World();
	exit(0);
}

void World::ExecuteTurn()
{
	for (int i = 0; i <  this->organisms.size(); i++)
	{
		system("cls");
		this->PrintWorld();
		if(this->organisms[i]->IsAlive())
			this->organisms[i]->Action(this);
	}
	cout << this->WriteActions();
	this->ClearActions();
	this->ClearOrganisms();
}

void World::ClearOrganisms()
{
	int i = this->GetOrganismsSize();
	while (i)
	{
		for (int j = 0; j < this->GetOrganismsSize(); j++)
			if (!this->organisms[j]->IsAlive())
			{
				this->organisms.erase(this->organisms.begin() + j);
				break;
			}
		i--;
	}
}

void World::CreateEcosystem(position_t posOfOrg, int iterator)
{
	if (iterator >= (START_AM_OF_ORGANISMS/2))
		iterator = iterator%(START_AM_OF_ORGANISMS/2);
	switch (iterator)//creating 2 organisms of every species
	{
	case WOLF:
		new Wolf(this, posOfOrg);
		break;
	case SHEEP:
		new Sheep(this, posOfOrg);
		break;
	case FOX:
		new Fox(this, posOfOrg);
		break;
	case TURTLE:
		new Turtle(this, posOfOrg);
		break;
	case ANTYLOPE:
		new Antylope(this, posOfOrg);
		break;
	case GRASS:
		new Grass(this, posOfOrg);
		break;
	case MILT:
		new Milt(this, posOfOrg);
		break;
	case GUARANA:
		new Guarana(this, posOfOrg);
		break;
	case BELLADONNA:
		new Belladonna(this, posOfOrg);
		break;
	case SOSHOGWEED:
		new SosHogweed(this, posOfOrg);
		break;
	}
}

void World::CreateEcosystem(int organismID, position_t posOfOrg, int strength)
{
	switch (organismID)//creating 2 organisms of every species
	{
	case WOLF:
		new Wolf(this, posOfOrg, strength);
		break;
	case SHEEP:
		new Sheep(this, posOfOrg, strength);
		break;
	case FOX:
		new Fox(this, posOfOrg, strength);
		break;
	case TURTLE:
		new Turtle(this, posOfOrg, strength);
		break;
	case ANTYLOPE:
		new Antylope(this, posOfOrg, strength);
		break;
	case GRASS:
		new Grass(this, posOfOrg);
		break;
	case MILT:
		new Milt(this, posOfOrg);
		break;
	case GUARANA:
		new Guarana(this, posOfOrg);
		break;
	case BELLADONNA:
		new Belladonna(this, posOfOrg);
		break;
	case SOSHOGWEED:
		new SosHogweed(this, posOfOrg);
		break;
	case HUMAN:
		this->humanPtr = new Human(this, posOfOrg, strength);
	}
}

bool World::GameOver()
{
	if (this->humanPtr->IsAlive())
		return false;
	else
		return true;
}
World::World()
{
	this->SetMeasurements(measurements);
	bool flag = true;
	int i = START_AM_OF_ORGANISMS -1; 
	vector<position_t> usedPos;
	position_t tmpPos;
	while (i != -1)
	{
		flag = true;
		tmpPos = this->RandomisePosition();
		for (int j = 0; j < usedPos.size(); j++)
			if (tmpPos.x == usedPos[j].x && tmpPos.y == usedPos[j].y)
				flag = false;
		if (flag)
		{
			usedPos.push_back(tmpPos);
			this->CreateEcosystem(tmpPos, i);
			i--;
		}
	}
	this->humanPtr = new Human(this, HUMANS_START_POS);
}

World::World(string aciton)
{
	position_t measurements, tmpPos;
	ifstream file("save.txt");
	int val;
	int flag = -2;
	int idOfAnAnimal, strenght;
	while (file >> val)
	{
		if (flag == -2)
			measurements.x = val;
		else if (flag == -1)
		{
			measurements.y = val;
			this->SetMeasurements(measurements);
		}
		else if (flag % 4 == 0)
			idOfAnAnimal = val;
		else if (flag % 4 == 1)
			tmpPos.x = val;
		else if (flag % 4 == 2)
			tmpPos.y = val;
		else if (flag % 4 == 3)
		{
			strenght = val;
			this->CreateEcosystem(idOfAnAnimal, tmpPos, strenght);
		}
		flag++;
	}
	file.close();
}

string World::WriteActions() const
{
	return this->actionsAtTurn;
}

World::World(position_t measurements)
{
	this->SetMeasurements(measurements);
	bool flag = true;
	int i = START_AM_OF_ORGANISMS - 1;
	vector<position_t> usedPos;
	position_t tmpPos;
	while (i != -1)
	{
		flag = true;
		tmpPos = this->RandomisePosition();
		for (int j = 0; j < usedPos.size(); j++)
			if (tmpPos.x == usedPos[j].x && tmpPos.y == usedPos[j].y)
				flag = false;
		if (flag)
		{
			usedPos.push_back(tmpPos);
			this->CreateEcosystem(tmpPos, i);
			i--;
		}
	}
	this->humanPtr = new Human(this, HUMANS_START_POS);
}

void World::SetMeasurements(position_t measurements)
{
	this->measurements = measurements;
}

position_t World::GetMeasurements() const
{
	return this->measurements;
}

void World::ClearActions()
{
	this->actionsAtTurn = "";
}

void World::AddToString(string mess)
{
	this->actionsAtTurn += mess + '\n';
}

void World::AddOrganismToWorld(Organism* newOrg)
{
	if (newOrg == nullptr)
		return;
	int subArrStart = -1;
	int subArrEnd = -1;
	int subArrWithLowerInit = -1;
	if (!this->organisms.empty())
	{
		for (int i = 0; i < this->GetOrganismsSize(); i++)
		{
			if (this->organisms[i]->GetInitiative() == newOrg->GetInitiative())
			{
				subArrStart = i;
				break;
			}
			else if (this->organisms[i]->GetInitiative() < newOrg->GetInitiative())
			{
				subArrWithLowerInit = i;
				break;
			}
		}
		if (subArrStart != -1)
		{
			for (int i = subArrStart; i < this->GetOrganismsSize(); i++)
			{
				if (this->organisms[i]->GetInitiative() != newOrg->GetInitiative())
				{
					subArrEnd = i;
					break;
				}
			}
			if(subArrEnd != -1)
				this->organisms.insert(this->organisms.begin() + subArrEnd, newOrg);
			else
				this->organisms.insert(this->organisms.begin() + subArrStart, newOrg);
		}
		else
		{
			if (subArrWithLowerInit != -1)
			{
				this->organisms.insert(this->organisms.begin() + subArrWithLowerInit, newOrg);
			}
			else
				this->organisms.push_back(newOrg);
		}
	}
	else
		this->organisms.push_back(newOrg);
}

void World::SetPlayersMove(char actionKey)
{
	this->humanPtr->SetMove(actionKey);
}

void World::HandleAction(char actionKey)
{
	if (actionKey == 's')
		this->AddSaveToFile();
	else
		this->SetPlayersMove(actionKey);
}

void World::PrintWorld() const
{
	for (int j = -1; j < this->GetMeasurements().x; j++)
		cout << "_";
	cout << endl;

	for (int i = 0; i < this->GetMeasurements().y; i++)
	{
		cout << "|";
		for (int j = 0; j < this->GetMeasurements().x; j++)
		{
			for (int k = 0; k < GetOrganismsSize(); k++)
			{
				position_t tmpPos = organisms[k]->GetPosition();

				if (tmpPos.x == j && tmpPos.y == i && organisms[k]->IsAlive())
				{
					cout << organisms[k]->GetSign();
					j++;
				}
			}
			if(j < this->GetMeasurements().x)
				cout << " ";
		}
		cout << "|" << endl;
	}
	for (int j = -1; j < GetMeasurements().x; j++)
		cout << "-";
	cout << endl;
}

void World::TestFnc() const
{
	for (int i = 0; i < this->GetOrganismsSize(); i++)
	{
		cout << this->organisms[i]->GetName() << " x:" << this->organisms[i]->GetPosition().x << " y:" << this->organisms[i]->GetPosition().y << '\n';
	}
}
int World::GetOrganismsSize() const
{
	return this->organisms.size();
}
Organism* World::GetOrganismsOnIndex(int index) const
{
	return this->organisms[index];
}
World::~World()
{
	for (int i = 0; i < this->organisms.size(); i++)
	{
		this->organisms[i]->~Organism();
	}
	this->humanPtr = nullptr;
	cout << "\nKoniec gry!!!\n";
}