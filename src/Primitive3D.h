#pragma once
#include <glad/glad.h> // holds all OpenGL type declarations
#include <glm/glm.hpp>
#include "shader.h"
#include <stb_image/stb_image.h>
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>



struct Transformations {
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 rotation = glm::mat4(1.0f);
    glm::mat4 translation = glm::mat4(1.0f);
    glm::mat4 model = glm::mat4(1.0f);
};

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

    Primitive3D();
    virtual ~Primitive3D();
    virtual void draw(Shader& shader) = 0;
    void setTexture(std::string type, const char* path);
    virtual void deleteMesh();

    unsigned int loadTexture(char const* path)
    {
        unsigned int textureID;
        glGenTextures(1, &textureID);

        int width, height, nrComponents;
        unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
        if (data)
        {
            GLenum format;
            if (nrComponents == 1)
                format = GL_RED;
            else if (nrComponents == 3)
                format = GL_RGB;
            else if (nrComponents == 4)
                format = GL_RGBA;

            glBindTexture(GL_TEXTURE_2D, textureID);
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            stbi_image_free(data);
        }
        else
        {
            std::cout << "Texture failed to load at path: " << path << std::endl;
            stbi_image_free(data);
        }

        return textureID;
    }
    glm::mat4 getScale() { return transform.scale; }
    glm::mat4 getRoation() { return transform.rotation; }
    glm::mat4 getTranslation() { return transform.translation; }
    glm::mat4 getModel() { return transform.model; }
    void setScale(glm::vec3 xyz) { transform.scale = glm::scale(xyz); }
    void setRotation(float degrees, glm::vec3 xyz) { transform.rotation = glm::rotate(glm::radians(degrees), xyz); }
    void setTranslation(glm::vec3 xyz) { transform.translation = glm::translate(xyz); }
    void updateModelMatrix() { transform.model = transform.translation * transform.rotation * transform.scale; }

protected:
	unsigned int VAO, VBO;
    std::vector<Texture> textures;
	bool isInitialized = false;
    Transformations transform;

        
	virtual void initializeMesh() {}; // only for some primitives
	virtual void initializeData() {};
};

