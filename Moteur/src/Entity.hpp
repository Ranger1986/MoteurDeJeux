#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.hpp>

#include <iostream>
#include <vector>

#include "Node.hpp"
#include "Hitbox.hpp"

class Entity : public Node
{
private:
public:
    HitboxRectangle * hitbox;
    Entity(/* args */);
    HitboxRectangle * getWorldHitbox();
    ~Entity();
};
#endif