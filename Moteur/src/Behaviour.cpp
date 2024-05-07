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

void TourelleBehaviour::update(){
    if (ennemy->nextFire<0)
    {
        ennemy->tir();
    }
}

RondeBehaviour::RondeBehaviour(/* args */)
{
}

RondeBehaviour::~RondeBehaviour()
{
}

void RondeBehaviour::update(){    
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
    hitboxs = ennemy->parent->getObstaclesHitboxs();
    iteration=0;
    bool denied =false;
    while (iteration < hitboxs.size() && !denied)
    {
        if (rectangleToRectangle(Node::getTransformedHitbox(ennemy->hitbox, futureXY), hitboxs[iteration]))
        {
            denied = true;
        }
        iteration++;
    }
    if (!denied)
    {
        ennemy->direction*=-1;
        Transform inverse = Transform();
        inverse.scale(vec3(-1,0,0));
        vision = Node::getTransformedHitbox(vision, inverse);
        std::cout << "Min Max" << std::endl;
        std::cout << vision->min.x << "," << vision->min.y << std::endl;
        std::cout << vision->max.x << "," << vision->max.y << std::endl;
    }
    ennemy->vitesse.x=ennemy->direction;
    
}