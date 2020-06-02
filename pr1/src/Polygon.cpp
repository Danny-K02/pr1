#include "Polygon.h"



Polygon::Polygon()
{

}

Polygon::Polygon(unsigned int i0, unsigned int i1, unsigned int i2)
{
	indicies[0] = i0;
	indicies[1] = i1;
	indicies[2] = i2;
	IndexBuffer ibs(indicies, 3);
	ib = &ibs;
}
Polygon::~Polygon()
{
}
