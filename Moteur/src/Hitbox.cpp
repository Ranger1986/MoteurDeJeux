#include "Hitbox.hpp"

Hitbox::Hitbox()
{
}

Hitbox::~Hitbox()
{
}

HitboxRectangle::HitboxRectangle(HitboxRectangle * hitbox, Transform t)
{
    this->min = t.applyToPoint(hitbox->min);
    this->max = t.applyToPoint(hitbox->max);
}

HitboxRectangle::HitboxRectangle(vec3 min, vec3 max)
{
    this->min = min;
    this->max = max;
}

HitboxRectangle::~HitboxRectangle()
{
}

bool rectangleToRectangle(HitboxRectangle * rec1, HitboxRectangle * rec2)
{
    bool overX = ((rec2->min.x <= rec1->max.x)&&(rec1->min.x <= rec2->max.x));
    bool overY = ((rec2->min.y <= rec1->max.y)&&(rec1->min.y <= rec2->max.y));
    return overX && overY;
}