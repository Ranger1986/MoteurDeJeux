#include "Entity.hpp"

Entity::Entity(/* args */): Node()
{
}
HitboxRectangle * Entity::getWorldHitbox(){
    Transform t = getWorldTransform();
    return new HitboxRectangle(hitbox, t);
}

Entity::~Entity()
{
}
