#include "Node.hpp"
#include <iostream>

Node::Node()
{
    transform = Transform();
}
void Node::addChild(Node *child)
{
    children.push_back(child);
    child->setParent(this);
}
void Node::setParent(Node *parent)
{
    this->parent = parent;
}
vector<Node *> Node::getChildren()
{
    return children;
}
void Node::init()
{
    if (mesh != nullptr)
    {
        mesh->init();
    }
    for (int i = 0; i < children.size(); i++)
    {
        children[i]->init();
    }
}
void Node::draw(GLuint Mlocation, mat4 modelMatrix)
{
    mat4 newModelMatrix = modelMatrix * transform.matMod();
    if (mesh != nullptr)
    {
        glUniformMatrix4fv(Mlocation, 1, GL_FALSE, &newModelMatrix[0][0]);
        mesh->draw();
    }
    for (int i = 0; i < children.size(); i++)
    {
        children[i]->draw(Mlocation, newModelMatrix);
    }
    
}
void Node::deleteBuffer()
{
    if (mesh != nullptr)
    {
        mesh->deleteBuffer();
    }
    for (int i = 0; i < children.size(); i++)
    {
        children[i]->deleteBuffer();
    }
}
void Node::destroyChild(int index){
    children.erase(children.begin() + index);
}