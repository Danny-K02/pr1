#pragma once

#include <vector>
#include <GL/glew.h>
#include "Renderer.h"
struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalised;
	//Sizes of types
	static unsigned int __get_size_of_type(unsigned int type)
	{
		switch (type)
		{
			case GL_FLOAT:		   	 return 4;
			case GL_UNSIGNED_INT:	 return 4;
			case GL_UNSIGNED_BYTE:	 return 1;
		}
		ASSERT(false)
		return 0;
	}
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
public:
	VertexBufferLayout()
		:m_Stride(0){}

	template <typename T>
	void __push(unsigned int count)
	{
		static_assert(false);
	}

	template<>
	void __push<float>(unsigned int count)
	{
		m_Elements.push_back({ GL_FLOAT,count,GL_FALSE });
		m_Stride += count * VertexBufferElement::__get_size_of_type(GL_FLOAT);
	}
	template<>
	void __push<unsigned int>(unsigned int count)
	{
		m_Elements.push_back({ GL_UNSIGNED_INT,count,GL_FALSE });
		m_Stride += count * VertexBufferElement::__get_size_of_type(GL_UNSIGNED_INT);
	}
	template<>
	void __push<unsigned char>(unsigned int count)
	{
		m_Elements.push_back({ GL_UNSIGNED_BYTE,count,GL_TRUE });
		m_Stride += count * VertexBufferElement::__get_size_of_type(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VertexBufferElement> __Get_Elements() const { return m_Elements; }
	inline unsigned int __Get_Stride() const { return m_Stride; }
};