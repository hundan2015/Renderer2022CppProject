#include "ObjectManager.h"

Camera* ObjectManager::mainCamera;
map<string, Object*> ObjectManager::objectManagerMap;

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
