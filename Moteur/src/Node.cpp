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

Transform Node::getWorldTransform(){
    return Transform(this->parent->transform.matMod()*this->transform.matMod());
}
HitboxRectangle * Node::getWorldHitbox(){
    Transform t = getWorldTransform();
    return new HitboxRectangle(hitbox, t);
}
Transform Node::getWorldTransform(Transform newTransform){
    return Transform(this->parent->transform.matMod()*newTransform.matMod());
}
HitboxRectangle * Node::getWorldHitbox(Transform newTransform){
    Transform t = getWorldTransform(newTransform);
    return new HitboxRectangle(hitbox, t);
}
vector<HitboxRectangle *> Node::getAllChildrenWorldHitbox(){
    vector<HitboxRectangle *> result = vector<HitboxRectangle*>();
    for (int i = 0; i < children.size(); i++)
    {
        vector<HitboxRectangle *> childResult = children[i]->getAllChildrenWorldHitbox();
        for (int j = 0; j < childResult.size(); j++)
        {
            result.push_back(childResult[j]);
        }
    }
    if (hitbox)
    {
        result.push_back(getWorldHitbox());
    }
    
    return result;
}
void Node::applyPhysics(float deltaTime){
    vec3 acceleration= vec3(0,-9.8,0);
    vitesse=(vitesse+acceleration*deltaTime)*0.99f;    
    vec3 deplacement = vitesse*deltaTime ;
    //transform.translate(deplacement);
    Transform futureX =transform;
    futureX.translate(vec3(deplacement.x,0,0));
    Transform futureY =transform;
    futureY.translate(vec3(0,deplacement.y,0));
    Transform futureXY =transform;
    futureXY.translate(vec3(deplacement.x,deplacement.y,0));
    int iteration = 1;
    bool deniedX = false;
    bool deniedY = false;
    bool deniedXY = false;
    vector<HitboxRectangle*> hitboxs = parent->getAllChildrenWorldHitbox();
    while (iteration < hitboxs.size() && !(deniedX&&deniedY&&deniedXY))
    {
        if(rectangleToRectangle(getWorldHitbox(futureX), hitboxs[iteration])){
            deniedX=true;
        }
        if(rectangleToRectangle(getWorldHitbox(futureY), hitboxs[iteration])){
            deniedY=true;
        }
        if(rectangleToRectangle(getWorldHitbox(futureXY), hitboxs[iteration])){
            deniedXY=true;
        }
        iteration++;
    }
    if (!deniedXY)
    {
        transform=futureXY;
        canJump=false;
        return;
    }
    if (deniedY && !deniedX)
    {
        transform=futureX;
        vitesse.y=0;
        if (deplacement.y <=0)
        {
            canJump=true;
        }
        
        return;
    }
    if (deniedX && !deniedY)
    {
        transform=futureY;
        vitesse.x=0;
        canJump=true;
        return;
    }
    
};