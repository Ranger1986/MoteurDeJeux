#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertices_position_modelspace;
layout(location = 1) in vec2 uv;
//TODO create uniform transformations matrices Model View Projection
// Values that stay constant for the whole mesh.
uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

out vec2 frag_uv;

void main(){
        frag_uv=uv;
        // TODO : Output position of the vertex, in clip space : MVP * position
        gl_Position = P*V*M * vec4(vertices_position_modelspace,1);

}

