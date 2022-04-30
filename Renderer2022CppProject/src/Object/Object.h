#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../Shader/Shader.h"
#include "../Compoments/Compoment.h"
#include <string>
#include <vector>
#include <map>
#include"ObjectManager.h"
using namespace std;
extern enum ObjectType
{
	GAMEOBJECT,
	CAMERA,
	LIGHT
};
class Component;
static class ComponentManager;
class Object
{
	map<int, Component*> compomentList;
public:
	string name;
	string uuid;
	unsigned int type = GAMEOBJECT;
	//ComponentManager* compomentManager;
	glm::vec3 position;
	glm::vec3 rotation;
	void addCompoment(Component* com);
	void deleteCompoment(Component* com);
	void translateObject(glm::vec3 delta);
	void setPosition(glm::vec3 pos);
	void rotateObject(glm::vec3 rot);
	void setRotation(glm::vec3 rot);
	Object(string name, vector<Component*>* initCompomentList, glm::vec3 pos);
	Object(string name, glm::vec3 pos);
	~Object();
};

class Camera :public Object {
public:
	Camera(vector<Component*>* initCompomentList, glm::vec3 pos);
	glm::mat4 getPerspective();
	Camera(glm::vec3);
	glm::mat4 getCamaraView();
};