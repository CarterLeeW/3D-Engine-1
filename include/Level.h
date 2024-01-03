#pragma once
#define RESOURCES_PATH "C:/Users/carte/source/repos/Engine1/resources/"


class Level
{

public:
	Level();
	virtual ~Level();

	virtual void renderLevel() = 0;
	void destroyObjects();

protected:
	// internal functions
	virtual void buildScene();
	virtual void buildShaders();
	virtual void buildObjects();
	virtual void buildLights();

	
};