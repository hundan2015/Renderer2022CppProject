#include "Object.h"
#include<glm/gtc/quaternion.hpp>

static class ObjectManager;
//unsigned int ObjectManager::width, ObjectManager::height;
//ʲôʱ���дʲôʱ�򲻸�д�أ�
void Object::addCompoment(Component* com) {
	compomentList.insert(make_pair(compomentList.size(), com));
	com->masterObject = this;
}

void Object::deleteCompoment(Component* com) {
	for (auto iter = compomentList.begin(); iter != compomentList.end(); iter++) {
		if (com == iter->second) {
			compomentList.erase(iter);
			//compomentManager->deleteCompoment(com);
			return;
		}
	}
	cout << "WARNING::Object::No this compoment." << endl;
}

void Object::translateObject(glm::vec3 delta) {
	position += delta;
}

void Object::setPosition(glm::vec3 pos) {
	position = pos;
}

void Object::rotateObject(glm::vec3 rot) {
	rotation += rot;
}

void Object::setRotation(glm::vec3 rot) {
	rotation = rot;
}

Object::Object(string name, vector<Component*>* initCompomentList, glm::vec3 pos) {
	this->name = name;
	setPosition(pos);
	for (auto i : *(initCompomentList)) {
		addCompoment(i);
	}
	delete initCompomentList;
	ObjectManager::registerObject(this);
}

Object::Object(string name, glm::vec3 pos) {
	setPosition(pos);
	//this->compomentManager = comM;
	this->name = name;
}

Object::~Object() {
	if (compomentList.empty()) {
		return;
	}
	Component* shit;
	for (auto i = compomentList.begin(); i != compomentList.end(); i++) {
		delete i->second;//����е�ֱ��ˣ�������û�и��õĽ���취������ͬʱҲ˵��ɾ��ϵͳ������
	}
}

/* Camera Part */
Camera::Camera(vector<Component*>* initCompomentList, glm::vec3 pos) :Object("MainCamera", initCompomentList, pos) {
	
}

glm::mat4 Camera::getPerspective() {
	return glm::perspective(glm::radians(45.0f), (float)ObjectManager::width / (float)ObjectManager::height, 0.1f, 100.0f);
}
Camera::Camera(glm::vec3 pos) : Object("MainCamera", pos) {
	
}
glm::mat4 Camera::getCamaraView() {
	glm::mat4 posMat = glm::mat4(1.f);
	posMat = glm::translate(posMat, position);
	glm::qua<float> q1(glm::radians(rotation));
	glm::mat4 rot = glm::mat4(1.0f);
	rot = glm::mat4_cast(q1) * rot;
	glm::mat4 model = posMat * rot;

	model = glm::inverse(model);
	return model;
}