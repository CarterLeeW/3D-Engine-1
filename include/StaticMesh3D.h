#ifndef STATICMESH3D_H
#define STATICMESH3D_H

#include <glad/glad.h> // holds all OpenGL type declarations

#include <glm/glm.hpp>

#include "shader.h"

#include <string>
#include <vector>

namespace sm3d {

	

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

	class StaticMesh3D
	{
	public:
		// mesh data
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<Texture> textures;

		StaticMesh3D(std::vector<Vertex> vertices, std::vector<unsigned int> indices,
			std::vector<Texture> textures)
		{
			this->vertices = vertices;
			this->indices = indices;
			this->textures = textures;

			setupMesh();
		}

		virtual ~StaticMesh3D()
		{}

		

		void Draw(Shader& shader)
		{
			// bind appropriate textures
			unsigned int diffuseNr = 1;
			unsigned int specularNr = 1;

			for (unsigned int i = 0; i < textures.size(); i++)
			{
				glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
				// retrieve texture number (the N in diffuse_textureN)
				std::string number;
				std::string name = textures[i].type;
				if (name == "texture_diffuse")
					number = std::to_string(diffuseNr++);
				else if (name == "texture_specular")
					number = std::to_string(specularNr++); // transfer unsigned int to string

				shader.setInt(("material." + name + number).c_str(), i);
				glBindTexture(GL_TEXTURE_2D, textures[i].id);
			}
			// draw mesh
			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);

			glActiveTexture(GL_TEXTURE0);

			// draw mesh

		}
	private:
		// render data
		unsigned int VAO, VBO, EBO;
		

		void setupMesh()
		{
			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glGenBuffers(1, &EBO);

			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);

			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex),
				&vertices[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() *
				sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

			// vertex positions
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
				sizeof(Vertex), (void*)0);
			// vertex normals
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
				sizeof(Vertex), (void*)offsetof(Vertex, Normal));
			// vertex texture coords
			glEnableVertexAttribArray(2);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
				sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));

			glBindVertexArray(0);
		}
	};
} // namespace sm3d
#endif //! STATICMESH3D_H

