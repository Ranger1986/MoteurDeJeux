#ifndef ENNEMY_HPP
#define ENNEMY_HPP

#include "Node.hpp"

class Bullet;

class Ennemy : public Node
{
public:
    float fireDelay;
    float nextFire;
    int direction;

    int HP;

    Bullet * bullet;

    Ennemy(/* args */);
    ~Ennemy();

    void applyPhysics(float deltaTime);
    void tir();
};
#endif