#include "Primitive3D.h"

namespace prim3d {

	Primitive3D::Primitive3D(std::vector<Vertex> vertices, std::vector<unsigned int> indices,
		std::vector<Texture> textures)
	{
		this->vertices = vertices;
		this->indices = indices;
		this->textures = textures;
	}
	Primitive3D::~Primitive3D()
	{
		deleteMesh();
	}
	void Primitive3D::deleteMesh()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

} // namespace prim3d
