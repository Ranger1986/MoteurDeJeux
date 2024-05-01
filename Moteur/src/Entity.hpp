#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.hpp>

#include <iostream>
#include <vector>

#include "Scene.hpp"
#include "Mesh.hpp"
#include "Transform.hpp"

class Entity 
{
private:
public:
    vec3 vitesse;
    Transform transform;
    Scene * parent;
    Mesh * mesh;
    HitboxRectangle * hitbox;

    Entity(/* args */);
    void applyPhysics(float deltaTime);
    ~Entity();
};
#endif