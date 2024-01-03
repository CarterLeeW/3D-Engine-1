#pragma once
#include "Level.h"
#include "shader.h"
#include "Cube.h"
#include "model.h"

class FirstScene : public Level
{
public:
	FirstScene();
	void renderLevel();
	void destroyObjects();

private:
	// global variables
	Shader* shader = nullptr;
	prim3d::Cube* cube1 = nullptr;
	sm3d::Model* backpack = nullptr;

	void buildScene();
	void buildShaders();
	void buildObjects();
	void buildLights();

};