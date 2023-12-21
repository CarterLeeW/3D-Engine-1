#pragma once
#include <iostream>
#include "shader.h"
#include "renderer.h"
#include "Game.h"
#include <glad/glad.h> // holds all OpenGL type declarations

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "Primitive3D.h"
#include "Cube.h"
#define RESOURCES_PATH "C:/Users/carte/source/repos/Engine1/resources/"
namespace scene {
    Shader* shader = nullptr;
    Cube* cube1 = nullptr;
    Cube* cube2 = nullptr;


	void printMe() {
		std::cout << "hello" << std::endl;
	}

	void buildObjects()
	{
        shader = new Shader(RESOURCES_PATH "shaders/texturedObject.vs", RESOURCES_PATH "shaders/texturedObject.fs");

        // first cube object
        cube1 = new Cube(true, false);
        cube1->setTexture("texture_diffuse", RESOURCES_PATH "textures/container2.png");
        cube2 = new Cube(true, false);
        cube2->setTexture("texture_diffuse", RESOURCES_PATH "textures/container2.png");
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
        // FIXME: make these variables class attributes eventually
        // static objects do not need to update in the render loop
        // template:
        /*
        scale = glm::scale(glm::vec3(0.75f, 0.2f, 0.25f));
        rotation = glm::rotate(glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        translation = glm::translate(glm::vec3(-2.2f, 0.4f, 0.0f));
        model = translation * rotation * scale;
        */
        glm::mat4 scale = glm::mat4(1.0f);
        glm::mat4 rotation = glm::mat4(1.0f);
        glm::mat4 translation = glm::mat4(1.0f);
        glm::mat4 model = glm::mat4(1.0f);
        // cube1
        scale = glm::scale(glm::vec3(3.0));
        rotation = glm::rotate(glm::radians(45.0f), glm::vec3(1.0f));
        translation = glm::translate(glm::vec3(0.0f, 0.0f, -4.0f));
        model = translation * rotation * scale;
        shader->setMat4("model", model);
        cube1->draw(*shader);
        // cube2
        


        
	}


	void destroyObjects()
	{
        delete(shader);
        delete(cube1);
	}
}