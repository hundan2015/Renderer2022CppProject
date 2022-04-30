#pragma once
#include"Light.h"
class LightManager
{
	map<string, PointLight*> pointLightMap;
	map<string, DirLight*> dirLightMap;
	map<string, SpotLight*> spotLightMap;
	const unsigned int maxLightCount;
public:
	LightManager(unsigned int maxCount = 4);
	void addPointLight(PointLight* p);
	void addDirLight(DirLight* p);
	void addSpotLight(SpotLight* p);
	void deletePointLight(string p);
	void deleteDirLight(string  p);
	void deleteSpotLight(string p);
	void setLightToShader();//need a ShaderManager
};

