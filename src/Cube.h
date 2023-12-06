#pragma once

#include "Primitive3D.h"


namespace prim3d {

	class Cube : public Primitive3D
	{
	public:
		Cube(bool hasSpecular, bool multipleTextures);

		void draw(Shader& shader) const override;

		static float vertices[288];

	private:
		bool multipleTextures = false;
		bool hasSpecular = false;
		void initializeData() override;

	};

} // namespace prim3d