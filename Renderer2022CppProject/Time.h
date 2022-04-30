#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static class Time
{
	static float lastTime;
public:
	static float deltaTime;
	static void caculateDeltaTime() {
		float timeNow = glfwGetTime();
		deltaTime = timeNow - lastTime;
		lastTime = timeNow;
	}
};

