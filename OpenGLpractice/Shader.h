#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <GLEW/glew.h>

class Shader
{
public:
	Shader(const std::string& vertexfilename, const std::string& fragmentfilename);
	virtual ~Shader();
	void Use();
	GLint GetAttributeLocation(const std::string& attributename);
	GLint GetUniformLocation(const std::string& uniformname);
private:
	Shader(const Shader& copy) = delete;
	Shader operator=(const Shader& assignee) = delete;
	GLuint handle;
};
#endif
