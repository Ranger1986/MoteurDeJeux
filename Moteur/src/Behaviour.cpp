#include "Behaviour.hpp"
#include "Scene.hpp"
Behaviour::Behaviour(/* args */)
{
}

Behaviour::~Behaviour()
{
}

TourelleBehaviour::TourelleBehaviour(/* args */)
{
}

TourelleBehaviour::~TourelleBehaviour()
{
}

void TourelleBehaviour::update(float deltaTime){
    if (ennemy->nextFire<0)
    {
        ennemy->tir();
    }
}
Behaviour * TourelleBehaviour::copy(){
    return new TourelleBehaviour(* this);
}
RondeBehaviour::RondeBehaviour(/* args */)
{
}

RondeBehaviour::~RondeBehaviour()
{
}

void RondeBehaviour::update(float deltaTime){    
    bool playerFound=false;
    vector<HitboxRectangle *> hitboxs = ennemy->parent->getPlayersHitboxs();
    bool detected=false;
    int playerPos;
    int iteration = 0;
    while (!detected && iteration < hitboxs.size())
    {
        if (rectangleToRectangle(Node::getTransformedHitbox(vision, ennemy->transform), hitboxs[iteration]))
        {
            detected = true;
            playerPos = (hitboxs[iteration]->min.x+hitboxs[iteration]->max.x)/2;
        }
        iteration++;
    }
    
    if (detected)
    {
        int ennemyPos=(Node::getTransformedHitbox(ennemy->hitbox, ennemy->transform)->min.x+Node::getTransformedHitbox(ennemy->hitbox, ennemy->transform)->max.x)/2;
        hitboxs = ennemy->parent->getObstaclesHitboxs();
        iteration =0;
        while(detected && iteration < hitboxs.size())
        {
            if (rectangleToRectangle(Node::getTransformedHitbox(vision, ennemy->transform), hitboxs[iteration]))
            {
                int obstaclePos= (hitboxs[iteration]->min.x+hitboxs[iteration]->max.x)/2;
                if ((playerPos<obstaclePos&&obstaclePos<ennemyPos)||
                    (ennemyPos<obstaclePos&&obstaclePos<playerPos))
                {
                    detected = false;
                }
                std::cout << "obstacle et ennemy" << std::endl;
                std::cout << playerPos << std::endl;
                std::cout << obstaclePos << std::endl;
                std::cout << ennemyPos << std::endl;
            }
            iteration++;
        }
        if (detected){
            if (ennemy->nextFire<0)
            {
                ennemy->tir();
            }
            ennemy->vitesse.x=0;
            return;
        }
    }

    Transform futureXY = ennemy->transform;
    futureXY.translate(vec3(ennemy->direction, -1, 0));

    Transform futureX = ennemy->transform;
    futureX.translate(vec3(ennemy->direction * deltaTime, 0, 0));

    hitboxs = ennemy->parent->getObstaclesHitboxs();
    iteration=0;
    bool canWalk =false;
    bool hitWall =false;
    while (iteration < hitboxs.size() && !hitWall)
    {
        if (!canWalk && rectangleToRectangle(Node::getTransformedHitbox(ennemy->hitbox, futureXY), hitboxs[iteration]))
        {
            canWalk = true;
        }
        if (rectangleToRectangle(Node::getTransformedHitbox(ennemy->hitbox, futureX), hitboxs[iteration]))
        {
            hitWall = true;
        }
        iteration++;
    }
    if (!canWalk || hitWall)
    {
        ennemy->direction*=-1;
        Transform inverse = Transform();
        inverse.scale(vec3(-1,0,0));
        vision = Node::getTransformedHitbox(vision, inverse);
    }
    ennemy->vitesse.x=ennemy->direction;  
}

Behaviour * RondeBehaviour::copy(){
    return new RondeBehaviour(* this);
}