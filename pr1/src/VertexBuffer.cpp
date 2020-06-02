#include "VertexBuffer.h"

#include "Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	m_Size = size;
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

void VertexBuffer::__change_data(const void* data,unsigned int size)
{
	GlCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	GlCall(glBufferSubData(GL_ARRAY_BUFFER, 0, size, data));
}
