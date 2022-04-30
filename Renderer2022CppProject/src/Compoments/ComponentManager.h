#pragma once
#include<map>
#include"Compoment.h"
#include "MeshRenderer.h"
class Component;
static class ComponentManager {
	static std::map<int, Component*> compomentGlobalList;
	static std::map<string, Component* (*)(std::vector<publicProperty>)> componentInstructor;
public:
	static void registerCompoment(Component* com);
	static void deleteCompoment(Component* com);
	static void compomentUpdate();
	static void compomentFixedUpdate();
	static Component* componentConstructor(std::string name,std::vector<publicProperty> propertyList);
};
