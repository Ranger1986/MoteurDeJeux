#include "Ennemy.hpp"
#include "Scene.hpp"
#include "Bullet.hpp"

Ennemy::Ennemy(){}
Ennemy::~Ennemy(){}
void Ennemy::applyPhysics(float deltaTime)
{
    behaviour->update();
    nextFire-=deltaTime;
    acceleration=parent->gravity;
    vitesse = (vitesse + acceleration * deltaTime) * 0.99f;
    vec3 deplacement = vitesse * deltaTime;
    // transform.translate(deplacement);
    Transform futureX = transform;
    futureX.translate(vec3(deplacement.x, 0, 0));
    Transform futureY = transform;
    futureY.translate(vec3(0, deplacement.y, 0));
    Transform futureXY = transform;
    futureXY.translate(vec3(deplacement.x, deplacement.y, 0));
    int iteration = 0;
    bool deniedX = false;
    bool deniedY = false;
    bool deniedXY = false;
    vector<HitboxRectangle *> hitboxs = parent->getObstaclesHitboxs();
    while (iteration < hitboxs.size() && !(deniedX && deniedY && deniedXY))
    {
        if (rectangleToRectangle(Node::getTransformedHitbox(hitbox, futureX), hitboxs[iteration]))
        {
            deniedX = true;
        }
        if (rectangleToRectangle(Node::getTransformedHitbox(hitbox, futureY), hitboxs[iteration]))
        {
            deniedY = true;
        }
        if (rectangleToRectangle(Node::getTransformedHitbox(hitbox, futureXY), hitboxs[iteration]))
        {
            deniedXY = true;
        }
        iteration++;
    }
    if (!deniedXY)
    {
        transform = futureXY;
        return;
    }
    if (deniedY && !deniedX)
    {
        transform = futureX;
        vitesse.y = 0;

        return;
    }
    if (deniedX && !deniedY)
    {
        transform = futureY;
        vitesse.x = 0;
        return;
    }
    vitesse.x = 0;
    vitesse.y = 0;    
}

void Ennemy::tir(){
    if (nextFire<=0)
    {
        Bullet * newBullet = new Bullet(*bullet);
        newBullet->direction=direction;
        newBullet->transform.t=transform.t;
        newBullet->mesh->init();
        newBullet->playerBullet=false;
        parent->bullets.push_back(newBullet);
        nextFire=fireDelay;
    }
}