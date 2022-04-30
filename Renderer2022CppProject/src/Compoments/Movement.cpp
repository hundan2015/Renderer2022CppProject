#include "Movement.h"
#include"../ActionManager.h"
#include<GLFW/glfw3.h>
#include"Time.h"
static class ActionManager;
static class Time;
float Time::deltaTime;

void Movement::Update()
{
	if (ActionManager::getKey(GLFW_KEY_W)) {
		masterObject->position.z -= Time::deltaTime * speed;
	}
	if (ActionManager::getKey(GLFW_KEY_S)) {
		masterObject->position.z += Time::deltaTime * speed;
	}
	if (ActionManager::getKey(GLFW_KEY_A)) {
		masterObject->position.x -= Time::deltaTime * speed;
	}
	if (ActionManager::getKey(GLFW_KEY_D)) {
		masterObject->position.x += Time::deltaTime * speed;
	}
}

Movement::Movement(float spd) :speed(spd) {

}
