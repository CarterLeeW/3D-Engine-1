#include "Primitive3D.h"

namespace prim3d {

	Primitive3D::Primitive3D()
	{
		
	}
	Primitive3D::~Primitive3D()
	{
		deleteMesh();
	}
	void Primitive3D::deleteMesh()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}

} // namespace prim3d
