#ifndef SCENE_HPP
#define SCENE_HPP
#include <vector>

#include "Transform.hpp"
#include "Mesh.hpp"
#include "Hitbox.hpp"
#include "Obstacle.hpp"
#include "Entity.hpp"

using namespace std;

class Entity;

class Scene
{
public:
    // attribut

    vector<vector<Obstacle*>> grid;
    vector<Entity*> entities;
    int width;
    int height;

    // constructeur & destructeur

    Scene(int width, int height);
    ~Scene();

    // fonctions

    void init();
    void draw(GLuint Mlocation, mat4 modelMatrix);
    void applyPhysics(float deltaTime);
    void deleteBuffer();
};
#endif
