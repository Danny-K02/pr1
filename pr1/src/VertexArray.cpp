#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Renderer.h"
VertexArray::VertexArray()
{
	GlCall(glGenVertexArrays(1, &m_RendererID));
	GlCall(glBindVertexArray(m_RendererID))
}

void VertexArray::__bind() const
{
	GlCall(glBindVertexArray(m_RendererID);)
}

void VertexArray::__unbind() const
{
	GlCall(glBindVertexArray(0));
}

void VertexArray::__add_buffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	__bind();
	vb.__bind();
	const auto& elements = layout.__Get_Elements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		GlCall(glEnableVertexAttribArray(i));
		GlCall(glVertexAttribPointer(i, element.count, element.type,
			element.normalised, layout.__Get_Stride(), (const void*)offset));
		offset += element.count * VertexBufferElement::__get_size_of_type(element.type);
	}
}

VertexArray::~VertexArray()
{
	GlCall(glDeleteVertexArrays(1, &m_RendererID));
}
