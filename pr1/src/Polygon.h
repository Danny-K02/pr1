#pragma once
#include "IndexBuffer.h"
//Polygon class
//The simplest part of object
class Polygon {
private:
	//Buffer with indices
	IndexBuffer *ib;
	//Massive with indices
	unsigned int indicies[3] = { 0,0,0 };
public:
	Polygon();
	Polygon(unsigned int i0, unsigned int i1, unsigned int i2);
	IndexBuffer __get_ib() { return *ib; }
	~Polygon();
};