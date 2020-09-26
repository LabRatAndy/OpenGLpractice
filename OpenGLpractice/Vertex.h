#ifndef VERTEX_H
#define VERTEX_H
#include <glm/glm.hpp>

struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;

	Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 texcoords) : Position(position), Normal(normal), TexCoords(texcoords) {};
	Vertex(glm::vec3 position, glm::vec3 normal) : Position(position), Normal(normal) { TexCoords = glm::vec2(0.0, 0.0); };
	Vertex(glm::vec3 position) : Position(position) { Normal = glm::vec3(0.0, 0.0, 0.0); TexCoords = glm::vec2(0.0, 0.0); };
};
#endif // !VERTEX_H

