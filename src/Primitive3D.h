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
	};
	class Primitive3D
	{
	public:
		// mesh data
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<Texture> textures;

		// constructor
		Primitive3D(std::vector<Vertex> vertices, std::vector<unsigned int> indices,
			std::vector<Texture> textures);
		// destructor
		virtual ~Primitive3D();

		void Draw(Shader& shader);

	private:
		unsigned int VAO, VBO, EBO;

		void setupMesh();

	};

} // namespace prim3d