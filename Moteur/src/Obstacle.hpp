#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "Entity.hpp"

class ObstacleImmovable : public Entity
{
private:
    /* data */
public:
    ObstacleImmovable(/* args */);
    ~ObstacleImmovable();
    void applyPhysics(float deltaTime) override;
};

#endif