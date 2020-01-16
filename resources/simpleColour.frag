#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;

void main()
{
	FragColor = vec4(0.4f, 0.0f, 0.4f, 0.0f);
}