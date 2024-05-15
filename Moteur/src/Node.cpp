#include "Node.hpp"

Node::Node(){
}
HitboxRectangle * Node::getTransformedHitbox(){
    return new HitboxRectangle(hitbox, transform);
}
HitboxRectangle * Node::getTransformedHitbox(HitboxRectangle *hitbox, Transform transform){
    HitboxRectangle *result = new HitboxRectangle(hitbox, transform);
    if (result->max.x<result->min.x)
    {
        float temp = result->max.x;
        result->max.x=result->min.x;
        result->min.x = temp;
    }
    if (result->max.y<result->min.y)
    {
        float temp = result->max.y;
        result->max.y=result->min.y;
        result->min.y = temp;
    }
    return result;
}