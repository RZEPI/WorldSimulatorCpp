#pragma once

typedef struct position_t {
	int x;
	int y;
}position_t;

#define DIRECTIONS 8

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UP_RIGHT 4
#define UP_LEFT 5 
#define DOWN_RIGHT 6 
#define DOWN_LEFT 7

#define WOLF 0
#define SHEEP 1
#define	FOX 2
#define	TURTLE 3
#define	ANTYLOPE 4
#define GRASS 5
#define MILT 6
#define GUARANA 7
#define BELLADONNA 8
#define SOSHOGWEED 9
#define HUMAN 10


enum Collisions
{
	MOVE,
	HUMAN_ALZUERES_SHIELD,
	TURTLE_COUNTER,
	GUARANA_BOOST,
	DEATH
};

#define STRENGTH_TO_KILL_TURTLE 5
#define TRIES_OF_MILT_REPLICATION 3
#define CHANCE_FOR_PLANT_TO_REPLICATE 33// devide 1 by this num and multiply by 100%
#define AGE_TO_REPLICATE 5
#define GUARANA_BOOST_VAL 3
#define PLANT_INIT 0

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32

#define DEFAULT_Y 20
#define DEFAULT_X 20

#define START_AM_OF_ORGANISMS 20
#define AMOUNT_OF_CHARACKERS_OF_SAME_SPECIES 2

#define HUMANS_START_POS {0, 0}
#define NULL_POSITION {21312, 21323}

#define ANTYLOPE_STRENGTH 4
#define ANTYLOPE_INIT 4
#define ANTYLOPE_NAME "Antylopa"
#define ANTYLOPE_SIGN 'a'

#define BELLADONNA_STRENGTH 99
#define BELLADONNA_NAME "Wilcza jagoda"
#define BELLADONNA_SIGN '~'

#define FOX_STRENGTH 3
#define FOX_INIT 7
#define FOX_NAME "Lis"
#define FOX_SIGN 'l'

#define GRASS_STRENGTH 0
#define GRASS_NAME "Trawa"
#define GRASS_SIGN '#'

#define GUARANA_STRENGTH 0
#define GUARANA_NAME "Guarana"
#define GUARANA_SIGN '*'

#define HUMAN_STRENGTH 5
#define HUMAN_INIT 4
#define HUMAN_NAME "Czlowiek"
#define HUMAN_SIGN '@'
#define DURATION_OF_ABILITY 6
#define COOLDOWN_OF_ABILITY 5

#define MILT_STRENGTH 0
#define MILT_NAME "Mlecz"
#define MILT_SIGN '&'

#define SHEEP_STRENGTH 4
#define SHEEP_INIT 4
#define SHEEP_NAME "Owca"
#define SHEEP_SIGN 'o'

#define SOSHOGWEED_STRENGTH 10
#define SOSHOGWEED_NAME "Barsz Sosnowskiego"
#define SOSHOGWEED_SIGN '0'

#define TURTLE_STRENGTH 2
#define TURTLE_INIT 1
#define TURTLE_NAME "Zlow"
#define TURTLE_SIGN 'z'

#define WOLF_STRENGTH 9
#define WOLF_INIT 5
#define WOLF_NAME "Wilk"
#define WOLF_SIGN 'w'

