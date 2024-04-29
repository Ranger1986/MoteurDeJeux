#ifndef MESH_HPP
#define MESH_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
using namespace std;
using namespace glm;

class Mesh{
    private :
        GLuint vertexbuffer;
        GLuint elementbuffer;
        GLuint vaoBuffer;
        GLuint uv;

    public :
        vector<unsigned short> indices;
        vector<vec3> indexed_vertices;
        vector<float> texCoords;
        Mesh();
        Mesh(std::vector<vec3>, vector<unsigned short>);
        void init();
        void draw();
        void deleteBuffer();
};

#endif