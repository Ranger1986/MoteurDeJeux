#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "Node.hpp"

class Obstacle : public Node
{
public:
    int HP;
    
    Obstacle(/* args */);
    ~Obstacle();

    void applyPhysics(float deltaTime);
};
#endif