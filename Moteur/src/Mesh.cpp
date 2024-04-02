#include "Mesh.h"

Mesh::Mesh() {
}

void Mesh::setVertices(vector<glm::vec3> indexed_vertices){
    this->indexed_vertices=indexed_vertices;
}
void Mesh::setIndices(vector<unsigned short> indices){
    this->indices=indices;
}
vector<glm::vec3> Mesh::getVertices(){
    return this->indexed_vertices;
}
vector<unsigned short> Mesh::getIndices(){
    return this->indices;
}