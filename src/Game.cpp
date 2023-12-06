#include "Game.h"

float vertices[] = {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
};
Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	renderer = new Renderer(title, width, height);
    this->width = width;
    this->height = height;
	// FIXME load scene from scene.cpp and edit this out
    /* test stuff */
    shader = new Shader(RESOURCES_PATH "shaders/shader.vs", RESOURCES_PATH "shaders/shader.fs");
    shader->use();
    // first, configure the cube's VAO (and VBO)

    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
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
    shader->use();
    // be sure to activate shader when setting uniforms/drawing objects
    shader->setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    shader->setVec3("lightColor", 1.0f, 1.0f, 1.0f);

    // view/projection transformations
    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)width / (float)height, 0.1f, 100.0f);
    glm::mat4 view = camera.GetViewMatrix();
    shader->setMat4("projection", projection);
    shader->setMat4("view", view);

    // world transformation
    glm::mat4 model = glm::mat4(1.0f);
    shader->setMat4("model", model);

    // render the cube
    glBindVertexArray(cubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    


	glfwSwapBuffers(renderer->window);
	glfwPollEvents();
	if (glfwWindowShouldClose(renderer->window)) {
        glDeleteVertexArrays(1, &cubeVAO);
        glDeleteBuffers(1, &VBO);
		isRunning = false;
		glfwTerminate();
	}
}

void Game::clean()
{

}