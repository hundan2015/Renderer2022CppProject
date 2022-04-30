#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include"../Object/Object.h"

class Object;

struct publicProperty {
	std::string name;
	std::string type;
	std::string value;
};

class Component
{
public:
	std::string name;
	int priority = 0;
	Object* masterObject = nullptr;
	std::map<std::string, publicProperty> propertyList;
	virtual void Update(){};
	virtual void FixedUpdate(){};
	Component();
	~Component();
};


static bool cmp(const Component* c1, const Component* c2) {
	if (!c1) return false;
	if (c2) {
		return c1->priority < c2->priority;
	}
	else {
		return false;
	}
	
}

