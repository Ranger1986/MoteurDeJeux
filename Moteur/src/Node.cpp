#include "Node.hpp"
#include <iostream>

Node::Node()
{
    transform = Transform();
}
void Node::addChild(Node *child){
    children.push_back(child);
    child->setParent(this);
}
void Node::setParent(Node *parent){
    this->parent=parent;
}
vector<Node *> Node::getChildren(){
    return children;
}
void Node::init(){
    if (mesh!=nullptr)
    {
        mesh->init();
    }
    
}
void Node::draw(GLuint Mlocation){
    if (mesh!=nullptr)
    {
        mat4 modelMatrix = transform.matMod();
        glUniformMatrix4fv(Mlocation, 1, GL_FALSE, &modelMatrix[0][0]);
        mesh->draw();
    }
    
}
void Node::deleteBuffer(){
    if (mesh!=nullptr)
    {
        mesh->deleteBuffer();
    }
    
}
