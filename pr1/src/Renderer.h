#pragma once

#include <GL/glew.h>
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GlCall(x) GLClearError();\
x;\
ASSERT (GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

class Renderer
{
private:

public:
	void __clear() const;
	void __draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader, const bool line) const;
};