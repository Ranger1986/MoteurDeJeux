#ifndef PLAN_HPP
#define PLAN_HPP
#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.hpp>

#include <iostream>
#include <vector>
using namespace glm;
using namespace std;

class Plan {
   private:
    vec3 center;
    int resolution;
    float height;
    float width;

   public:
    Plan(vec3 center, int resolution,float height, float width);
    void generate(std::vector<glm::vec3>& indexed_vertices, std::vector<unsigned short>& indices,std::vector<float> &texCoords);
};
#endif