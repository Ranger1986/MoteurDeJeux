#ifndef BULLET_HPP
#define BULLET_HPP

#include "Node.hpp"
#include "Obstacle.hpp"
#include "Ennemy.hpp"
#include "Player.hpp"

class Bullet : public Node
{
public:
    int direction; 
    float TTL;
    bool playerBullet;


    Bullet(/* args */);
    ~Bullet();
    
    void applyPhysics(float deltaTime);
};


#endif
