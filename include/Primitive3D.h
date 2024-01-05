#pragma once
#include <glad/glad.h> // holds all OpenGL type declarations
#include <glm/glm.hpp>
#include "shader.h"
#include <stb_image/stb_image.h>
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

namespace prim3d {

    struct Transformations {
        glm::mat4 scale = glm::mat4(1.0f);
        glm::mat4 rotation = glm::mat4(1.0f);
        glm::mat4 translation = glm::mat4(1.0f);
        glm::mat3 normalMat = glm::mat3(1.0f);
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
        virtual void deleteMesh();

        glm::mat4 getScale() { return transform.scale; }
        glm::mat4 getRoation() { return transform.rotation; }
        glm::mat4 getTranslation() { return transform.translation; }
        glm::mat3 getNormalMat() { return transform.normalMat; }
        glm::mat4 getModel() { return transform.model; }
        void setScale(glm::vec3 xyz) { transform.scale = glm::scale(xyz); }
        void setRotation(float degrees, glm::vec3 xyz) { transform.rotation = glm::rotate(glm::radians(degrees), xyz); }
        void setTranslation(glm::vec3 xyz) { transform.translation = glm::translate(xyz); }
        /* always call after changing transformation matrices */
        void updateModelMatrix() {
            transform.model = transform.translation * transform.rotation * transform.scale;
            transform.normalMat = glm::mat3(transpose(inverse(transform.model)));   // update normal matrix
        }

    protected:
        unsigned int VAO, VBO;
        std::vector<Texture> textures;
        bool isInitialized = false;
        Transformations transform;

        unsigned int loadTexture(char const* path);
        unsigned int loadCubeMap(std::vector<std::string> faces);
        virtual void initializeMesh() {}; // only for some primitives
        virtual void initializeData() {};
    };

} // namespace prim3d