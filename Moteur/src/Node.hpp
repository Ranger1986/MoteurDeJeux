#ifndef NODE_HPP
#define NODE_HPP
#include <vector>

#include "Transform.hpp"
#include "Mesh.hpp"

using namespace std;
/**
 * @brief Representation d'une Node 3D
 *
 */
class Node
{
private:
    // liste des Nodes dependantes de la Node
    Node *parent;
    vector<Node *> children;

public:
    // information de transformation de la Node
    Transform transform;
    Mesh *mesh;
    Node();
    void addChild(Node *child);
    void setParent(Node *child);
    vector<Node *> getChildren();

    void init();
    void draw(GLuint Mlocation, mat4 modelMatrix);
    void deleteBuffer();
    void destroyChild(int i);

    Transform getWorldTransform();
};
#endif
