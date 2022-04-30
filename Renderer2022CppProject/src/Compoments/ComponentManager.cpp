#include "ComponentManager.h"

void ComponentManager::registerCompoment(Component* com) {
	compomentGlobalList.insert(std::make_pair(compomentGlobalList.size(), com));
}

void ComponentManager::deleteCompoment(Component* com) {
	for (auto iter = compomentGlobalList.begin(); iter != compomentGlobalList.end(); iter++) {
		if (com == iter->second) {
			compomentGlobalList.erase(iter);
			return;
		}
	}
}

void ComponentManager::compomentUpdate() {
	std::vector<Component*> globalQue = std::vector<Component*>(0);
	for (auto& i : compomentGlobalList) {
		globalQue.push_back(i.second);
	}
	sort(globalQue.begin(), globalQue.end(), cmp);
	for (auto& i : globalQue) {
		if (!i) continue;
		i->Update();
	}
}

void ComponentManager::compomentFixedUpdate() {
	std::vector<Component*> globalQue;
	globalQue.resize(compomentGlobalList.size());
	for (auto& i : compomentGlobalList) {
		globalQue.push_back(i.second);
	}
	sort(globalQue.begin(), globalQue.end(), cmp);
	for (auto& i : globalQue) {
		i->FixedUpdate();
	}
}

/*
Component* ComponentManager::componentConstructor(std::string name, std::vector<publicProperty> propertyList)
{
	return nullptr;
}
*/