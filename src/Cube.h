#pragma once

#include "Primitive3D.h"



	class Cube : public Primitive3D
	{
	public:
		Cube(bool hasSpecular, bool multipleTextures);

		void draw(Shader& shader) const;

		static float vertices[288];

	private:
		bool multipleTextures = false;
		bool hasSpecular = false;
		void initializeData();

	};
