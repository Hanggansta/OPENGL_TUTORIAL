#version 330 core
layout (location =0) in vec3 aPos;
layout (location =1) in vec3 aNormal;

uniform mat4 MVP;
uniform mat3 normalMatrix;
uniform vec3 lightDirection;
uniform vec4 color;
out vec4 vcolor;


void main()
{
    vec3 normal=normalMatrix*aNormal;
	vcolor = color*0.3 +color*max(dot(normal,lightDirection),0.0);
	gl_Position = MVP*vec4(aPos,1.0);
}