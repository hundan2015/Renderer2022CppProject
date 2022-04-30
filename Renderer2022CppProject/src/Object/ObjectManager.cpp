#include "ObjectManager.h"
#include"Light.h"
Camera* ObjectManager::mainCamera;
map<string, Object*> ObjectManager::objectManagerMap;
unsigned int ObjectManager::width, ObjectManager::height;
void ObjectManager::registerObject(Object* object) {
	UUIDUtils uuidGen;
	string uuid = uuidGen.GenerateUUID();
	object->uuid = uuid;
	objectManagerMap.insert(make_pair(uuid, object));
}

void ObjectManager::changeCamera(Camera* anoCam) {
	mainCamera = anoCam;
}

void ObjectManager::deleteObject(string uuid) {
	auto iter = objectManagerMap.find(uuid);
	if (iter != objectManagerMap.end()) {
		objectManagerMap.erase(iter);
	}
	else {
		cout << "WARN::ObjectManager::No this object." << endl;
	}
}

void ObjectManager::displayObject() {
	for (auto i : objectManagerMap) {
		cout << i.second->name << " " << i.first << endl;
	}
}

Object* ObjectManager::getObject(string uuid)
{
	auto iter = objectManagerMap.find(uuid);
	if (iter != objectManagerMap.end()) {
		return iter->second;
	}
	else
	{
		return nullptr;
	}
}

void ObjectManager::makeNewObject(string type, string name, glm::vec3 pos, vector<Component*>* initComponentList)
{
	Object* object = nullptr;
	UUIDUtils uuidGen;
	if (type == "GameObject") {
		object = new Object(name, pos);
	}
	else if (type == "PointLight") {
		object = new PointLight(name, pos);
	}
	else if (type == "DirLight") {
		object = new DirLight(name, pos);
	}
	else if (type == "SpotLight") {
		object = new SpotLight(name, pos);
	}
	else if (type == "Camera") {
		object = new Camera(pos);
	}
	if (object) {
		objectManagerMap.insert(make_pair(uuidGen.GenerateUUID(), object));
	}
	else
	{
		cout << "WARNING::ObjectManager::Failed to create Object.";
	}
}


