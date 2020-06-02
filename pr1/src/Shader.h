#pragma once
#include <string>
#include <unordered_map>
#include "glm/glm.hpp"
//Shader container
struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};
//Shader program class
class Shader
{
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	
	unsigned int		 __get_uniform_location (const std::string & name);
	//Loading shader
	unsigned int		 __compile_shader		(unsigned int type, const std::string& source);
	unsigned int		 __create_shader		(const std::string& vertexShader, const std::string fragmentShader);
	ShaderProgramSource  __parse_shader			(const std::string& filepath);
	std::unordered_map<std::string, int> m_UniformLocationCahe;

public:
	Shader(const std::string& filepath);
	~Shader();
	//Binding shader
	void __bind() const;
	//Unbinding shader
	void __unbind() const;
	//Set color
	void __set_uniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void __set_uniformMat4f(const std::string& name, const glm::mat4& matrix);
};