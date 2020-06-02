#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Renderer.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


Shader::Shader(const std::string& filepath)
	:m_FilePath(filepath), m_RendererID(0)
{
	ShaderProgramSource source = __parse_shader(filepath);
	m_RendererID = __create_shader(source.VertexSource, source.FragmentSource);
}

ShaderProgramSource Shader::__parse_shader(const std::string& filepath)
{
	std::ifstream stream(filepath);

	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};


	std::stringstream ss[2];
	std::string line;
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else
		{
			ss[(int)type] << line << "\n";
		}
	}
	return{ ss[0].str(),ss[1].str() };
}

unsigned int Shader::__compile_shader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int lenght;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
		char* message = (char*)_malloca(lenght * sizeof(char));
		glGetShaderInfoLog(id, lenght, &lenght, message);
		std::cout << "Failed to compile" <<
			(type == GL_VERTEX_SHADER ? "vertex" : "fragment")
			<< " shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

unsigned int Shader::__create_shader(const std::string& vertexShader, const std::string fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = __compile_shader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = __compile_shader(GL_FRAGMENT_SHADER, fragmentShader);
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}
Shader::~Shader()
{
	GlCall(glDeleteProgram(m_RendererID));
}

void Shader::__bind() const
{
	GlCall(glUseProgram(m_RendererID));
}

void Shader::__unbind() const
{
	GlCall(glUseProgram(0));
}

void Shader::__set_uniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	GlCall(glUniform4f(__get_uniform_location(name), v0, v1, v2, v3));
}
void Shader::__set_uniformMat4f(const std::string& name, const glm::mat4& matrix)
{
	GlCall(glUniformMatrix4fv(__get_uniform_location(name), 1, GL_FALSE, &matrix[0][0]));
}
unsigned int Shader::__get_uniform_location(const std::string& name)
{
	if (m_UniformLocationCahe.find(name) != m_UniformLocationCahe.end())
		return m_UniformLocationCahe[name];
	GlCall(int location=glGetUniformLocation(m_RendererID, name.c_str()));
	if (location == -1)
		std::cout << "Warning: uniform " << name << " doesn't exist!" << std::endl;
	m_UniformLocationCahe[name] = location;
	return location;
}