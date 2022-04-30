#include "ActionManager.h"

GLFWwindow* ActionManager::window;
int ActionManager::getKey(int glfwKey)
{
    return glfwGetKey(window, glfwKey);
}
