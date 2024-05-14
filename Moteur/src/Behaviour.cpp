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
    type = BehaviourType::Tourelle;
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
    type = BehaviourType::Ronde;
}

RondeBehaviour::~RondeBehaviour()
{
}

void RondeBehaviour::update(float deltaTime){    
    bool playerFound=false;
    vector<HitboxRectangle *> hitboxs = ennemy->parent->getPlayersHitboxs();
    int iteration=0;
    bool detected=false;
    for (int i = 0; i < hitboxs.size(); i++)
    {
        if (rectangleToRectangle(Node::getTransformedHitbox(vision, ennemy->transform), hitboxs[iteration]))
        {
            detected = true;
        }
    }
    if (detected)
    {
        if (ennemy->nextFire<0)
        {
            ennemy->tir();
        }
        ennemy->vitesse.x=0;
        return;
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