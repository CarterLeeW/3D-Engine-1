#pragma once
#include <iostream>
#include "shader.h"
#include "renderer.h"
#include "Game.h"
#include <glad/glad.h> // holds all OpenGL type declarations

#include <glm/glm.hpp>
#include "Primitive3D.h"
#include "Cube.h"
#define RESOURCES_PATH "C:/Users/carte/source/repos/Engine1/resources/"
namespace scene {
    Shader* shader = nullptr;
    Cube* cube = nullptr;


	void printMe() {
		std::cout << "hello" << std::endl;
	}

	void buildObjects()
	{
        shader = new Shader(RESOURCES_PATH "shaders/texturedObject.vs", RESOURCES_PATH "shaders/texturedObject.fs");

        // first cube object
        cube = new Cube(true, false);
        cube->setTexture("texture_diffuse", RESOURCES_PATH "textures/container2.png");
	}

	void renderObjects()
	{
        shader->use();
        

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)800 / (float)600, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        shader->setMat4("projection", projection);
        shader->setMat4("view", view);

        // world transformation
        glm::mat4 model = glm::mat4(1.0f);
        shader->setMat4("model", model);

        cube->draw(*shader);
	}


	void destroyObjects()
	{
        delete(shader);
        delete(cube);
	}
}