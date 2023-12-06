#include "Cube.h"

namespace prim3d {

    float Cube::vertices[] = {
        // back face
        // position            // normal            // texture
        -0.5f, -0.5f, -0.5f,   0.0f, 0.0f, -1.0f,   0.0f, 0.0f, // bottom-left
         0.5f, -0.5f, -0.5f,   0.0f, 0.0f, -1.0f,   1.0f, 0.0f, // bottom-right    
         0.5f,  0.5f, -0.5f,   0.0f, 0.0f, -1.0f,   1.0f, 1.0f, // top-right              
         0.5f,  0.5f, -0.5f,   0.0f, 0.0f, -1.0f,   1.0f, 1.0f, // top-right
        -0.5f,  0.5f, -0.5f,   0.0f, 0.0f, -1.0f,   0.0f, 1.0f, // top-left
        -0.5f, -0.5f, -0.5f,   0.0f, 0.0f, -1.0f,   0.0f, 0.0f, // bottom-left                
        // front face                     
        -0.5f, -0.5f,  0.5f,   0.0f, 0.0f, 1.0f,    0.0f, 0.0f, // bottom-left
         0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 1.0f,    1.0f, 1.0f, // top-right
         0.5f, -0.5f,  0.5f,   0.0f, 0.0f, 1.0f,    1.0f, 0.0f, // bottom-right        
         0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 1.0f,    1.0f, 1.0f, // top-right
        -0.5f, -0.5f,  0.5f,   0.0f, 0.0f, 1.0f,    0.0f, 0.0f, // bottom-left
        -0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 1.0f,    0.0f, 1.0f, // top-left        
        // left face                      
        -0.5f,  0.5f,  0.5f,  -1.0f, 0.0f, 0.0f,    1.0f, 0.0f, // top-right
        -0.5f, -0.5f, -0.5f,  -1.0f, 0.0f, 0.0f,    0.0f, 1.0f, // bottom-left
        -0.5f,  0.5f, -0.5f,  -1.0f, 0.0f, 0.0f,    1.0f, 1.0f, // top-left       
        -0.5f, -0.5f, -0.5f,  -1.0f, 0.0f, 0.0f,    0.0f, 1.0f, // bottom-left
        -0.5f,  0.5f,  0.5f,  -1.0f, 0.0f, 0.0f,    1.0f, 0.0f, // top-right
        -0.5f, -0.5f,  0.5f,  -1.0f, 0.0f, 0.0f,    0.0f, 0.0f, // bottom-right
        // right face                     
         0.5f,  0.5f,  0.5f,   1.0f, 0.0f, 0.0f,    1.0f, 0.0f, // top-left
         0.5f,  0.5f, -0.5f,   1.0f, 0.0f, 0.0f,    1.0f, 1.0f, // top-right      
         0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,    0.0f, 1.0f, // bottom-right          
         0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,    0.0f, 1.0f, // bottom-right
         0.5f, -0.5f,  0.5f,   1.0f, 0.0f, 0.0f,    0.0f, 0.0f, // bottom-left
         0.5f,  0.5f,  0.5f,   1.0f, 0.0f, 0.0f,    1.0f, 0.0f, // top-left
        // bottom face                      
        -0.5f, -0.5f, -0.5f,   0.0f, -1.0f, 0.0f,   0.0f, 1.0f, // top-right
         0.5f, -0.5f,  0.5f,   0.0f, -1.0f, 0.0f,   1.0f, 0.0f, // bottom-left
         0.5f, -0.5f, -0.5f,   0.0f, -1.0f, 0.0f,   1.0f, 1.0f, // top-left        
         0.5f, -0.5f,  0.5f,   0.0f, -1.0f, 0.0f,   1.0f, 0.0f, // bottom-left
        -0.5f, -0.5f, -0.5f,   0.0f, -1.0f, 0.0f,   0.0f, 1.0f, // top-right
        -0.5f, -0.5f,  0.5f,   0.0f, -1.0f, 0.0f,   0.0f, 0.0f, // bottom-right
        // top face                       
        -0.5f,  0.5f, -0.5f,   0.0f, 1.0f, 0.0f,    0.0f, 1.0f, // top-left
         0.5f,  0.5f, -0.5f,   0.0f, 1.0f, 0.0f,    1.0f, 1.0f, // top-right
         0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 0.0f,    1.0f, 0.0f, // bottom-right                 
         0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 0.0f,    1.0f, 0.0f, // bottom-right
        -0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 0.0f,    0.0f, 0.0f, // bottom-left  
        -0.5f,  0.5f, -0.5f,   0.0f, 1.0f, 0.0f,    0.0f, 1.0f  // top-left              
    };


	Cube::Cube(bool hasSpecular, bool multipleTextures)
		: Primitive3D()
	{
		this->multipleTextures = multipleTextures;
        this->hasSpecular = hasSpecular;
		initializeData();
	}

    void Cube::initializeData()
    {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VAO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    }

    void Cube::draw(Shader& shader) const
    {

    }

} // namespace prim3d