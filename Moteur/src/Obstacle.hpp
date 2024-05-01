#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "Mesh.hpp"
#include "Hitbox.hpp"

class Scene;

class Obstacle
{
public:
    // attribut

    Scene * parent;
    Mesh * mesh;
    HitboxRectangle * hitbox;
    bool destructible;
    int pv;

    // constructeur & destructeur

    Obstacle(/* args */);
    ~Obstacle();

    // fonctions

    
};
#endif