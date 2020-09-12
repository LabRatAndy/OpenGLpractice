#include<iostream>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "GLwindow.h"

int main(int* argc, char* argv)
{
	//initialise glfw and glew
	glfwInit();
	std::cout << "hello world" << std::endl;
	GLwindow theWindow(800, 600, "hello world");
	while (!theWindow.GetWindowClosing())
	{
		glfwPollEvents();
		theWindow.Clear(0, 150, 50, 255);
		theWindow.UpdateWindow();
		theWindow.Swapbuffer();
	}

	glfwTerminate();
	return 0;
}