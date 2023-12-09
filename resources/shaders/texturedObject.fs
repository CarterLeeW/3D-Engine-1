#version 460 core
out vec4 FragColor;

in vec2 TexCoords;

struct Material {
	sampler2D texture_diffuse;
	sampler2D texture_specular;
};

uniform Material material;

void main()
{
	FragColor = texture(material.texture_diffuse, TexCoords);
}