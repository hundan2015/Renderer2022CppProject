#include "CommandManager.h"
#include"Mesh/Mesh.h"
#include"Compoments/MeshRenderer.h"
#include"CommandManager.h"
#include"Compoments/ComponentManager.h"
#include<sstream>
using namespace std;
/*
-create
	-mesh
		-modelPath -vertexPath -fragmentPath //Create mesh object.
-delete
	-uuid //delete Object.
*/
static class ComponentManager;
std::map<int, Component*> ComponentManager::compomentGlobalList;

void CommandManager::commandAnalyzer(std::string commandLine) {
	stringstream strS;
	strS << commandLine;
	string command;
	strS >> command;
	if (command == "create") {
		strS >> command;
		if (command == "mesh") {
			string name,modelfile, vshader, fshader;
			strS >> name>>modelfile >> vshader, fshader;
			createMeshObject(name,modelfile.c_str(), vshader.c_str(), fshader.c_str(), this->objm, this->comM);
		}
		else {
			cout << "WARNING::CommandManager::Vaild creation." << endl;
		}
	}
	else if (command == "delete") {
		strS >> command;
		Object* target = objm->getObject(command);
		if (target) {
			delete target;
		}
		else {
			cout << "WARNING::CommandManager::No this object." << endl;
		}
	}
	else {
		cout << "WARNING::CommandManager::Vaild command." << endl;
	}
}

void CommandManager::createMeshObject(string name, const char* modelFilePath, const char* vshaderFilePath, const char* fshaderPath, ObjectManager* objm, ComponentManager* comM) {
	Shader* shader = new Shader(vshaderFilePath, fshaderPath);
	Object* object = new Object(name, glm::vec3(0., 0., 0.));
	object->addCompoment((Component*)(new MeshRenderer(modelFilePath, shader)));
}