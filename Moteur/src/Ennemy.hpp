#ifndef ENNEMY_HPP
#define ENNEMY_HPP

#include "Node.hpp"

#include "Behaviour.hpp"

class Bullet;

class Behaviour;

class Ennemy : public Node
{
public:
    float fireDelay;
    float nextFire;
    int direction;

    int HP;

    Bullet * bullet;

    Behaviour * behaviour;

    Ennemy(/* args */);
    ~Ennemy();

    void applyPhysics(float deltaTime);
    void tir();
};
#endif