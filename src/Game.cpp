#include "Game.h"
#include <glad/glad.h>

// declare callbacks
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, GLdouble xposIn, GLdouble yposIn);
void scroll_callback(GLFWwindow* window, GLdouble xoffset, GLdouble yoffset);

// define camera
Camera camera;


Game::Game() {}
Game::~Game() {}

void Game::init()
{
	if (!initGLFW()) {
		std::cout << "Failure loading OpenGL renderer" << std::endl;
		isRunning = false;
		return;
	}
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
	updateFrameTiming();
	processInput(window);

	// clear the frame and z buffers
	glClearColor(0.2f, 0.15f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// loop and render meshes
	//
	//
	firstScene->renderLevel();
    
	glfwSwapBuffers(window);
	glfwPollEvents();
	if (glfwWindowShouldClose(window)) {
		firstScene->destroyObjects();
		isRunning = false;
		glfwTerminate();
	}
}

void Game::clean()
{

}


// helper functions
void Game::updateFrameTiming()
{
	currentFrame = static_cast<float>(glfwGetTime());
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

void Game::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	// process key presses
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(Camera_Movement::FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(Camera_Movement::BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(Camera_Movement::LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(Camera_Movement::RIGHT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		camera.ProcessKeyboard(Camera_Movement::UP, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		camera.ProcessKeyboard(Camera_Movement::DOWN, deltaTime);
}

bool Game::initGLFW()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif

	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, TITLE, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}


	// capture motion and disable cursor
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);

	return true;
}


// callbacks for renderer
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
void mouse_callback(GLFWwindow* window, GLdouble xposIn, GLdouble yposIn)
{
	GLfloat xpos = static_cast<GLfloat>(xposIn);
	GLfloat ypos = static_cast<GLfloat>(yposIn);

	if (camera.firstMouse)
	{
		camera.lastX = xpos;
		camera.lastY = ypos;
		camera.firstMouse = false;
	}

	GLfloat xoffset = xpos - camera.lastX;
	GLfloat yoffset = camera.lastY - ypos;
	camera.lastX = xpos;
	camera.lastY = ypos;

	// debug camera position not updating

	camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, GLdouble xoffset, GLdouble yoffset)
{
	camera.ProcessMouseScroll(static_cast<GLfloat>(yoffset));
}