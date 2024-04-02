#ifndef PLAN_H
#define PLAN_H
#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.hpp>

#include <iostream>
#include <vector>

#include "Mesh.h"

using namespace glm;
using namespace std;


class Plan {
   private:
    vec3 center;
    float cote;
    int resolution;
    Mesh m;

   public:
    Plan(vec3 center, float cote, int resolution);
    /**
     * @brief Set the Cote object
     * 
     * @param cote 
     */
    void setCote(float cote);
    /**
     * @brief Set the Resolution object
     * 
     * @param resolution 
     */
    void setResolution(int resolution);
    /**
     * @brief Set the Mesh object
     * 
     * @param mesh 
     */
    void setMesh(Mesh mesh);
    /**
     * @brief Get the Cote object
     * 
     * @return float 
     */
    float getCote();
    /**
     * @brief Get the Resolution object
     * 
     * @return int 
     */
    int getResolution();
    /**
     * @brief Get the Mesh object
     * 
     * @return Mesh 
     */
    Mesh getMesh();
    void generateMesh();
    void draw();
};
#endif