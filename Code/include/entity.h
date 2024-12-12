#ifndef ENTITY
#define ENTITY

#include "game_object.h"
#include "td_struct.h"

class Entity : public GameObject {

public:
	Health life;
	int damage;
	int money;

	Entity();
	Entity(float x = 0, float y = 0, int maxHealth = 100, int currentHealth = 100, int damage = 5, int money = 10);
	~Entity() = default;

	void DrawCollider();
};

#endif