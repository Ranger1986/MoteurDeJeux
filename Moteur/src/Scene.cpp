#include "Scene.hpp"

Scene::Scene(){
    gravity= vec3(0,-9.8,0);
}
Scene::Scene(GLuint Mlocation){
    this->Mlocation=Mlocation;
    this->gravity = vec3(0,-9.8,0);
}
Scene::Scene(GLuint Mlocation, vec3 gravity){
    this->Mlocation=Mlocation;
    this->gravity = gravity;
}
vector<HitboxRectangle*> Scene::getObstaclesHitboxs(){
    vector<HitboxRectangle*> result = vector<HitboxRectangle*>();
    for (int i = 0; i < obstacles.size(); i++)
    {
        result.push_back(obstacles[i]->getTransformedHitbox());
    }
    return result;
}
vector<HitboxRectangle*> Scene::getPlayersHitboxs(){
    vector<HitboxRectangle*> result = vector<HitboxRectangle*>();
    for (int i = 0; i < players.size(); i++)
    {
        result.push_back(players[i]->getTransformedHitbox());
    }
    return result;
}
vector<HitboxRectangle*> Scene::getEnnemiesHitboxs(){
    vector<HitboxRectangle*> result = vector<HitboxRectangle*>();
    for (int i = 0; i < ennemies.size(); i++)
    {
        result.push_back(ennemies[i]->getTransformedHitbox());
    }
    return result;
}
void Scene::applyPhysics(float deltaTime){
    for (int i = 0; i < obstacles.size(); i++)
    {
        obstacles[i]->applyPhysics(deltaTime);
        if (obstacles[i]->HP <= 0 )
        {
            obstacles.erase(obstacles.begin()+i);
        }
        
    }
    for (int i = 0; i < ennemies.size(); i++)
    {
        ennemies[i]->applyPhysics(deltaTime);
    }
    for (int i = 0; i < players.size(); i++)
    {
        players[i]->applyPhysics(deltaTime);
    }
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i]->applyPhysics(deltaTime);
        if (bullets[i]->TTL <=0)
        {
            bullets.erase(bullets.begin()+i);
        }
    }
}
void Scene::init(){
    for (int i = 0; i < obstacles.size(); i++)
    {
        obstacles[i]->mesh->init();
    }
    for (int i = 0; i < ennemies.size(); i++)
    {
        ennemies[i]->mesh->init();
    }
    for (int i = 0; i < players.size(); i++)
    {
        players[i]->mesh->init();
    }
}
void Scene::draw(){
    for (int i = 0; i < obstacles.size(); i++)
    {
        mat4 modelMatrix = obstacles[i]->transform.matMod();
        glUniformMatrix4fv(Mlocation, 1, GL_FALSE, &modelMatrix[0][0]);
        obstacles[i]->mesh->draw();
    }
    for (int i = 0; i < ennemies.size(); i++)
    {
        mat4 modelMatrix = ennemies[i]->transform.matMod();
        glUniformMatrix4fv(Mlocation, 1, GL_FALSE, &modelMatrix[0][0]);
        ennemies[i]->mesh->draw();
    }
    for (int i = 0; i < players.size(); i++)
    {
        mat4 modelMatrix = players[i]->transform.matMod();
        glUniformMatrix4fv(Mlocation, 1, GL_FALSE, &modelMatrix[0][0]);
        players[i]->mesh->draw();
    }
    for (int i = 0; i < bullets.size(); i++)
    {
        mat4 modelMatrix = bullets[i]->transform.matMod();
        glUniformMatrix4fv(Mlocation, 1, GL_FALSE, &modelMatrix[0][0]);
        bullets[i]->mesh->draw();
    }
}
void Scene::deleteBuffers(){
    for (int i = 0; i < obstacles.size(); i++)
    {
        obstacles[i]->mesh->deleteBuffer();
    }
    for (int i = 0; i < ennemies.size(); i++)
    {
        ennemies[i]->mesh->deleteBuffer();
    }
    for (int i = 0; i < players.size(); i++)
    {
        players[i]->mesh->deleteBuffer();
    }
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i]->mesh->deleteBuffer();
    }
}