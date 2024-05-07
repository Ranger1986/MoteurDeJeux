#include "Player.hpp"
#include "Scene.hpp"

Player::Player(/* args */) : Node()
{
    canJump=true;
}
Player::~Player()
{
}
void Player::applyPhysics(float deltaTime)
{
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
        canJump = false;
        return;
    }
    if (deniedY && !deniedX)
    {
        transform = futureX;
        vitesse.y = 0;
        canJump = true;

        return;
    }
    if (deniedX && !deniedY)
    {
        transform = futureY;
        vitesse.x = 0;
        canJump = true;
        return;
    }
    vitesse.x = 0;
    vitesse.y = 0;
    canJump = true;
}
void Player::jump()
{
    if (canJump)
    {
        vitesse.y = 7.5;
        canJump = false;
    }
}