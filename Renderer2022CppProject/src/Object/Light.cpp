#include "Light.h"

void Light::addObject(Object* object)
{
	shadedObjectMap.insert(make_pair(object->uuid, object));
}

void Light::deleteObject(string uuid)
{
	auto iter = shadedObjectMap.find(uuid);
	if (iter != shadedObjectMap.end()) {
		shadedObjectMap.erase(iter);
	}
	else {
		cout << "WARNING::LIGHT::" << this->name << "::This object is not effected.";
	}
}

