#ifndef PLAYER
#define PLAYER

#include "entity.h"

class Player : public Entity {
public:
	int money = 100;
	int healht;
};

#endif