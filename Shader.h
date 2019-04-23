#pragma once
#ifndef POWER_SHADER_H
#define POWER_SHADER_H

#include<glad/glad.h>

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<vector>
#include"3dmath.h"

class Shader
{
public:
	unsigned int ID;
	Shader()
	{}
	
	Shader(const std::string vertexPath, const std::string fragmentPath)
	{
		
		//vertex shader
		std::string vertexCode;
		std::ifstream vertexFile(vertexPath);
		std::stringstream vertexStream;
		vertexStream << vertexFile.rdbuf();
		vertexCode = vertexStream.str();
		const char* vertexSource = vertexCode.c_str();
		//std::cout << vertexSource << std::endl;
		unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertexSource, NULL); //将着色器源码关联到 shader 对象中
		glCompileShader(vertex); //编译着色器源代码
		int success;
		int LogLength;
		char InfoLog[1024];
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{		
			std::cout << "Vertex Shader Failed to Compile  PATH: "+ vertexPath<< std::endl;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &LogLength);
			std::cout << "Log length=" << LogLength << std::endl;
			glGetShaderInfoLog(vertex, 1024, &LogLength, InfoLog);		
			std::cout << InfoLog << std::endl;
		}		

		//fragment shader
		std::string fragmentCode;
		std::ifstream fragmentFile(fragmentPath);
		std::stringstream fragmentStream;
		fragmentStream << fragmentFile.rdbuf();
		fragmentCode = fragmentStream.str();
		const char* fragmentSource = fragmentCode.c_str();
		std::cout << fragmentSource << std::endl;
		unsigned int fragment= glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragmentSource, NULL);
		glCompileShader(fragment);
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
		
			std::cout << "Fragment Shader Failed to Compile PATH: " +fragmentPath<< std::endl;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &LogLength);
			std::cout << "Log length=" << LogLength << std::endl;
			glGetShaderInfoLog(fragment, 1024, &LogLength, InfoLog);
			std::cout << strlen(InfoLog) << std::endl;
			std::cout << InfoLog << std::endl;
		}

		//Program 
		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);
		
		glGetShaderiv(ID, GL_LINK_STATUS, &success);
		if (!success)
		{			
			std::cout << "Fragment Shader Failed to Compile" << std::endl;
			glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &LogLength);
			std::cout << "Log length=" << LogLength << std::endl;
			glGetShaderInfoLog(ID, 1024, &LogLength, InfoLog);
			

			std::cout << InfoLog << std::endl;
		}
		
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
	
	Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath=nullptr)
	{
		unsigned int geometry;
		//vertex shader
		std::string vertexCode;
		std::ifstream vertexFile(vertexPath);
		std::stringstream vertexStream;
		vertexStream << vertexFile.rdbuf();
		vertexCode = vertexStream.str();
		const char* vertexSource = vertexCode.c_str();
		//std::cout << vertexSource << std::endl;
		unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertexSource, NULL); //将着色器源码关联到 shader 对象中
		glCompileShader(vertex); //编译着色器源代码
		int success;
		int LogLength;
		char InfoLog[1024];
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			std::cout << "Vertex Shader Failed to Compile  PATH: " << vertexPath << std::endl;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &LogLength);
			std::cout << "Log length=" << LogLength << std::endl;
			glGetShaderInfoLog(vertex, 1024, &LogLength, InfoLog);
			std::cout << InfoLog << std::endl;
		}

		//fragment shader
		std::string fragmentCode;
		std::ifstream fragmentFile(fragmentPath);
		std::stringstream fragmentStream;
		fragmentStream << fragmentFile.rdbuf();
		fragmentCode = fragmentStream.str();
		const char* fragmentSource = fragmentCode.c_str();
		//std::cout << fragmentSource << std::endl;
		unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragmentSource, NULL);
		glCompileShader(fragment);
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{

			std::cout << "Fragment Shader Failed to Compile PATH: " << fragmentPath << std::endl;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &LogLength);
			std::cout << "Log length=" << LogLength << std::endl;
			glGetShaderInfoLog(fragment, 1024, &LogLength, InfoLog);
			std::cout << strlen(InfoLog) << std::endl;
			std::cout << InfoLog << std::endl;
		}
		// geometry shader
		if (geometryPath !=nullptr)
		{
			std::string geometryCode;
			std::ifstream geometryFile(geometryPath);
			std::stringstream geometryStream;
			geometryStream << geometryFile.rdbuf();
			geometryCode = geometryStream.str();
			const char* geometrySource = geometryCode.c_str();
			geometry = glCreateShader(GL_GEOMETRY_SHADER);
			glShaderSource(geometry, 1, &geometrySource, NULL);
			glCompileShader(geometry);
			glGetShaderiv(geometry, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				std::cout << "Geometry Shader Failed to Compile PATH: " << geometryPath << std::endl;
				glGetShaderiv(geometry, GL_INFO_LOG_LENGTH, &LogLength);
				std::cout << "Log length=" << LogLength << std::endl;
				glGetShaderInfoLog(geometry, 1024, &LogLength, InfoLog);
				std::cout << strlen(InfoLog) << std::endl;
				std::cout << InfoLog << std::endl;
			}
		}


		//Program 
		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		if (geometryPath != nullptr)
			glAttachShader(ID, geometry);
		glLinkProgram(ID);

		glGetShaderiv(ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			std::cout << "Fragment Shader Failed to Compile" << std::endl;
			glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &LogLength);
			std::cout << "Log length=" << LogLength << std::endl;
			glGetShaderInfoLog(ID, 1024, &LogLength, InfoLog);


			std::cout << InfoLog << std::endl;
		}
		glDeleteShader(vertex);	
		glDeleteShader(fragment);
		if(geometryPath!=nullptr)
			glDeleteShader(geometry);
	}

	void use()
	{
		glUseProgram(ID);
	}
	
	void hasProgram()
	{
		if (glIsProgram(ID))      //shader 是否存在
		{
			std::cout << "has program" << std::endl;
		}
	}
	void SetInt(std::string location, int value)
	{
		int loc = glGetUniformLocation(ID,location.c_str());
	
		if (loc >= 0)
			glUniform1i(loc, value);
	}
	// --------------------------------------------------------------------------------------------
	void SetBool(std::string location, bool value)
	{
		int loc = glGetUniformLocation(ID,location.c_str());
		if (loc >= 0)
			glUniform1i(loc, (int)value);
	}
	// --------------------------------------------------------------------------------------------
	void SetFloat(std::string location, float value)
	{
		int loc = glGetUniformLocation(ID,location.c_str());
		if (loc >= 0)
			glUniform1f(loc, value);
	}
	// --------------------------------------------------------------------------------------------
	void SetVector(std::string location, math::vec2 value)
	{
		int loc = glGetUniformLocation(ID,location.c_str());
		if (loc >= 0)
			glUniform2fv(loc, 1, &value[0]);
	}
	// --------------------------------------------------------------------------------------------
	void SetVector(std::string location, math::vec3 value)
	{
		int loc = glGetUniformLocation(ID,location.c_str());
		if (loc >= 0)
			glUniform3fv(loc, 1, &value[0]);
	}
	// --------------------------------------------------------------------------------------------
	void SetVector(std::string location, math::vec4 value)
	{
		int loc = glGetUniformLocation(ID,location.c_str());
		if (loc >= 0)
			glUniform4fv(loc, 1, &value[0]);
	}
	// --------------------------------------------------------------------------------------------
	void SetVectorArray(std::string location, int size, const std::vector<math::vec2> & values)
	{
		unsigned int loc = glGetUniformLocation(ID, location.c_str());
		if (loc >= 0)
		{
			glUniform2fv(loc, size, (float*)(&values[0].x));
		}
	}
	// --------------------------------------------------------------------------------------------
	void SetVectorArray(std::string location, int size, const std::vector<math::vec3> & values)
	{
		unsigned int loc = glGetUniformLocation(ID, location.c_str());
		if (loc >= 0)
		{
			glUniform3fv(loc, size, (float*)(&values[0].x));
		}
	}
	// --------------------------------------------------------------------------------------------
	void SetVectorArray(std::string location, int size, const std::vector<math::vec4> & values)
	{
		unsigned int loc = glGetUniformLocation(ID, location.c_str());
		if (loc >= 0)
		{
			glUniform4fv(loc, size, (float*)(&values[0].x));
		}
	}
	// --------------------------------------------------------------------------------------------
	void SetMatrix(std::string location, math::mat2 value)
	{
		int loc = glGetUniformLocation(ID,location.c_str());
		if (loc >= 0)
			glUniformMatrix2fv(loc, 1, GL_FALSE, &value[0][0]);
	}
	// --------------------------------------------------------------------------------------------
	void SetMatrix(std::string location, math::mat3 value)
	{
		int loc = glGetUniformLocation(ID,location.c_str());
		if (loc >= 0)
			glUniformMatrix3fv(loc, 1, GL_FALSE, &value[0][0]);
	}
	// --------------------------------------------------------------------------------------------
	void SetMatrix(std::string location, math::mat4 value)
	{
		int loc = glGetUniformLocation(ID,location.c_str());
		if (loc >= 0)
			glUniformMatrix4fv(loc, 1, GL_FALSE, &value[0][0]);
	}




};





#endif // !POWER_SHADER_H
