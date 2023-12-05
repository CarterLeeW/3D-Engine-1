#include "Primitive3D.h"

namespace prim3d {

	Primitive3D::Primitive3D()
	{
		initializeData();
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
