#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#include <glm/glm.hpp>

using namespace glm;
class Transform
{
public:
    // rotation + skew + scale
    mat3 m;
    // translation
    vec3 t;
    Transform();
    Transform(mat3 matrice);
    Transform(vec3 translation);
    Transform(mat3 m, vec3 t);
    Transform(mat4 matrice);
    void rotx(float angle);
    void roty(float angle);
    void rotz(float angle);
    void scale(float ratio);
    void scale(vec3 ratio);
    void translate(vec3 translation);
    vec3 getTranslation();
    vec3 applyToPoint(vec3 p);
    vec3 applyToVector(vec3 v);
    mat4 matMod();
};
#endif