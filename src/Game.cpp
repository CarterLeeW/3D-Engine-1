#include "Game.h"
#include "scene.h"
#include <glad/glad.h>
#include "FirstScene.h"


Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	renderer = new Renderer(title, width, height);
    this->width = width;
    this->height = height;

	/* test stuff */
	firstScene = new FirstScene();  // build scene
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
	firstScene->renderLevel();
    
	glfwSwapBuffers(renderer->window);
	glfwPollEvents();
	if (glfwWindowShouldClose(renderer->window)) {
		firstScene->destroyObjects();
		isRunning = false;
		glfwTerminate();
	}
}

void Game::clean()
{

}