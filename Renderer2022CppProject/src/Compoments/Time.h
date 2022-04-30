#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static class Time
{
public:
	static float lastTime;
	static float deltaTime;
	static void caculateDeltaTime() {
		float timeNow = glfwGetTime();
		if (lastTime == -1) {
			deltaTime = 0;
			return;
		}
		deltaTime = timeNow - lastTime;
		lastTime = timeNow;
	}
};

