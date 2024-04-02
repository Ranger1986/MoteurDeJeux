#ifndef MESH_H
#define MESH_H
#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.hpp>

#include <iostream>
#include <vector>
using namespace glm;
using namespace std;

class Mesh {
   private:
    vector<glm::vec3> indexed_vertices;
    vector<unsigned short> indices;

   public:
    Mesh();
    /**
     * @brief Set the Vertices object
     * 
     * @param indexed_vertices 
     */
    void setVertices(vector<glm::vec3> indexed_vertices);
    /**
     * @brief Set the Indices object
     * 
     * @param indices 
     */
    void setIndices(vector<unsigned short> indices);
    /**
     * @brief Get the Vertices object
     * 
     * @return vector<glm::vec3> 
     */
    vector<glm::vec3> getVertices();
    /**
     * @brief Get the Indices object
     * 
     * @return vector<unsigned short> 
     */
    vector<unsigned short> getIndices();
};
#endif