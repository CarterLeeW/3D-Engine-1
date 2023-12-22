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

    void buildLight()
    {
        // directional light
        shader->setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
        shader->setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
        shader->setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
        shader->setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);

        // spotLight
        shader->setVec3("spotLight.position", camera.Position);
        shader->setVec3("spotLight.direction", camera.Front);
        shader->setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
        shader->setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
        shader->setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
        shader->setFloat("spotLight.constant", 1.0f);
        shader->setFloat("spotLight.linear", 0.09f);
        shader->setFloat("spotLight.quadratic", 0.032f);
        shader->setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
        shader->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
    }

	void buildObjects()
	{
        shader = new Shader(RESOURCES_PATH "shaders/texturedObjWithLight.vs", RESOURCES_PATH "shaders/texturedObjWithLight.fs");

        // update lights
        // spotLight
        shader->setVec3("spotLight.position", camera.Position);
        shader->setVec3("spotLight.direction", camera.Front);

        // first cube object
        cube1 = new Cube(true, false);
        // set initial world space
        cube1->setScale(glm::vec3(2.0f));
        cube1->setRotation(45.0f, glm::vec3(1.0f));
        cube1->setTranslation(glm::vec3(0.0f, 0.0f, -4.0f));
        cube1->updateModelMatrix();
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
        // cube1
        cube1->setRotation((float)glfwGetTime() *40.0f, glm::vec3(0.0f, 1.0f, 0.0f));
        cube1->updateModelMatrix();
        shader->setMat3("normalMat", cube1->getNormalMat());
        shader->setMat4("model", cube1->getModel());
        shader->setFloat("material.shininess", 32.0f);
        cube1->draw(*shader);
        
        
	}


	void destroyObjects()
	{
        delete(shader);
        delete(cube1);
	}
}