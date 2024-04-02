#include "Plan.h"

Plan::Plan(vec3 center, float cote, int resolution) {
    this->center = center;
    this->cote = cote;
    this->resolution = resolution;
    generateMesh();
}
void Plan::setCote(float cote){
    this->cote=cote;
}
void Plan::setResolution(int resolution){
    this->resolution=resolution;
}
void Plan::setMesh(Mesh m){
    this->m=m;
}
float Plan::getCote(){
    return this->cote;
}
int Plan::getResolution(){
    return this->resolution;
}
Mesh Plan::getMesh(){
    return this->m;
}
void Plan::generateMesh() {
    vector<glm::vec3> indexed_vertices;
    vector<unsigned short> indices;
    float half_width = cote / 2;
    float half_length =  cote / 2;
    for (int i = 0; i < resolution; i++) {
        for (int j = 0; j < resolution; j++) {
            indexed_vertices.push_back(center +
                                       vec3(cote/resolution * j - half_width,
                                            cote/resolution * i - half_length,
                                            0.0));
        }
    }
    for (int i = 0; i < resolution - 1; i++) {
        for (int j = 0; j < resolution - 1; j++) {
            indices.push_back(i * resolution + j);
            indices.push_back((i + 1) * resolution + j);
            indices.push_back((i + 1) * resolution + j + 1);

            indices.push_back(i * resolution + j);
            indices.push_back(i * resolution + j + 1);
            indices.push_back((i + 1) * resolution + j + 1);
        }
    }
    m.setVertices(indexed_vertices);
    m.setIndices(indices);
}
void Plan::draw(){

}