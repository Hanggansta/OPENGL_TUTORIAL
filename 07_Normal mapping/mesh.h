#pragma once
#include<glad/glad.h>
#include<iostream>
#include<vector>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>

class Mesh
{
public:
	unsigned int m_VAO, m_VBO, m_EBO;
	std::vector<glm::vec3>Positions;
	std::vector<glm::vec2>TexCoords;
	std::vector<glm::vec3>Normals;
	std::vector <glm::vec3>Tangents;
	std::vector<glm::vec3>Bitangents;
	std::vector<unsigned int> Indices;

	Mesh()
	{}
	Mesh(std::vector<glm::vec3>positions,std::vector<unsigned int>indices)
	{
		Positions = positions;
		Indices = indices;
	}
	Mesh(std::vector<glm::vec3>positions,std::vector<glm::vec2> uv, std::vector<unsigned int>indices)
	{
		Positions = positions;
		TexCoords = uv;
		Indices = indices;
	}
	Mesh(std::vector<glm::vec3>positions, std::vector <glm::vec2>uv,std::vector<glm::vec3>normals, std::vector<unsigned int>indices)
	{
		Positions = positions;
		Normals = normals;
		TexCoords = uv;
		Indices = indices;
	}
	Mesh(std::vector<glm::vec3>positions, std::vector <glm::vec2>uv,std::vector<glm::vec3>normals,std::vector<glm::vec3>tangents,std::vector<glm::vec3>bitangents, std::vector<unsigned int>indices)
	{
		Positions = positions;
		Normals = normals;
		TexCoords = uv;
		Tangents = tangents;
		Bitangents = bitangents;
		Indices = indices;
	}
	void Finalize(bool interleaved=true)
	{
		// initialize object IDs if not configured before
		if (!m_VAO)
		{
			glGenVertexArrays(1, &m_VAO);
			glGenBuffers(1, &m_VBO);
			glGenBuffers(1, &m_EBO);
		}

		// preprocess buffer data as interleaved or seperate when specified
		std::vector<float> data;
		if (interleaved)
		{
			for (int i = 0; i < Positions.size(); ++i)
			{
				data.push_back(Positions[i].x);
				data.push_back(Positions[i].y);
				data.push_back(Positions[i].z);
				if (TexCoords.size() > 0)
				{
					data.push_back(TexCoords[i].x);
					data.push_back(TexCoords[i].y);
				}
				if (Normals.size() > 0)
				{
					data.push_back(Normals[i].x);
					data.push_back(Normals[i].y);
					data.push_back(Normals[i].z);
				}
				if (Tangents.size() > 0)
				{
					data.push_back(Tangents[i].x);
					data.push_back(Tangents[i].y);
					data.push_back(Tangents[i].z);
				}
				if (Bitangents.size() > 0)
				{
					data.push_back(Bitangents[i].x);
					data.push_back(Bitangents[i].y);
					data.push_back(Bitangents[i].z);
				}
			}
		}
		else
		{
			// if any of the float arrays are empty, data won't be filled by them.
			for (int i = 0; i < Positions.size(); ++i)
			{
				data.push_back(Positions[i].x);
				data.push_back(Positions[i].y);
				data.push_back(Positions[i].z);
			}
			for (int i = 0; i < TexCoords.size(); ++i)
			{
				data.push_back(TexCoords[i].x);
				data.push_back(TexCoords[i].y);
			}
			for (int i = 0; i < Normals.size(); ++i)
			{
				data.push_back(Normals[i].x);
				data.push_back(Normals[i].y);
				data.push_back(Normals[i].z);
			}
			for (int i = 0; i < Tangents.size(); ++i)
			{
				data.push_back(Tangents[i].x);
				data.push_back(Tangents[i].y);
				data.push_back(Tangents[i].z);
			}
			for (int i = 0; i < Bitangents.size(); ++i)
			{
				data.push_back(Bitangents[i].x);
				data.push_back(Bitangents[i].y);
				data.push_back(Bitangents[i].z);
			}
		}

		// configure vertex attributes (only on vertex data size() > 0)
		glBindVertexArray(m_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
		// only fill the index buffer if the index array is non-empty.
		if (Indices.size() > 0)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(unsigned int), &Indices[0], GL_STATIC_DRAW);
		}
		if (interleaved)
		{
			// calculate stride from number of non-empty vertex attribute arrays
			size_t stride = 3 * sizeof(float);
			if (TexCoords.size() > 0)         stride += 2 * sizeof(float);
			if (Normals.size() > 0)    stride += 3 * sizeof(float);
			if (Tangents.size() > 0)   stride += 3 * sizeof(float);
			if (Bitangents.size() > 0) stride += 3 * sizeof(float);

			size_t offset = 0;
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid*)offset);
			offset += 3 * sizeof(float);
			if (TexCoords.size() > 0)
			{
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (GLvoid*)offset);
				offset += 2 * sizeof(float);
			}
			if (Normals.size() > 0)
			{
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid*)offset);
				offset += 3 * sizeof(float);
			}
			if (Tangents.size() > 0)
			{
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid*)offset);
				offset += 3 * sizeof(float);
			}
			if (Bitangents.size() > 0)
			{
				glEnableVertexAttribArray(4);
				glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid*)offset);
				offset += 3 * sizeof(float);
			}
		}
		else
		{
			size_t offset = 0;
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)offset);
			offset += Positions.size() * sizeof(float);
			if (TexCoords.size() > 0)
			{
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)offset);
				offset += TexCoords.size() * sizeof(float);
			}
			if (Normals.size() > 0)
			{
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)offset);
				offset += Normals.size() * sizeof(float);
			}
			if (Tangents.size() > 0)
			{
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)offset);
				offset += Tangents.size() * sizeof(float);
			}
			if (Bitangents.size() > 0)
			{
				glEnableVertexAttribArray(4);
				glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)offset);
				offset += Bitangents.size() * sizeof(float);
			}
		}
		glBindVertexArray(0);
	}

	void Release()
	{
		//资源没有必要继续使用则把他们释放出去
		if (!m_VAO)
			glDeleteVertexArrays(1, &m_VAO);
		if (!m_VBO)
			glDeleteBuffers(1, &m_VBO);
		if (!m_EBO)
			glDeleteBuffers(1, &m_EBO);
	}

	void Draw()
	{
		//绘制    如果有索引数据则使用索引绘制，
		// 如果没有索引数据 则使用 顶点绘制
		//TODO: 根据不同的图元 绘制
		glBindVertexArray(m_VAO);
		if (Indices.size() > 0)
		{			
			glDrawElements(GL_ELEMENT_ARRAY_BUFFER, Indices.size(), GL_UNSIGNED_INT, 0);
		}
		else
		{
			glDrawArrays(GL_TRIANGLES, 0, Positions.size());
		}
		glBindVertexArray(0);
	
	}


	void CalculateTangents()
	{
		//http://www.opengl-tutorial.org/cn/intermediate-tutorials/tutorial-13-normal-mapping/   
		//http://ogldev.atspace.co.uk/www/tutorial26/tutorial26.html
		// 关键公式如下
		// deltaPos1 = deltaUV1.x * T + deltaUV1.y * B
		//	deltaPos2 = deltaUV2.x * T + deltaUV2.y * B
		for (int i = 0; i < Positions.size(); i += 3) {

			// Shortcuts for vertices
			glm::vec3& v0 = Positions[i + 0];
			glm::vec3& v1 = Positions[i + 1];
			glm::vec3& v2 = Positions[i + 2];

			// Shortcuts for UVs
			glm::vec2& uv0 = TexCoords[i + 0];
			glm::vec2& uv1 = TexCoords[i + 1];
			glm::vec2& uv2 = TexCoords[i + 2];

			// Edges of the triangle : postion delta
			glm::vec3 deltaPos1 = v1 - v0;
			glm::vec3 deltaPos2 = v2 - v0;

			// UV delta
			glm::vec2 deltaUV1 = uv1 - uv0;
			glm::vec2 deltaUV2 = uv2 - uv0;

			float r = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV1.y * deltaUV2.x);
			glm::vec3 tangent = glm::normalize((deltaPos1 * deltaUV2.y - deltaPos2 * deltaUV1.y) * r);
			glm::vec3 bitangent = glm::normalize((deltaPos2 * deltaUV1.x - deltaPos1 * deltaUV2.x) * r);

			Tangents.push_back(tangent);
			Tangents.push_back(tangent);
			Tangents.push_back(tangent);

			// Same thing for binormals
			Bitangents.push_back(bitangent);
			Bitangents.push_back(bitangent);
			Bitangents.push_back(bitangent);
		}

	}

	void CalculateNormals()
	{
		
	
	
	}


};