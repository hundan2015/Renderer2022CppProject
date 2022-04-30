#pragma once
#include "Compoment.h"
#include"../Mesh/Model.h"
#include"../Shader/Shader.h"
using namespace std;

class MeshRenderer:public Component
{
private:
	Model* mesh;
	Shader* shader;
public:
	MeshRenderer(const char* modelFilePath, Shader* shader);
	void Update() override;
};

//这玩意应该封装成一个类
static Component* meshRendererConstuctor(vector<publicProperty> publicP) {
	string modelFilePath, shaderUUid;
	for (auto i : publicP) {
		string pName = i.name;
		if (pName == "modelFilePath") {
			modelFilePath = i.value;
		}
		else if (pName == "shaderUUid")
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
}
