#include "ShaderManager.h"
#include"Shader.h"
map<string, Shader*> ShaderManager::shaderMap;
void ShaderManager::makeNewShader(string name, const char* vsPath, const char* fsPath)
{
	if (shaderMap.find(name) == shaderMap.end()) {
		shaderMap.insert(make_pair(name, new Shader(vsPath, fsPath)));
	}
	else {
		cout << "WARNING::ShaderManager::This shader is existed.";
	}
}

Shader* ShaderManager::getShader(string name)
{
	auto iter = shaderMap.find(name);
	if (iter != shaderMap.end()) {
		return iter->second;
	}
	else {
		cout << "WARNING::ShaderManager::This shader doesn't exist.";
		return nullptr;
	}
}

void ShaderManager::deleteShader(string name)
{
	auto iter = shaderMap.find(name);
	if (iter != shaderMap.end()) {
		shaderMap.erase(iter);
	}
	else {
		cout << "WARNING::ShaderManager::This shader doesn't exist.";
	}
}
