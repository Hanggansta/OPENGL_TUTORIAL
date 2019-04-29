#version 330 core

layout(location =0) in vec3 aPos;
out vec3 TexCoords;

uniform mat4 projection;
uniform mat4 view;

void main()
{
     mat4 skyview=mat4(mat3(view));  //remove transform information;
     TexCoords =aPos;
	 gl_Position =projection* skyview * vec4(aPos,1.0);

}