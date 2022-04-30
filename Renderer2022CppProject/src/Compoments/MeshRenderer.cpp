#include "MeshRenderer.h"
#include<glm/gtc/quaternion.hpp>

MeshRenderer::MeshRenderer(const char* modelFilePath, Shader* shader) :Component() {
	name = "Mesh Renderer";
	mesh = new Model(modelFilePath);
	this->shader = shader;
}

void MeshRenderer::Update(){
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