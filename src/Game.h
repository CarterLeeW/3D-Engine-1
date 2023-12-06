#ifndef GAME_H
#define GAME_H
// for loading textures, shaders, and other objects
#define RESOURCES_PATH "C:/Users/carte/source/repos/AdvancedOpenGL/resources/"

#include "camera.h"
#include "shader.h"
#include "renderer.h"

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
};


#endif // !GAME_H
