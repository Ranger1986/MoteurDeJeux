#version 330 core

// Ouput data
out vec4 FragColor;
out vec3 color;

in vec2 frag_uv;

uniform sampler2D text;

void main(){
    FragColor=texture(text,frag_uv);
    //color =vec3(0.2, 0.2,0.4);

}
