#pragma once
#include "Level.h"
#include "shader.h"
#include "Cube.h"
#include "model.h"
#include "Skybox.h"
#include "Plane.h"

class FirstScene : public Level
{
public:
	FirstScene();
	void renderLevel();
	void destroyObjects();

private:
	// global variables
	Shader* shader = nullptr;
	Shader* skyboxShader = nullptr;
	prim3d::Cube* cube1 = nullptr;
	sm3d::Model* backpack = nullptr;
	prim3d::Skybox* skybox = nullptr;
	prim3d::Plane* floor = nullptr;

	void buildScene();
	void buildShaders();
	void buildObjects();
	void buildLights();

};