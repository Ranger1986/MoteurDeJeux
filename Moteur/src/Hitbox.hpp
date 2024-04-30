#ifndef HITBOX_HPP
#define HITBOX_HPP
#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.hpp>

#include <iostream>
#include <vector>
using namespace glm;

#include "Transform.hpp"

class Hitbox
{
private:
    /* data */
public:
    Hitbox(/* args */);
    ~Hitbox();
};

class HitboxRectangle : public Hitbox
{
private:
    /* data */
public:
    vec3 min;
    vec3 max;
    HitboxRectangle(vec3 min, vec3 max);
    HitboxRectangle(HitboxRectangle * hitbox, Transform t);
    ~HitboxRectangle();
};

bool rectangleToRectangle(HitboxRectangle * rec1, HitboxRectangle * rec2);
#endif