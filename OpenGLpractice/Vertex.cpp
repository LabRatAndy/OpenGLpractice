#include "Vertex.h"
Vertex::Vertex(const glm::vec3 position)
{
	Position = position;
	Normal = glm::vec3();
	TexCoords = glm::vec2();
}
Vertex::Vertex(const glm::vec3 position, const glm::vec3 normal)
{
	Position = position;
	Normal = normal;
	TexCoords = glm::vec2();
}
Vertex::Vertex(const glm::vec3 position, const glm::vec3 normal, const glm::vec2 texcoords)
{
	Position = position;
	Normal = normal;
	TexCoords = texcoords;
}
Vertex::~Vertex()
{

}
glm::vec3 Vertex::GetPosition()
{
	return Position;
}
glm::vec3 Vertex::GetNormal()
{
	return Normal;
}
glm::vec2 Vertex::GetTexCoords()
{
	return TexCoords;
}
void Vertex::SetPosition(const glm::vec3 position)
{
	this->Position = position;
}
void Vertex::SetNormal(const glm::vec3 normal)
{
	this->Normal = normal;
}
void Vertex::SetTexCoords(const glm::vec2 texcoords)
{
	this->TexCoords = texcoords;
}