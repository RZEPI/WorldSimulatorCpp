#include <iostream>
#include <vector>
#include <conio.h>
#include "World.h"

using namespace std;

int main()
{
	World* world;
	position_t measOfWorld;
	cout << "Autor zadania: Pawel Rzepecki\nNumer indeksu:191703\nPodaj wymiary i wcisnij Enter lub wprowadz \'l\' zeby wczytac stan gry z pliku: ";
	string meas;
	getline(cin, meas);
	if (meas[0] == 'l')
		world = new World(meas);
	else if (!meas.empty())//if user inserted measurements of world
	{
		int split = meas.find(' ');
		measOfWorld.x = stoi(meas.substr(0, split));
		measOfWorld.y = stoi(meas.substr(split + 1));
		world = new World(measOfWorld);
	}
	else//if not
		world = new World();
	char action = -1;
	while (!(world->GameOver()))//game loop 
	{
		cout << "Ruch czlowieka" << endl;
		while(action < 0)
		{ 
			action = _getch();
		}
		world->HandleAction(action);
		world->ExecuteTurn();
		//system("PAUSE");
		action = -1;
	}
	world->~World();
	return 0;
}