#pragma once

class VertexBuffer
{
private: 
	unsigned int m_RendererID;
	unsigned int m_Size;
	unsigned int m_Start;
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();
	void __bind() const;
	void __unbind() const;
	void __add_data(const void* data, unsigned int size) ;
};