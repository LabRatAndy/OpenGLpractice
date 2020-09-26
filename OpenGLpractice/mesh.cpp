#include "mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numvertices)
{
	drawcount = numvertices;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(NUM_BUFFERS, buffers);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[VBO]);
	glBufferData(GL_ARRAY_BUFFER, numvertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	//position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), 0);
	//normal attribute
	unsigned int offset = sizeof(vertices[0].Position);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), &offset);
	//Tex Coords
	offset = sizeof(vertices[0].Position) + sizeof(vertices[0].Normal);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), &offset);

	glBindVertexArray(0);
}
Mesh::~Mesh()
{
	glDeleteBuffers(NUM_BUFFERS, buffers);
	glDeleteVertexArrays(1, &VAO);
}
void Mesh::Draw()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, drawcount);
	glBindVertexArray(0);
}