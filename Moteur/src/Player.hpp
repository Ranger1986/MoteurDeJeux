#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.hpp>

#include <iostream>
#include <vector>

#include "Node.hpp"
#include "Bullet.hpp"

class Player : public Node
{
public:
    bool canJump;
    float fireDelay;
    float nextFire;
    Bullet * bullet;
    Player(/* args */);
    ~Player();
    void applyPhysics(float deltaTime);
    void jump();
    void tir();
};
#endif