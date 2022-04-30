#include "Compoment.h"
#include"ComponentManager.h"
static class ComponentManager;
Component::Component() {
	ComponentManager::registerCompoment(this);
}

Component::~Component() {
	ComponentManager::deleteCompoment(this);
}

