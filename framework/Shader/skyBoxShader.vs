#version 330 core

layout (location = 0) in vec3 Position; 

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 TexCoords;

void main()
{          
    gl_Position = projection * view * model * vec4(Position, 1.0);
	//gl_Position = pos.xyww;
	TexCoords = Position;
}
