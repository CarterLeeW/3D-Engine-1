#pragma once

#include "Primitive3D.h"

namespace prim3d {

	class Cube : public Primitive3D
	{
	public:
		Cube(std::vector<Vertex> vertices, std::vector<unsigned int> indices,
			std::vector<Texture> textures, bool multipleTextures);

		void render(Shader& shader) const override;

	private:
		bool multipleTextures = false;
		void initializeData() override;

	};

} // namespace prim3d