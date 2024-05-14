#ifndef BEHAVIOUR_HPP
#define BEHAVIOUR_HPP

#include "Ennemy.hpp"

enum BehaviourType { Tourelle, Ronde};

class Ennemy;

class Behaviour
{
public:
    BehaviourType type;
    Ennemy * ennemy;

    Behaviour(/* args */);
    ~Behaviour();

    virtual void update(float deltaTime)= 0;
    virtual Behaviour * copy()=0;
};

class TourelleBehaviour : public Behaviour
{
public:
    TourelleBehaviour(/* args */);
    ~TourelleBehaviour();

    void update(float deltaTime) override;
    Behaviour * copy() override;
};
class RondeBehaviour : public Behaviour
{
public:
    HitboxRectangle * vision;
    
    RondeBehaviour(/* args */);
    ~RondeBehaviour();

    void update(float deltaTime) override;
    Behaviour * copy() override;
};


#endif