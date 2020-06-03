#pragma once

class IndexBuffer
{
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
	unsigned int m_Start;
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void __bind() const;
	void __unbind() const;

	void __add_data(const void* data, unsigned int count);
	inline unsigned int __get_count() const { return m_Count; };
};