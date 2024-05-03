#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.hpp>

#include <iostream>
#include <vector>

#include "Entity.hpp"

class Player : public Entity
{
public:
    bool canJump;
    Player(/* args */);
    ~Player();
    void applyPhysics(float deltaTime);
};
#endif