#pragma once
#include"mesh.h"


class Cube :public Mesh
{
public:
	Cube(bool TangentSpace=false)
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
		if (TangentSpace)
			CalculateTangents();

		Finalize();	
	}


};



class Quad :public Mesh
{
public:
	Quad(float TangentSpace=false)
	{
		Positions =
		{
			{ -1.0f,  1.0f, 0.0f, },
			{ -1.0f, -1.0f, 0.0f, },
			{  1.0f,  1.0f, 0.0f, },
			{  1.0f, -1.0f, 0.0f, },
		};
		TexCoords = {
			{ 0.0f, 1.0f, },
			{ 0.0f, 0.0f, },
			{ 1.0f, 1.0f, },
			{ 1.0f, 0.0f, },
		};
		Normals = {
			{0.0f,0.0f,1.0f},
			{0.0f,0.0f,1.0f},
			{0.0f,0.0f,1.0f},
			{0.0f,0.0f,1.0f},
		};

		if (TangentSpace)
			CalculateTangents();
		Finalize();
    }
	Quad(float width, float height,float TangentSpace=false)
	{
		Positions =
		{
			{ -width,  height, 0.0f, },
			{ -width, -height, 0.0f, },
			{  width,  height, 0.0f, },
			{  width, -height, 0.0f, },
		};
		TexCoords = {
			{ 0.0f, 1.0f, },
			{ 0.0f, 0.0f, },
			{ 1.0f, 1.0f, },
			{ 1.0f, 0.0f, },
		};
		if (TangentSpace)
			CalculateTangents();
		Finalize();
	
	
	}



};