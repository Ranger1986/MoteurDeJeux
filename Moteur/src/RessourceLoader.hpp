#include "Player.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Quad.hpp"

#include <common/texture.hpp>


vector<Obstacle *> obstacles;
vector<Player *> players;
vector<Ennemy *> ennemies;
void init(){
    obstacles = vector<Obstacle *>();
    players = vector<Player *>();
    ennemies = vector<Ennemy *>();

    Quad square = Quad(vec3(0, 0, 0), 1);


    //Obstacles

    Obstacle *obstacle;

    obstacle = new Obstacle();
    GLuint dirt_texture = loadTexture2DFromFilePath("Texture/dirt_text.png");
    obstacle->HP=1;
    obstacle->mesh = square.generateMesh(dirt_texture);
    obstacle->hitbox = new HitboxRectangle(vec3(-0.5, -0.5, 0), vec3(0.5, 0.5, 0));
    obstacles.push_back(obstacle);
    
    obstacle = new Obstacle();
    GLuint stone_texture = loadTexture2DFromFilePath("Texture/stone_text.png");
    obstacle->HP=2;
    obstacle->mesh = square.generateMesh(stone_texture);
    obstacle->hitbox = new HitboxRectangle(vec3(-0.5, -0.5, 0), vec3(0.5, 0.5, 0));
    obstacles.push_back(obstacle);

    //Bullets

    GLuint yellow_texture = loadTexture2DFromFilePath("Texture/yellow.png");
    Bullet * bullet = new Bullet();
    bullet->TTL = 2;
    bullet->hitbox = new HitboxRectangle(vec3(-0.5, -0.5, 0), vec3(0.5, 0.5, 0));
    bullet->mesh = square.generateMesh(yellow_texture);
    bullet->transform.scale(0.25);

    //players

    Player * player = new Player();

    GLuint steve_texture = loadTexture2DFromFilePath("Texture/steve.jpg");

    player->hitbox = new HitboxRectangle(vec3(-0.5, -0.5, 0), vec3(0.5, 0.5, 0));
    player->mesh = square.generateMesh(steve_texture);
    player->transform.scale(0.5);
    player->fireDelay=1;
    player->direction=1;
    player->HP=3;
    players.push_back(player);
    player->bullet = bullet;
    players.push_back(player);

    //Ennemies
    GLuint red_texture = loadTexture2DFromFilePath("Texture/red.png");    
    
    Ennemy * ennemy = new Ennemy();
    ennemy->hitbox = new HitboxRectangle(vec3(-0.5, -0.5, 0), vec3(0.5, 0.5, 0));
    ennemy->mesh = square.generateMesh(red_texture);
    ennemy->transform.scale(0.75);
    ennemy->fireDelay=2;
    ennemy->direction=-1;
    ennemy->HP=3;

    RondeBehaviour * ronde = new RondeBehaviour();
    ronde->vision = new HitboxRectangle(vec3(-4, -0.5, 0), vec3(0, 0.5, 0));
    
    ennemy->behaviour=ronde;
    ennemy->behaviour->ennemy=ennemy;
    ennemy->bullet= bullet;
    
    ennemies.push_back(ennemy);
}

Obstacle * getObstacleByID(int id){
    return obstacles[id];
}
Player * getPlayerByID(int id){
    return players[id];
}
Ennemy * getEnnemyByID(int id){
    return ennemies[id];
}