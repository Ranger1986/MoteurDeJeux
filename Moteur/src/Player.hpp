#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.hpp>

#include <iostream>
#include <vector>

#include "Node.hpp"
#include "Player.hpp"

class Player : public Node
{
private:
public:
    Player(/* args */);
    ~Player();
};
#endif