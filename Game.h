#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include <stb_image/stb_image.h>

// glm
#include "thirdparty/glm/glm.hpp"
#include "thirdparty/glm/gtc/matrix_transform.hpp"
#include "thirdparty/glm/gtc/type_ptr.hpp"

#include "camera.h"
#include "shader.h"
#include "renderer.h"

class Game
{
public:
	Game()
	{

	}
	~Game()
	{

	}

	bool isRunning = false;
	Renderer* renderer = nullptr;
    

	void init(const char* title, int width, int height, bool fullscreen)
	{
		renderer = new Renderer(title, width, height);
		isRunning = true;
	}

	void handleEvents();
	void update();
	//bool isRunning() { return isRunning; }
	void render()
	{
		renderer->updateFrameTiming();
		renderer->processInput(renderer->window);

		// clear the frame and z buffers
		glClearColor(0.2f, 0.15f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// loop and render meshes
		//
		//

		glfwSwapBuffers(renderer->window);
		glfwPollEvents();
		if (glfwWindowShouldClose(renderer->window)) { 
			isRunning = false;
			glfwTerminate();
		}
	}
	void clean();

	


private:
	int cnt = 0;
    
};


#endif // !GAME_H
