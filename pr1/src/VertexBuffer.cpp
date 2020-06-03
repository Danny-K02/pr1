#include "VertexBuffer.h"

#include "Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
	:m_Size(size),m_Start(0)
{
	GlCall(glGenBuffers(1, &m_RendererID));
	GlCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	GlCall(glBufferData(GL_ARRAY_BUFFER, size*4, data, GL_STATIC_DRAW));
}



VertexBuffer::~VertexBuffer()
{
	GlCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::__bind() const
{
	GlCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::__unbind()const
{
	GlCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void VertexBuffer::__add_data(const void* data,unsigned int size)
{
	GlCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	GlCall(glBufferSubData(GL_ARRAY_BUFFER, m_Start, size, data));
	m_Start += size;
}
