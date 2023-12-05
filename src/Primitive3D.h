#pragma once
#include <glad/glad.h> // holds all OpenGL type declarations
#include <glm/glm.hpp>
#include "shader.h"

#include <vector>
#include <string>

namespace prim3d {
	struct Vertex {
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
	};

	struct Texture {
		unsigned int id;
		std::string type;
		std::string path;
	};
	class Primitive3D
	{
	public:
		
		Primitive3D();
		virtual ~Primitive3D();
		virtual void render(Shader& shader) const = 0;
		virtual void deleteMesh();

	protected:
		unsigned int VAO, VBO;
		bool isInitialized = false;

		virtual void initializeMesh() {}; // only for some primitives
		virtual void initializeData() {};
	};

} // namespace prim3d