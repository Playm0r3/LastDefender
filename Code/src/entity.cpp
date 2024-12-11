#include <raylib.h>

#include "entity.h"
#include "game_object.h"
#include "component.h"

Entity::Entity() : GameObject(0.f, 0.f), life(Health{ 100, 100 }), damage(5)
{
	AddComponent(new BoxColliderComponent(Rectangle{0, 0, 10, 10}));
}

Entity::Entity(float x, float y, int maxHealth, int currentHealth, int damage) : GameObject(x, y),
life(Health{ maxHealth, currentHealth }), damage(damage)
{
	AddComponent(new BoxColliderComponent(Rectangle{ x, y, 50, 50 }));
}

void Entity::DrawCollider()
{
	DrawRectangleRec(GetComponent<BoxColliderComponent>()->boxCollider, ORANGE);
}