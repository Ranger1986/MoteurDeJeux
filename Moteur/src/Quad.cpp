#include "Quad.hpp"

Quad::Quad(vec3 center, float length)
{
    this->center = center;
    this->length = length;
}

Mesh *Quad::generateMesh()
{
    Mesh *result = new Mesh();
    float halfLength = length / 2;
    result->indexed_vertices.push_back(center -
                                       vec3(halfLength, halfLength, 0));
    result->indexed_vertices.push_back(center -
                                       vec3(halfLength, -halfLength, 0));
    result->indexed_vertices.push_back(center -
                                       vec3(-halfLength, halfLength, 0));
    result->indexed_vertices.push_back(center -
                                       vec3(-halfLength, -halfLength, 0));
    result->indices.push_back(0);
    result->indices.push_back(1);
    result->indices.push_back(2);
    result->indices.push_back(1);
    result->indices.push_back(2);
    result->indices.push_back(3);

    return result;
};

Quad::~Quad()
{
}
