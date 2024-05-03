#include "Scene.hpp"

#include "Entity.hpp"
#include "Player.hpp"

Scene::Scene()
{
    listeEntites = vector<Entity*>();
}

Scene::~Scene()
{
}

void Scene::init(){
    for (int i = 0; i < listeEntites.size(); i++)
    {
        listeEntites[i]->mesh->init();
    }
}
void Scene::draw(GLuint Mlocation, mat4 modelMatrix){
    for (int i = 0; i < listeEntites.size(); i++)
    {
        mat4 newModelMatrix = listeEntites[i]->transform.matMod();
        glUniformMatrix4fv(Mlocation, 1, GL_FALSE, &newModelMatrix[0][0]);
        listeEntites[i]->mesh->draw();
    }
}
void Scene::deleteBuffer(){
    for (int i = 0; i < listeEntites.size(); i++)
    {
        listeEntites[i]->mesh->deleteBuffer();
    }
}

vector<HitboxRectangle*> Scene::getCollideableHitbox(){
    vector<HitboxRectangle*> result = vector<HitboxRectangle*>();
    for (int i = 0; i < listeEntites.size(); i++)
    {
        if (listeEntites[i]->collideable)
            result.push_back(listeEntites[i]->hitbox);
    }
    return result;
}
vector<HitboxRectangle*> Scene::getTriggerableHitbox(){
    vector<HitboxRectangle*> result = vector<HitboxRectangle*>();
    for (int i = 0; i < listeEntites.size(); i++)
    {
        if (listeEntites[i]->triggerable)
            result.push_back(listeEntites[i]->hitbox);
    }
    return result;
}