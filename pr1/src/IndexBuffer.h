#pragma once

class IndexBuffer
{
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void __bind() const;
	void __unbind() const;

	inline unsigned int __get_count() const { return m_Count; };
};