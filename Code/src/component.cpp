#include <raylib.h>

#include "component.h"


TransformComponent::TransformComponent() : Component(), position(Vector2{0, 0})
{
}

TransformComponent::TransformComponent(float x, float y) : Component(), position(Vector2{ x, y })
{
}

BoxColliderComponent::BoxColliderComponent() : Component(), boxCollider(Rectangle{ 0, 0, 0, 0 })
{
}

BoxColliderComponent::BoxColliderComponent(Rectangle bCollider) : Component(), boxCollider(bCollider)
{
}

CircleColliderComponent::CircleColliderComponent() : Component(), radius(0)
{
}

CircleColliderComponent::CircleColliderComponent(float rad) : Component(), radius(rad)
{
}