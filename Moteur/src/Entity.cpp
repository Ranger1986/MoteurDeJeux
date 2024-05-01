#include "Entity.hpp"

Entity::Entity(/* args */)
{
}

void Entity::applyPhysics(float deltaTime)
{
    vec3 posInit = transform.getTranslation() + vec3(0.25,0.25,0.25);
    vec3 acceleration = vec3(0, -9.8, 0);
    vitesse = (vitesse + acceleration * deltaTime) * 0.99f;

    transform.translate(vitesse * deltaTime);

    vec3 posFin = transform.getTranslation() + vec3(0.25,0.25,0.25);
    bool positionInvalide = posFin.x < 0 || posFin.y < 0 || posFin.x > parent->width || posFin.y > parent->height;
    if (positionInvalide ||
        parent->grid[(int)posFin.x][(int)posFin.y])
    {
        vec3 vitesseFinale = vitesse;
        if (!positionInvalide && parent->grid[(int)posInit.x][(int)posFin.y])
        {
            vitesse.y *= 0.1;
            vitesseFinale.x = 0;
        }
        if (!positionInvalide && parent->grid[(int)posFin.x][(int)posInit.y])
        {
            vitesse.x *= 0.1;
            vitesseFinale.y = 0;
        }
        transform.translate(-vitesseFinale * deltaTime);
    }
};

Entity::~Entity()
{
}
