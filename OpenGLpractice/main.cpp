#include<iostream>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "GLwindow.h"
#include "Shader.h"
#include "mesh.h"
#include "Vertex.h"
#include<glm/glm.hpp>

int main(int* argc, char* argv)
{
	//initialise glfw
	glfwInit();
	std::cout << "hello world" << std::endl;
	Vertex vertices[] = { Vertex(glm::vec3(-0.5,-0.5,0.0)),Vertex(glm::vec3(0.0,0.5,0.0)),Vertex(glm::vec3(0.5,-0.5,0.0)) };
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("basicshader.vert", "basicshader.frag");
	GLwindow theWindow(800, 600, "hello world");
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