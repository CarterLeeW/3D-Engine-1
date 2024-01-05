#pragma once

#include "Primitive3D.h"

namespace prim3d {

	class Plane : public Primitive3D
	{
	public:
		Plane();

		void draw(Shader& shader);
		void setTexture(std::string type, const char* path);

		static constexpr float vertices[] = {
			// position            // normal            // texture
			-0.5f,  0.0f, -0.5f,   0.0f, 1.0f, 0.0f,    0.0f, 15.0f, // top-left
			 0.5f,  0.0f, -0.5f,   0.0f, 1.0f, 0.0f,    15.0f, 15.0f, // top-right
			 0.5f,  0.0f,  0.5f,   0.0f, 1.0f, 0.0f,    15.0f, 0.0f, // bottom-right                 
			 0.5f,  0.0f,  0.5f,   0.0f, 1.0f, 0.0f,    15.0f, 0.0f, // bottom-right
			-0.5f,  0.0f,  0.5f,   0.0f, 1.0f, 0.0f,    0.0f, 0.0f, // bottom-left  
			-0.5f,  0.0f, -0.5f,   0.0f, 1.0f, 0.0f,    0.0f, 15.0f  // top-left
		};

	private:
		void initializeData();

	};

} // namespace prim3d