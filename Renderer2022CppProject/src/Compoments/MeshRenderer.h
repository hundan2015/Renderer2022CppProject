#pragma once
#include "Compoment.h"
#include"../Mesh/Mesh.h"
#include"../Mesh/Model.h"
#include"../Shader/Shader.h"
#include <glm/gtc/quaternion.hpp>
using namespace std;
static class ObjectManager;
class Component;
class MeshRenderer:public Component
{
private:
	Model* mesh;
	Shader* shader;
public:
	MeshRenderer(const char* modelFilePath,Shader* shader):Component() {
		name = "Mesh Renderer";
		mesh = new Model(modelFilePath);
		this->shader = shader;
	}
	void Update() override{
		shader->use();
		glm::vec3 pos = this->masterObject->position;
		glm::vec3 rotate = this->masterObject->rotation;
		glm::qua<float> q1(glm::radians(rotate));
		glm::mat4 trans = glm::mat4(1.0f);
		glm::mat4 rot = glm::mat4(1.0f);
		trans = glm::translate(trans, pos);
		rot = glm::mat4_cast(q1) * rot;
		
		glm::mat4 model = trans * rot;
		shader->setMat4("model", model);
		Camera* mainCamera = ObjectManager::mainCamera;
		shader->setMat4("view", mainCamera->getCamaraView());
		shader->setMat4("projection", mainCamera->getPerspective());
		mesh->Draw(*(shader));
	}
	void FixUpdate() {

	}
};
/*
Component* meshRendererConstuctor(vector<publicProperty> publicP) {
	string modelFilePath, shaderUUid;
	for (auto i : publicP) {
		string pName = i.name;
		if (pName == "modelFilePath") {
			modelFilePath = i.value;
		}
		else if(pName=="shaderUUid")
		{
			shaderUUid = i.value;
		}
		else {
			cout << "WARNING::meshConstructor::Invaild property " << pName << endl;
		}
	}
	if (!modelFilePath.empty() && !shaderUUid.empty()) {
		return nullptr; //这块需要搭配Shader反射器。
	}
	else {
		cout << "ERROR::meshConstructor::Faild to create MeshRenderer." << endl;
		return nullptr;
	}
}*/
