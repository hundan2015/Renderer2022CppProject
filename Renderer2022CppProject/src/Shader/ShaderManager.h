#pragma once
#include"Shader.h"
#include<map>
using namespace std;
//If we need a bigger engine, we can abract a map Scene,
//which own its own ShaderManager and ComponentManager.
static class ShaderManager
{	
	//Shader have spetific name. Different shader should have different name.
public:
	static map<string, Shader*> shaderMap;
	static void makeNewShader(string name,const char* vsPath,const char* fsPath);
	static Shader* getShader(string name);
	static void deleteShader(string name);
};

