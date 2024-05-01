#include "Scene.hpp"

Scene::Scene(int width, int height) : width(width), height(height)
{
    grid.resize(width);
    for (int i = 0; i < width; i++)
    {
        grid[i].resize(height);
        for (int j = 0; j < height; j++)
        {
            grid[i][j] = nullptr;
        }
    }
}

Scene::~Scene()
{
}

void Scene::init()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (grid[i][j])
            {
                grid[i][j]->mesh->init();
            }
        }
    }
    for (int i = 0; i < entities.size(); i++)
    {
        entities[i]->mesh->init();
    }
    
}

void Scene::draw(GLuint Mlocation, mat4 modelMatrix)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (grid[i][j])
            {
                mat4 newModelMatrix = modelMatrix * Transform(vec3(i,j,0)).matMod();
                glUniformMatrix4fv(Mlocation, 1, GL_FALSE, &newModelMatrix[0][0]);
                grid[i][j]->mesh->draw();
            }
        }
    }
    for (int i = 0; i < entities.size(); i++)
    {
        mat4 newModelMatrix = modelMatrix * entities[i]->transform.matMod();
        glUniformMatrix4fv(Mlocation, 1, GL_FALSE, &newModelMatrix[0][0]);
        entities[i]->mesh->draw();
    }
}
void Scene::applyPhysics(float deltaTime){
    for (int i = 0; i < entities.size(); i++)
    {
        entities[i]->applyPhysics(deltaTime);
    }
}
void Scene::deleteBuffer()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (grid[i][j])
            {
                grid[i][j]->mesh->deleteBuffer();
            }
        }
    }
    for (int i = 0; i < entities.size(); i++)
    {
        entities[i]->mesh->deleteBuffer();
    }
}