#ifndef NODE_HPP
#define NODE_HPP
#include <vector>
#include <functional>

#include "Transform.hpp"
#include "Mesh.hpp"
#include "Hitbox.hpp"

using namespace std;

class Scene;

class Node
{
public:
    Scene *parent;
    Mesh *mesh;
    Transform transform;
    HitboxRectangle *hitbox;
    vec3 acceleration;
    vec3 vitesse;

    Node(/* args */);
    //~Node();

    HitboxRectangle *getTransformedHitbox();
    static HitboxRectangle *getTransformedHitbox(HitboxRectangle *hitbox, Transform transform);
};
#endif
