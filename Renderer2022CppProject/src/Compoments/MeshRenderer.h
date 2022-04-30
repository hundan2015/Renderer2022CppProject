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

//������Ӧ�÷�װ��һ����
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
		return nullptr; //�����Ҫ����Shader��������
	}
	else {
		cout << "ERROR::meshConstructor::Faild to create MeshRenderer." << endl;
		return nullptr;
	}
}
