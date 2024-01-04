#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "camera.h"
#include "FirstScene.h"

extern Camera camera;    // global variable for use in other files
class Game
{
public:
	Game();
	~Game();
	void init();
	void handleEvents();
	void update();
	bool getIsRunning();
	void render();
	void clean();

	
private:
	bool isRunning = false; 
	FirstScene* firstScene = nullptr;
	
	// rendering
	int SCR_WIDTH = 800;
	int SCR_HEIGHT = 600;
	const char* TITLE = "game";
	GLFWwindow* window;
	// timing
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;
	float currentFrame = 0;

	// helper functions
	bool initGLFW();
	void updateFrameTiming();
	void processInput(GLFWwindow* window);
};
