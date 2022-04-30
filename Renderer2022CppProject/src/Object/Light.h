#pragma once
#include "Object.h"
using namespace std;
class Light :
    public Object
{
    //Notice: The renderer only support max 4 lights in one scene.
    map<string,Object*> shadedObjectMap;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
public:
    //virtual void addLight();
    Light(string name, glm::vec3 pos) :Object(name, pos) {};
    void addObject(Object* object);
    void deleteObject(string uuid);
};

class PointLight :public Light {
private:
    float constant;
    float linear;
    float quadratic;
public:
    PointLight(string name, glm::vec3 pos) :Light(name, pos) {};
    //void addLight() override;
};

class DirLight :public Light {
    
public:
    DirLight(string name, glm::vec3 pos) :Light(name, pos) {};
    //void addLight() override;
};

class SpotLight :public Light {
    float constant;
    float linear;
    float quadratic;
public:
    SpotLight(string name, glm::vec3 pos) :Light(name, pos) {};
    //void addLight() override;
};