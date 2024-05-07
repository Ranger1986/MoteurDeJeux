#ifndef SCENE_HPP
#define SCENE_HPP
#include <vector>

#include "Obstacle.hpp"
#include "Hitbox.hpp"
#include "Player.hpp"
#include "Ennemy.hpp"

class Scene
{
public:
    vector<Obstacle *> obstacles;
    vector<Player *> players;
    vector<Ennemy *> ennemies;
    vec3 gravity;
    GLuint Mlocation;

    Scene();
    Scene(GLuint Mlocation);
    Scene(GLuint Mlocation, vec3 gravity);
    //~Scene();

    vector<HitboxRectangle*> getObstaclesHitboxs();
    vector<HitboxRectangle*> getPlayersHitboxs();
    vector<HitboxRectangle*> getEnnemiesHitboxs();

    void applyPhysics(float deltaTime);
    void init();
    void draw();
    void deleteBuffers();
};
#endif