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

/*
class Node
{
private:
    // liste des Nodes dependantes de la Node

public:
    // information de transformation de la Node
    Node *parent;
    vector<Node *> children;
    bool canJump;
    vec3 vitesse;
    Transform transform;
    Mesh *mesh;

    std::function<void(Node* node, float deltaTime)> applyPhysics;

    HitboxRectangle * hitbox;
    Node();
    void addChild(Node *child);
    void setParent(Node *child);
    vector<Node *> getChildren();

    void init();
    void draw(GLuint Mlocation, mat4 modelMatrix);
    void deleteBuffer();
    void destroyChild(int i);

    HitboxRectangle * getWorldHitbox();
    vector<HitboxRectangle *> getAllChildrenWorldHitbox();
    //void applyPhysics(float deltaTime);

    Transform getWorldTransform();
    HitboxRectangle * getWorldHitbox(Transform newTransform);
    Transform getWorldTransform(Transform newTransform);
};*/
#endif
