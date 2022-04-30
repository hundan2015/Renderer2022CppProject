#include "Compoment.h"
Component::Component() {
	ComponentManager::registerCompoment(this);
}

Component::~Component() {
	ComponentManager::deleteCompoment(this);
}

