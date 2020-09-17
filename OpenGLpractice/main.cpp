#include<iostream>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "GLwindow.h"
#include "Shader.h"
#include "mesh.h"
#include "Vertex.h"
#include<glm/glm.hpp>
void ErrorReport(int error, const char* description);

int main(int* argc, char* argv)
{
	//initialise glfw
	if (glfwInit() != GLFW_TRUE)
	{
		std::cerr << "GLFW initialisation failed. Exiting!" << std::endl;
		return 0;
	}
	glfwSetErrorCallback(ErrorReport);
	std::cout << "hello world" << std::endl;
	GLwindow theWindow(800, 600, "hello world");
	Vertex vertices[] = { Vertex(glm::vec3(-0.5,-0.5,0.0)),Vertex(glm::vec3(0.0,0.5,0.0)),Vertex(glm::vec3(0.5,-0.5,0.0)) };
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("basicshader.vert", "basicshader.frag");
	while (!theWindow.GetWindowClosing())
	{
		glfwPollEvents();
		theWindow.Clear(0, 150, 50, 255);
		shader.Use();
		mesh.Draw();
		theWindow.UpdateWindow();
		theWindow.Swapbuffer();
	}

	glfwTerminate();
	return 0;
}
void ErrorReport(int error, const char* description)
{
	std::cerr << "GLFW error: " << error << " " << description << std::endl;
}