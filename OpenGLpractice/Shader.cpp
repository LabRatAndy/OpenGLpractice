#include "Shader.h"
#include <fstream>
#include <iostream>

static GLuint ReadShader(const std::string& filename, GLenum shaderType);

Shader::Shader(const std::string& vertexfilename, const std::string& fragmentfilename)
{
	handle = glCreateProgram();
	GLuint vertexShader = ReadShader(vertexfilename, GL_VERTEX_SHADER);
	GLuint fragmentShader = ReadShader(fragmentfilename, GL_FRAGMENT_SHADER);
	glAttachShader(handle, vertexShader);
	glAttachShader(handle, fragmentShader);
	//bind attribute locations
	glBindAttribLocation(handle, 0, "position");
	glBindAttribLocation(handle, 1, "normal");
	glBindAttribLocation(handle, 2, "texcoords");
	glLinkProgram(handle);
	GLint sucess = 0;
	glGetProgramiv(handle, GL_LINK_STATUS, &sucess);
	if (sucess != 0)
	{
		std::cerr << " Error linking shader: " << std::endl;
		GLint loglength;
		glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &loglength);
		GLchar* errormsg;
		errormsg =(GLchar*) std::malloc(loglength);
		glGetProgramInfoLog(handle, loglength, NULL, errormsg);
		std::cerr << errormsg << std::endl;
		std::free(errormsg);
	}
	glValidateProgram(handle);
	glGetProgramiv(handle, GL_VALIDATE_STATUS, &sucess);
	if (sucess != 0)
	{
		std::cerr << "Error validating shader!" << std::endl;
	}
}

Shader::~Shader()
{
	glDeleteProgram(handle);
}
void Shader::Use()
{
	glUseProgram(handle);
}
GLint Shader::GetAttributeLocation(const std::string& attributename)
{
	return glGetAttribLocation(handle, attributename.c_str());
}
GLint Shader::GetUniformLocation(const std::string& uniformname)
{
	return glGetUniformLocation(handle, uniformname.c_str());
}
static GLuint ReadShader(const std::string& filename, GLenum shaderType)
{
	GLuint handle = glCreateShader(shaderType);
	if (handle == 0)
	{
		std::cerr << "Shader creation failed" << std::endl;
	}
	std::string source, line;
	std::ifstream input;
	input.open(filename);
	if (input.is_open())
	{
		std::cerr << "unable to open shader source file: " << filename << std::endl;
		glDeleteShader(handle);
		return 0;
	}
	while (!input.good())
	{
		std::getline(input, line);
		source.append(line + "/n");
	}
	input.close();
	const GLchar* shaderSource[1];
	GLint shaderSourceLength[1];
	std::cerr << "Source:" << source << std::endl;
	shaderSource[0] = source.c_str();
	shaderSourceLength[0] = source.length();
	glShaderSource(handle, 1, shaderSource, shaderSourceLength);
	glCompileShader(handle);
	GLint sucess = 0;
	glGetShaderiv(handle, GL_COMPILE_STATUS, &sucess);
	std::cerr << "sucess value is: " << sucess << std::endl;
	if (sucess != 0)
	{
		GLint loglength;
		glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &loglength);
		std::cerr << "Log length = " << loglength;
		GLchar* errormsg;
		errormsg = (GLchar*)std::malloc(loglength);
		glGetShaderInfoLog(handle, loglength, NULL, errormsg);
		std::cerr << "Shader compile error: " << errormsg << std::endl;
		std::free(errormsg);
	}
	return handle;
}