#ifndef GAME_OBJECT
#define GAME_OBJECT

#include <raylib.h>
#include <vector>
#include <iostream>

#include "component.h"

class GameObject {

public:
	std::vector<Component*> components;

	GameObject();
	GameObject(float x, float y);
	~GameObject();

	template <typename T>
	T* GetComponent() // vérifier si le component retourné n'est pas égale à nullptr;
	{
		std::vector<Component*>::iterator it = components.begin();
		for (; it != components.end(); ++it)
		{
			T* component = dynamic_cast<T*>(*it);
			if (component != nullptr)
				return component;
		}
		return nullptr;
	}

	template <typename T>
	bool HasComponent()
	{
		std::vector<Component*>::iterator it = components.begin();
		for (; it != components.end(); ++it)
		{
			T* component = dynamic_cast<T*>(*it);
			if (component != nullptr)
				return true;
		}
		return false;
	}

	template <typename T>
	void AddComponent(T* newComponent)
	{
		if (HasComponent<T>()) {
			std::cout << "[ERROR in AddComponent] Component Already exist !" << std::endl;
			return;
		}
		components.push_back(newComponent);
	}
};

#endif