#ifndef COMPONENT
#define COMPONENT

#include <raylib.h>

class Component {

};

class TransformComponent : public Component {

public:

	Vector2 position;

	TransformComponent();
	TransformComponent(float x, float y);
	~TransformComponent() = default;

};

class BoxColliderComponent : public Component {

public:

	Rectangle boxCollider;

	BoxColliderComponent();
	BoxColliderComponent(Rectangle boxCollider);
	~BoxColliderComponent() = default;
};

class CircleColliderComponent : public Component {

public:

	float radius;

	CircleColliderComponent();
	CircleColliderComponent(float radius);
	~CircleColliderComponent() = default;
};

#endif