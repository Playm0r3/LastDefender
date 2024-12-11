#include "game_object.h"

GameObject::GameObject()
{
	AddComponent(new TransformComponent(0.f, 0.f));
}

GameObject::GameObject(float x, float y)
{
	AddComponent(new TransformComponent(x, y));
}

GameObject::~GameObject()
{
	std::vector<Component*>::iterator it = components.begin();
	for (; it != components.end(); ++it)
	{
		delete* it;
	}
	
	components.clear();
	std::cout << "[Destruction GameObject] " << this << std::endl;
}