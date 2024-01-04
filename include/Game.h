#pragma once

#include "camera.h"
#include "renderer.h"
#include "FirstScene.h"
#include <glm/glm.hpp>

extern Camera camera;
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
	FirstScene* firstScene = nullptr;
	
};
