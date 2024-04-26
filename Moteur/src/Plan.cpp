#include "Plan.hpp"

Plan::Plan(vec3 center, int resolution, float height, float width) {
    this->center = center;
    this->resolution=resolution;
    this->height = height;
    this->width = width;
}
void Plan::generate(std::vector<glm::vec3>& indexed_vertices, std::vector<unsigned short>& indices,std::vector<float> &texCoords) {
    float half_width = width / 4;
    float half_height =  height / 4;
    for (int i = 0; i < resolution; i++) {
        for (int j = 0; j < resolution; j++) {
            indexed_vertices.push_back(center +
                                       vec3(height/resolution * i - half_height,
                                            width/resolution * j - half_width,
                                            0));
            texCoords.push_back((float)i / (float)resolution);
            texCoords.push_back((float)j / (float)resolution);
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

            texCoords.push_back((float)(i + 1) / (float)resolution);
            texCoords.push_back((float)j / (float)resolution);

            texCoords.push_back((float)(i + 1) / (float)resolution);
            texCoords.push_back((float)(j + 1) / (float)resolution);

            texCoords.push_back((float)(i) / (float)resolution);
            texCoords.push_back((float)(j + 1) / (float)resolution);

            texCoords.push_back((float)(i) / (float)resolution);
            texCoords.push_back((float)j / (float)resolution);

            texCoords.push_back((float)(i + 1) / (float)resolution);
            texCoords.push_back((float)(j) / (float)resolution);

            texCoords.push_back((float)(i) / (float)resolution);
            texCoords.push_back((float)(j + 1) / (float)resolution);

        }
    }
}