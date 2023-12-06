#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// define callbacks
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void scroll_callback(GLFWwindow* window, GLdouble xoffset, GLdouble yoffset);
void mouse_callback(GLFWwindow* window, GLdouble xposIn, GLdouble yposIn);
class Renderer
{
public:

    int SCR_WIDTH = 800;
    int SCR_HEIGHT = 600;
    const char* TITLE = "";
    GLFWwindow* window;
    static Camera camera;
    // timing
    GLfloat deltaTime = 0.0f;
    GLfloat lastFrame = 0.0f;
    float currentFrame = 0;
    bool firstMouse = true;

    // constructor
    
    Renderer(const char* title, int width, int height)
    {
        TITLE = title;
        SCR_WIDTH = width;
        SCR_HEIGHT = height;
        if (!initGLFW()) {
            std::cout << "Failure loading OpenGL renderer" << std::endl;
        }
    }

    void updateFrameTiming()
    {
        currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
    }
    void processInput(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        // process key presses
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camera.ProcessKeyboard(FORWARD, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camera.ProcessKeyboard(BACKWARD, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            camera.ProcessKeyboard(LEFT, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camera.ProcessKeyboard(RIGHT, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
            camera.ProcessKeyboard(UP, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
            camera.ProcessKeyboard(DOWN, deltaTime);
    }
private:

    bool initGLFW()
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

        return true;
    }

};

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void mouse_callback(GLFWwindow* window, GLdouble xposIn, GLdouble yposIn)
{
    GLfloat xpos = static_cast<GLfloat>(xposIn);
    GLfloat ypos = static_cast<GLfloat>(yposIn);

    if (Renderer::camera.firstMouse)
    {
        Renderer::camera.lastX = xpos;
        Renderer::camera.lastY = ypos;
        //firstMouse = false;
    }

    GLfloat xoffset = xpos - Renderer::camera.lastX;
    GLfloat yoffset = Renderer::camera.lastY - ypos;
    Renderer::camera.lastX = xpos;
    Renderer::camera.lastY = ypos;

    Renderer::camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, GLdouble xoffset, GLdouble yoffset)
{
    Renderer::camera.ProcessMouseScroll(static_cast<GLfloat>(yoffset));
}


#endif // !RENDERER_H