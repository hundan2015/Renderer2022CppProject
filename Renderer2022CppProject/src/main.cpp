#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include"Object/Object.h"
#include"Object/ObjectManager.h"
#include"Compoments/Compoment.h"
#include"Compoments/Movement.h"

#include"Mesh/Model.h"
#include"Compoments/MeshRenderer.h"
#include"Shader/Shader.h"
#include"Compoments/ComponentManager.h"

#include"ActionManager.h"
#include"Compoments/Time.h"

const unsigned int SCR_WIDTH = 1600;
const unsigned int SCR_HEIGHT = 1200;

using namespace std;
static class ComponentManager;
static class ObjectManager;
static class ActionManager;

static class Time;
float Time::lastTime;
void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "GL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	ActionManager::window = window;
	stbi_set_flip_vertically_on_load(true);
	glEnable(GL_DEPTH_TEST);
	Time::lastTime = glfwGetTime();

	Camera* MainCamera=new Camera(glm::vec3(1.,2.,10),SCR_WIDTH,SCR_HEIGHT);
	MainCamera->addCompoment(new Movement(1.f));
	ObjectManager::changeCamera(MainCamera);
	Shader ourShader("glslShader\\simple2.vs", "glslShader\\simplePhong.fs");
	Object gameObject("shit",glm::vec3(0,0,0));
	gameObject.addCompoment(new MeshRenderer("model/backpack/backpack.obj",&ourShader));
	ObjectManager::registerObject(&gameObject);


	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.05f, 0.5f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Time::caculateDeltaTime();
		processInput(window);
		ComponentManager::compomentUpdate();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}