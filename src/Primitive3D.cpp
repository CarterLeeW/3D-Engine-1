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
	void Primitive3D::setTexture(std::string type, const char* path)
	{
		Texture newTexture;
		unsigned int textureID = loadTexture(path);
		newTexture.id = textureID;
		newTexture.type = type;
		textures.push_back(newTexture);
	}

} // namespace prim3d
