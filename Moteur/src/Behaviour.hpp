#ifndef BEHAVIOUR_HPP
#define BEHAVIOUR_HPP

#include "Ennemy.hpp"

class Ennemy;

class Behaviour
{
public:
    Ennemy * ennemy;

    Behaviour(/* args */);
    ~Behaviour();

    virtual void update()= 0;
};

class TourelleBehaviour : public Behaviour
{
public:
    TourelleBehaviour(/* args */);
    ~TourelleBehaviour();

    void update() override;
};
class RondeBehaviour : public Behaviour
{
public:
    HitboxRectangle * vision;
    
    RondeBehaviour(/* args */);
    ~RondeBehaviour();

    void update() override;
};


#endif