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
#include "model.h"
#include "StaticMesh3D.h"
#define RESOURCES_PATH "C:/Users/carte/source/repos/Engine1/resources/"
namespace scene {
    Shader* shader = nullptr;
    prim3d::Cube* cube1 = nullptr;
    //Cube* cube2 = nullptr;
    sm3d::Model* backpack = nullptr;

    // function prototypes
    void buildScene();
    void buildShaders();
    void buildObjects();
    void buildLights();

    /* builds shaders, objects, and lights */
    void buildScene()
    {
        buildShaders();
        buildObjects();
        buildLights();
    }

    /* must be called before buildObjects and buildLights */
    void buildShaders()
    {
        shader = new Shader(RESOURCES_PATH "shaders/texturedObjWithLight.vs", RESOURCES_PATH "shaders/texturedObjWithLight.fs");
    }

	void buildObjects()
	{
        
        shader->use();
        stbi_set_flip_vertically_on_load(true);
        // first cube object
        cube1 = new prim3d::Cube(true, false);
        // set initial world space
        cube1->setScale(glm::vec3(2.0f));
        cube1->setRotation(45.0f, glm::vec3(1.0f));
        cube1->setTranslation(glm::vec3(0.0f, 0.0f, -4.0f));
        cube1->updateModelMatrix();
        cube1->setTexture("texture_diffuse", RESOURCES_PATH "textures/container2.png");
        cube1->setTexture("texture_specular", RESOURCES_PATH "textures/container2_specular.png");

        // backpack model loading ussing 
        backpack = new sm3d::Model(RESOURCES_PATH "objects/backpack/backpack.obj");
        backpack->setScale(glm::vec3(0.5f));
        backpack->setTranslation(glm::vec3(3.0f, 2.0f, -5.0f));
        backpack->updateModelMatrix();

	}

    void buildLights()
    {
        shader->setInt("material.texture_diffuse1", 0);
        shader->setInt("material.texture_specular", 1);

        // directional light
        shader->setVec3("dirLight.direction", -0.6f, -1.0f, -0.3f);
        shader->setVec3("dirLight.ambient", 0.03f, 0.03f, 0.03f);
        shader->setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
        shader->setVec3("dirLight.specular", 0.6f, 0.6f, 0.6f);

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

	void renderObjects()
	{
        shader->use();
        shader->setVec3("viewPos", camera.Position);

        // update lights
        // spotLight
        shader->setVec3("spotLight.position", camera.Position);
        shader->setVec3("spotLight.direction", camera.Front);

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
        // backpack
        shader->setMat3("normalMat", backpack->getNormalMat());
        shader->setMat4("model", backpack->getModel());
        shader->setFloat("material.shininess", 64.0f);
        backpack->Draw(*shader);
	}


	void destroyObjects()
	{
        delete(shader);
        delete(cube1);
        delete(backpack);
	}
}