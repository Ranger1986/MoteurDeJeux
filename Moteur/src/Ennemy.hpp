#ifndef ENNEMY_HPP
#define ENNEMY_HPP

#include "Node.hpp"

class Ennemy : public Node
{
public:
    Ennemy(/* args */);
    ~Ennemy();

    void applyPhysics(float deltaTime);
    void Tir();
};
#endif