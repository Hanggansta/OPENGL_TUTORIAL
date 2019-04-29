#pragma once
#include<glad/glad.h>
#include"mesh.h"

class Cube : public Mesh
{
public:
	Cube()
	{
			Positions = std::vector<glm::vec3>{
				glm::vec3(-0.5f, -0.5f, -0.5f),
				glm::vec3(0.5f,  0.5f, -0.5f),
				glm::vec3(0.5f, -0.5f, -0.5f),
				glm::vec3(0.5f,  0.5f, -0.5f),
				glm::vec3(-0.5f, -0.5f, -0.5f),
				glm::vec3(-0.5f,  0.5f, -0.5f),

				glm::vec3(-0.5f, -0.5f,  0.5f),
				glm::vec3(0.5f, -0.5f,  0.5f),
				glm::vec3(0.5f,  0.5f,  0.5f),
				glm::vec3(0.5f,  0.5f,  0.5f),
				glm::vec3(-0.5f,  0.5f,  0.5f),
				glm::vec3(-0.5f, -0.5f,  0.5f),

				glm::vec3(-0.5f,  0.5f,  0.5f),
				glm::vec3(-0.5f,  0.5f, -0.5f),
				glm::vec3(-0.5f, -0.5f, -0.5f),
				glm::vec3(-0.5f, -0.5f, -0.5f),
				glm::vec3(-0.5f, -0.5f,  0.5f),
				glm::vec3(-0.5f,  0.5f,  0.5f),

				glm::vec3(0.5f,  0.5f,  0.5f),
				glm::vec3(0.5f, -0.5f, -0.5f),
				glm::vec3(0.5f,  0.5f, -0.5f),
				glm::vec3(0.5f, -0.5f, -0.5f),
				glm::vec3(0.5f,  0.5f,  0.5f),
				glm::vec3(0.5f, -0.5f,  0.5f),

				glm::vec3(-0.5f, -0.5f, -0.5f),
				glm::vec3(0.5f, -0.5f, -0.5f),
				glm::vec3(0.5f, -0.5f,  0.5f),
				glm::vec3(0.5f, -0.5f,  0.5f),
				glm::vec3(-0.5f, -0.5f,  0.5f),
				glm::vec3(-0.5f, -0.5f, -0.5f),

				glm::vec3(-0.5f,  0.5f, -0.5f),
				glm::vec3(0.5f,  0.5f,  0.5f),
				glm::vec3(0.5f,  0.5f, -0.5f),
				glm::vec3(0.5f,  0.5f,  0.5f),
				glm::vec3(-0.5f,  0.5f, -0.5f),
				glm::vec3(-0.5f,  0.5f,  0.5f),
			};
			TexCoords = std::vector<glm::vec2>{
				glm::vec2(0.0f, 0.0f),
				glm::vec2(1.0f, 1.0f),
				glm::vec2(1.0f, 0.0f),
				glm::vec2(1.0f, 1.0f),
				glm::vec2(0.0f, 0.0f),
				glm::vec2(0.0f, 1.0f),

				glm::vec2(0.0f, 0.0f),
				glm::vec2(1.0f, 0.0f),
				glm::vec2(1.0f, 1.0f),
				glm::vec2(1.0f, 1.0f),
				glm::vec2(0.0f, 1.0f),
				glm::vec2(0.0f, 0.0f),

				glm::vec2(1.0f, 0.0f),
				glm::vec2(1.0f, 1.0f),
				glm::vec2(0.0f, 1.0f),
				glm::vec2(0.0f, 1.0f),
				glm::vec2(0.0f, 0.0f),
				glm::vec2(1.0f, 0.0f),

				glm::vec2(1.0f, 0.0f),
				glm::vec2(0.0f, 1.0f),
				glm::vec2(1.0f, 1.0f),
				glm::vec2(0.0f, 1.0f),
				glm::vec2(1.0f, 0.0f),
				glm::vec2(0.0f, 0.0f),

				glm::vec2(0.0f, 1.0f),
				glm::vec2(1.0f, 1.0f),
				glm::vec2(1.0f, 0.0f),
				glm::vec2(1.0f, 0.0f),
				glm::vec2(0.0f, 0.0f),
				glm::vec2(0.0f, 1.0f),

				glm::vec2(0.0f, 1.0f),
				glm::vec2(1.0f, 0.0f),
				glm::vec2(1.0f, 1.0f),
				glm::vec2(1.0f, 0.0f),
				glm::vec2(0.0f, 1.0f),
				glm::vec2(0.0f, 0.0f),
			};
			Normals = std::vector<glm::vec3>{
				glm::vec3(0.0f,  0.0f, -1.0f),
				glm::vec3(0.0f,  0.0f, -1.0f),
				glm::vec3(0.0f,  0.0f, -1.0f),
				glm::vec3(0.0f,  0.0f, -1.0f),
				glm::vec3(0.0f,  0.0f, -1.0f),
				glm::vec3(0.0f,  0.0f, -1.0f),

				glm::vec3(0.0f,  0.0f,  1.0f),
				glm::vec3(0.0f,  0.0f,  1.0f),
				glm::vec3(0.0f,  0.0f,  1.0f),
				glm::vec3(0.0f,  0.0f,  1.0f),
				glm::vec3(0.0f,  0.0f,  1.0f),
				glm::vec3(0.0f,  0.0f,  1.0f),

				glm::vec3(-1.0f,  0.0f,  0.0f),
				glm::vec3(-1.0f,  0.0f,  0.0f),
				glm::vec3(-1.0f,  0.0f,  0.0f),
				glm::vec3(-1.0f,  0.0f,  0.0f),
				glm::vec3(-1.0f,  0.0f,  0.0f),
				glm::vec3(-1.0f,  0.0f,  0.0f),

				glm::vec3(1.0f,  0.0f,  0.0f),
				glm::vec3(1.0f,  0.0f,  0.0f),
				glm::vec3(1.0f,  0.0f,  0.0f),
				glm::vec3(1.0f,  0.0f,  0.0f),
				glm::vec3(1.0f,  0.0f,  0.0f),
				glm::vec3(1.0f,  0.0f,  0.0f),

				glm::vec3(0.0f, -1.0f,  0.0f),
				glm::vec3(0.0f, -1.0f,  0.0f),
				glm::vec3(0.0f, -1.0f,  0.0f),
				glm::vec3(0.0f, -1.0f,  0.0f),
				glm::vec3(0.0f, -1.0f,  0.0f),
				glm::vec3(0.0f, -1.0f,  0.0f),

				glm::vec3(0.0f,  1.0f,  0.0f),
				glm::vec3(0.0f,  1.0f,  0.0f),
				glm::vec3(0.0f,  1.0f,  0.0f),
				glm::vec3(0.0f,  1.0f,  0.0f),
				glm::vec3(0.0f,  1.0f,  0.0f),
				glm::vec3(0.0f,  1.0f,  0.0f),
			};
			Finalize();
	}
	
};
