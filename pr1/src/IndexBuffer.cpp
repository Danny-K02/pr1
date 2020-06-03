#include "IndexBuffer.h"

#include "Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
	:m_Count(count),m_Start(0)
{
	GlCall(glGenBuffers(1, &m_RendererID));
	GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
	GlCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}


IndexBuffer::~IndexBuffer()
{
	GlCall(glDeleteBuffers(1, &m_RendererID));
}



void IndexBuffer::__bind() const
{
	GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void IndexBuffer::__unbind() const
{
	GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void IndexBuffer::__add_data(const void* data, unsigned int count)
{
	GlCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	GlCall(glBufferSubData(GL_ARRAY_BUFFER, m_Start, count * sizeof(unsigned int), data));
	m_Start += count * sizeof(unsigned int);
}
