#pragma once
#include<GLFW/glfw3.h>
static class ActionManager
{
public:
	static GLFWwindow* window;
	static int getKey(int glfwKey);
};

