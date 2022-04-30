#pragma once
#include"Shader/Shader.h"
#include"Object/ObjectManager.h"
#include"Compoments/Compoment.h"
class CommandManager
{
	ObjectManager* objm;
	ComponentManager* comM;
public:
	void commandAnalyzer(std::string commandLine);
	void createMeshObject(string name, const char* modelFilePath, const char* vshaderFilePath, const char* fshaderPath, ObjectManager* objm, ComponentManager* comM);
	CommandManager(ObjectManager* object,ComponentManager* comP):objm(object),comM(comP){};
};

