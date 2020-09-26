#ifndef VERTEX_H
#define VERTEX_H
#include <glm/glm.hpp>

struct Vertex
{
	glm::vec3 Position;
	//glm::vec3 Normal;
	//glm::vec2 TexCoords;

	//Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 texcoords) : Position(position), Normal(normal), TexCoords(texcoords) {};
	//Vertex(glm::vec3 position, glm::vec3 normal) : Position(position), Normal(Normal) {};
	Vertex(glm::vec3 position) : Position(position) {};

};
#endif // !VERTEX_H

