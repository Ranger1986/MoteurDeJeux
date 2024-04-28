#ifndef QUAD_HPP
#define QUAD_HPP
#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.hpp>

#include <iostream>
#include <vector>
using namespace glm;

#include "Mesh.hpp"

class Quad
{
private:
    vec3 center;
    float length;
public:
    Quad(vec3 center, float length);
    Mesh* generateMesh();
    ~Quad();
};
#endif