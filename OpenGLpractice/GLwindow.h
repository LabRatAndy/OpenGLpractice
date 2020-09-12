#ifndef GLWINDOW_H
#define GLWINDOW_H
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <string>
class GLwindow
{
public:
	GLwindow(const unsigned int width,const unsigned int height, const std::string& title );
	virtual ~GLwindow();

	bool inline GetWindowClosing() { return windowgclosing; };
	void Clear(const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpah);
	void UpdateWindow();
	void Swapbuffer();
private:
	GLwindow(const GLwindow& copy) = delete;
	GLwindow operator = (const GLwindow& assignee) = delete;

	GLFWwindow* window;
	bool windowgclosing;
};

#endif // !GLWINDOW_H

