#pragma once
#include"Object.h"
#include"UUid.h"
#include"../Compoments/Compoment.h"
#include<map>
using namespace std;
class Object;
class Component;
class Camera;
/*
	For ObjectManager, the objectNow is a special value which
	give user a special table to get the object user-wanted.
*/
static class ObjectManager
{
public:
	static unsigned int width, height;
	static map<string, Object*> objectManagerMap;
	static Camera* mainCamera;
	static Object* objectNow;
	static void registerObject(Object* object);
	static void changeCamera(Camera* anoCam);
	static void deleteObject(string uuid);
	static void displayObject();
	static Object* getObject(string uuid);
	static void makeNewObject(string type, string name, glm::vec3 pos = glm::vec3(0,0,0), vector<Component*>* initComponentList=nullptr);
};
//TODO Object ½âñî£¡£¡£¡
