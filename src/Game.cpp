#include "Game.h"

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	renderer = new Renderer(title, width, height);
	// FIXME load scene from scene.cpp


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
    ourShader.use();
    ourShader.setVec3("viewPos", camera.Position);
    ourShader.setFloat("material.shininess", 32.0f);
    // spotLight
    ourShader.setVec3("light.position", camera.Position);
    ourShader.setVec3("light.direction", camera.Front);
    ourShader.setVec3("light.ambient", 0.0f, 0.0f, 0.0f);
    ourShader.setVec3("light.diffuse", 1.0f, 1.0f, 1.0f);
    ourShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
    ourShader.setFloat("light.constant", 1.0f);
    ourShader.setFloat("light.linear", 0.09f);
    ourShader.setFloat("light.quadratic", 0.032f);
    ourShader.setFloat("light.cutOff", glm::cos(glm::radians(12.5f)));
    ourShader.setFloat("light.outerCutOff", glm::cos(glm::radians(15.0f)));

    // view/projection transformations
    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    glm::mat4 view = camera.GetViewMatrix();
    ourShader.setMat4("projection", projection);
    ourShader.setMat4("view", view);

    // render the loaded model
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
    ourShader.setMat4("model", model);
    ourShader.setMat3("modelMatNormals", glm::mat3(transpose(inverse(model))));
    ourModel.Draw(ourShader);


	glfwSwapBuffers(renderer->window);
	glfwPollEvents();
	if (glfwWindowShouldClose(renderer->window)) {
		isRunning = false;
		glfwTerminate();
	}
}

void Game::clean()
{

}