#pragma once
#include"Shader.h"
#include"texture.h"
#include"Primitive.h"

std::vector<std::string> one
{
	"right.jpg",
	"left.jpg",
	"top.jpg",
	"bottom.jpg",
	"front.jpg",
	"back.jpg"
};


class Skybox
{
public:
	Cube *skybox;
	Shader *shader;
	unsigned int CubemapTexture;

	Skybox()
	{
		skybox = new Cube;
		CubemapTexture = LoadCubeMap(one);
		shader = new Shader("CubeMapping.vert", "CubeMapping.frag");
		shader->use();
		shader->setInt("skybox", 0);
		
	    
	
	}

	void Draw(glm::mat4 projection,glm::mat4 view)
	{
		glDepthFunc(GL_LEQUAL);
		shader->use();
		shader->setMat4("projection", projection);
		shader->setMat4("view", view);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, CubemapTexture);
		
		skybox->Draw();
		glDepthFunc(GL_LESS);
		



	}

};

