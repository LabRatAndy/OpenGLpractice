#ifndef MESH_H
#define MESH_H
#include <GLEW/glew.h>
#include "Vertex.h"

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numvertices);
	virtual ~Mesh();
	void Draw();

private:
	Mesh(const Mesh& copy) = delete;
	Mesh operator=(const Mesh& assignee) = delete;
	
	enum
	{
		VBO,
		IBO,
		NUM_BUFFERS
	};
	GLuint VAO;
	GLuint buffers[NUM_BUFFERS];
	unsigned int drawcount;
};
#endif