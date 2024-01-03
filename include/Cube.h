#pragma once

#include "Primitive3D.h"

namespace prim3d {

    class Cube : public Primitive3D
    {
    public:
        Cube(bool hasSpecular, bool multipleTextures);

        void draw(Shader& shader);

        float vertices[288] = {
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

    private:
        bool multipleTextures = false;
        bool hasSpecular = false;
        void initializeData();

    };

} // namespace prim3d