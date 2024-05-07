// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include "Transform.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

using namespace glm;
using namespace std;

class helper
{
public:
    static void print(mat4 matrice){
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                std::cout << "|" << matrice[j][i];
            }
            std::cout << "|" << std::endl;
        }
    }
    static void print(Transform transform){
        print(transform.matMod());
    }

    static void print(Player * player){
        std::cout << "Print de joueur :" << std::endl;
        std::cout << "Acceleration : (" << player->acceleration.x << "," << player->acceleration.y << ","<< player->acceleration.z <<")" <<std::endl;
        std::cout << "Vitesse : (" << player->vitesse.x << "," << player->vitesse.y << ","<< player->vitesse.z <<")" <<std::endl;
        std::cout << "canJump : " << player->canJump << std::endl;
    }
    static void print(vec3 vec){
        std::cout << "(";
        for (int i = 0; i < 3; i++){
            std::cout << vec[i] << ",";
        }
        std::cout << ")" << std::endl;
    }
    static void print(vector<vector<int>> vecteur){
        
        for (int i = 0; i < vecteur.size(); i++)
        {
            for (int j = 0; j < vecteur[i].size(); j++)
            {
                std::cout << "|" << vecteur[i][j];
            }
            std::cout << "|" << std::endl;
        }
    }
};