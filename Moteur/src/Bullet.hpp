#ifndef BULLET_HPP
#define BULLET_HPP

#include "Node.hpp"

class Bullet : public Node
{
public:
    float TTL;
    Bullet(/* args */);
    ~Bullet();
    
    void applyPhysics(float deltaTime);
};


#endif
