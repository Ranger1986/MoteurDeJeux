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
                std::cout << "|" << matrice[i][j];
            }
            std::cout << "|" << std::endl;
        }
    }

    static void print(vector<float> uv){
        for (int i = 0; i< uv.size() ; i+=2){
            std::cout << "(" << uv[i] << "," << uv[i+1] << ")" << std::endl;
        }
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