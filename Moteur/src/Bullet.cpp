#include "Bullet.hpp"
#include "Scene.hpp"
#include "helper.cpp"

Bullet::Bullet(/* args */)
{
}
Bullet::~Bullet()
{
}
void Bullet::applyPhysics(float deltaTime){
    TTL-=deltaTime;
    transform.translate(vec3(direction,0,0) * (3 * deltaTime) );
    vector<HitboxRectangle *> hitboxs;
    if (playerBullet)
    {
        hitboxs = parent->getObstaclesHitboxs();
        for (int i = 0; i < hitboxs.size(); i++)
        {
            if (rectangleToRectangle(Node::getTransformedHitbox(hitbox, transform), hitboxs[i])){
                parent->obstacles[i]->HP--;
                TTL=-1;
                return;
            }
        }
        hitboxs = parent->getEnnemiesHitboxs();
        for (int i = 0; i < hitboxs.size(); i++)
        {
            if (rectangleToRectangle(Node::getTransformedHitbox(hitbox, transform), hitboxs[i])){
                parent->ennemies[i]->HP--;
                TTL=-1;
                return;
            }
        }
    }
    else
    {
        hitboxs = parent->getPlayersHitboxs();
        for (int i = 0; i < hitboxs.size(); i++)
        {
            if (rectangleToRectangle(Node::getTransformedHitbox(hitbox, transform), hitboxs[i])){
                parent->players[i]->HP--;
                TTL=-1;
                return;
            }
        }
    }
    
};