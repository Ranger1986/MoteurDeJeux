#include "Obstacle.hpp"

ObstacleImmovable::ObstacleImmovable(/* args */)
{
    collideable=true;
}

ObstacleImmovable::~ObstacleImmovable()
{
}
void ObstacleImmovable::applyPhysics(float deltaTime){};