#pragma once
#include"Object.h"
#include"UUid.h"
#include<map>
using namespace std;
class Object;
class Camera;
static class ObjectManager
{
public:
	static map<string, Object*> objectManagerMap;
	static Camera* mainCamera;
	static void registerObject(Object* object);
	static void changeCamera(Camera* anoCam);
	static void deleteObject(string uuid);
	static void displayObject();
	static Object* getObject(string uuid);
};

