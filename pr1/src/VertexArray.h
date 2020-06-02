#pragma once
#include "VertexBuffer.h"

class VertexBufferLayout;

class VertexArray
{
private:
	unsigned int m_RendererID;
public:
	VertexArray();
	//Array binding
	void __bind() const;
	//Array unbinding
	void __unbind() const;
	//Adding buffer to Array
	void __add_buffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	~VertexArray();
};