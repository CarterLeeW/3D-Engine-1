#pragma once
#include <stdio.h>
#include "camera.h"
#include "renderer.h"
static Camera camera;
static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
static void mouse_callback(GLFWwindow* window, GLdouble xposIn, GLdouble yposIn)
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

    std::cout << camera.Position.x << std::endl;         // debug camera position not updating

    camera.ProcessMouseMovement(xoffset, yoffset);
}

static void scroll_callback(GLFWwindow* window, GLdouble xoffset, GLdouble yoffset)
{
    camera.ProcessMouseScroll(static_cast<GLfloat>(yoffset));
}