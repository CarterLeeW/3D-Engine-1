#pragma once

#include "renderer.h"
#include <glad/glad.h> // holds all OpenGL type declarations
#include <glm/glm.hpp>


#include "Cube.h"

class Game
{
public:
	Game();
	~Game();
	void init(const char* title, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	bool getIsRunning();
	void render();
	void clean();

private:
	bool isRunning = false;
	Renderer* renderer = nullptr;
	int cnt = 0;  
	int width;
	int height;
	unsigned int VBO, cubeVAO;

	Cube* box;
};
