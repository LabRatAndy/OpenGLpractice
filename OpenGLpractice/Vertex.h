#ifndef VERTEX_H
#define VERTEX_H
#include <glm/glm.hpp>

/*class Vertex
{
public:
	Vertex(const glm::vec3 position, const glm::vec3 normal, const glm::vec2 texcoords);
	Vertex(const glm::vec3 position);
	Vertex(const glm::vec3 position, const glm::vec3 normal);
	virtual ~Vertex();

	glm::vec3 GetPosition();
	glm::vec3 GetNormal();
	glm::vec2 GetTexCoords();

	void SetPosition(const glm::vec3 position);
	void SetNormal(const glm::vec3 normal);
	void SetTexCoords(const glm::vec2 texcoords);
private:
//	Vertex(const Vertex& copy) = delete;
//	Vertex operator=(const Vertex& assignee) = delete;
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};*/
struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;

	Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 texcoords) : Position(position), Normal(normal), TexCoords(texcoords) {};
	Vertex(glm::vec3 position, glm::vec3 normal) : Position(position), Normal(Normal) {};
	Vertex(glm::vec3 position) : Position(position) {};

};
#endif // !VERTEX_H

