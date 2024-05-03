#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "Hitbox.hpp"

using namespace std;
using namespace glm;

class Entity;
class Player;

class Scene
{
public:
    vector<Entity*> listeEntites;
    Player * player;

    Scene(/* args */);
    ~Scene();

    void init();
    void draw(GLuint Mlocation, mat4 modelMatrix);
    void deleteBuffer();

    vector<HitboxRectangle*> getCollideableHitbox();
    vector<HitboxRectangle*> getTriggerableHitbox();
};

#endif