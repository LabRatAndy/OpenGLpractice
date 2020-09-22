#include "GLwindow.h"
#include <iostream>


GLwindow::GLwindow(const unsigned int width, const unsigned int height, const std::string& title)
{
	//glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
	glfwWindowHint(GLFW_RED_BITS, 8);
	glfwWindowHint(GLFW_GREEN_BITS, 8);
	glfwWindowHint(GLFW_BLUE_BITS, 8);
	glfwWindowHint(GLFW_ALPHA_BITS, 8);
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (!window)
	{
		std::cerr << "failed to create GLFW window" << std::endl;
	}
	glfwMakeContextCurrent(window);
	GLint status = glewInit();
	if (status != GLEW_OK)
	{
		std::cerr << "failed to initialise GLEW" << std::endl;
	}
	windowgclosing = false;
}
GLwindow::~GLwindow()
{
	glfwDestroyWindow(window);
}

void GLwindow::Swapbuffer()
{
	glfwSwapBuffers(window);
}
void GLwindow::UpdateWindow()
{
	windowgclosing = glfwWindowShouldClose(window);
}
void GLwindow::Clear(const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha)
{
	float r = (float)(red / (unsigned char)255);
	float g = (float)(green / (unsigned char)255);
	float b = (float)(blue / (unsigned char)255);
	float a = (float)(alpha / (unsigned char)255);
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void GLwindow::Clear(const float red, const float green, const float blue, const float alpha)
{
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}