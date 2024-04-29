#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>

#include "Mesh.hpp"
#include <common/objloader.hpp>

Mesh::Mesh(){
    indexed_vertices = vector<vec3>();
    indices = vector<unsigned short>();
    texCoords = vector<float>();
}

Mesh::Mesh(vector<glm::vec3> indexed_vertices_in, vector<unsigned short> indices_in){
    indexed_vertices = indexed_vertices_in;
    indices = indices_in;
}

void Mesh::init(){
    glGenVertexArrays(1, &vaoBuffer);
    glGenBuffers(1, &vertexbuffer);
    glGenBuffers(1, &elementbuffer);
    glGenBuffers(1,&uv);

    glBindVertexArray(vaoBuffer);

    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, indexed_vertices.size() * sizeof(glm::vec3), &indexed_vertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(
        0,                  // attribute
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), &indices[0] , GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, uv);
    glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(float), &texCoords[0], GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(1);	
    glVertexAttribPointer(
        1,        // attribute
        2,        // size
        GL_FLOAT, // type
        GL_FALSE, // normalized?
        0,        // stride
        (void *)0 // array buffer offset
    );

    glBindVertexArray(0);
}

void Mesh::draw(){
    glBindTexture(GL_TEXTURE_2D, text); 

    glBindVertexArray(vaoBuffer);
    glEnableVertexAttribArray(0);

    // Draw the triangles !
    glDrawElements(
        GL_TRIANGLES,      // mode
        indices.size(),    // count
        GL_UNSIGNED_SHORT,   // type
        (void*)0           // element array buffer offset
    );

    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

void Mesh::deleteBuffer(){
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &elementbuffer);
    glDeleteVertexArrays(1, &vaoBuffer);
}