#include "Game.h"
#include "scene.h"
#include <glad/glad.h>

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	renderer = new Renderer(title, width, height);
    this->width = width;
    this->height = height;
	// FIXME load scene from scene.cpp and edit this out
    scene::buildObjects();
	scene::buildLight();
    /* test stuff */
   
    /* test stuff */

	isRunning = true;
}

void Game::handleEvents()
{

}

void Game::update()
{

}

bool Game::getIsRunning() { return isRunning; }

void Game::render()
{
	renderer->updateFrameTiming();
	renderer->processInput(renderer->window);

	// clear the frame and z buffers
	glClearColor(0.2f, 0.15f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// loop and render meshes
	//
	//
	scene::renderObjects();
    
	glfwSwapBuffers(renderer->window);
	glfwPollEvents();
	if (glfwWindowShouldClose(renderer->window)) {
		scene::destroyObjects();
		isRunning = false;
		glfwTerminate();
	}
}

void Game::clean()
{

}