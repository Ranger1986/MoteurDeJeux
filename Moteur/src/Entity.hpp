#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "Hitbox.hpp"
#include "Mesh.hpp"

using namespace std;
using namespace glm;

class Scene;

class Entity
{
public:
    Scene * parent;
    Transform transform;
    Mesh * mesh;
    HitboxRectangle * hitbox;
    vec3 vitesse;
    vec3 acceleration;
    bool collideable;
    bool triggerable;

    Entity(/* args */);
    ~Entity();

    virtual void applyPhysics(float deltaTime) = 0;
};
#endif