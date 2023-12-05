#pragma once

#include "Primitive3D.h"

namespace prim3d {

	class Cube : public Primitive3D
	{
	public:
		Cube(bool multipleTextures);

		void render(Shader& shader) const override;

		static float vertices[288];

	private:
		bool multipleTextures = false;
		void initializeData() override;

	};

} // namespace prim3d