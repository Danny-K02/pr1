#include "Renderer.h"

#include <iostream>

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << ")" << function <<
			" " << file << ":" << line << std::endl;
		return false;
	}
	return true;
}

void Renderer::__clear() const
{
	GlCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::__draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader, const bool line) const
{
	shader.__bind();
	va.__bind();
	ib.__bind();
	if (line)
	{
		GlCall(glDrawElements(GL_LINES, ib.__get_count(), GL_UNSIGNED_INT, nullptr));
	}
	else
	{

		GlCall(glDrawElements(GL_TRIANGLES, ib.__get_count(), GL_UNSIGNED_INT, nullptr));
	}
}

