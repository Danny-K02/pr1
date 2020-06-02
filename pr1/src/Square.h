#pragma once
#include "Object.h"
#include "Polygon.h"
class Square:public Object
{
public:
	float positions[24] =
	{
		 -50.0f,	-50.0f,	 0.5f,
		  50.0f,	-50.0f,	 0.5f,
		  50.0f,	-50.0f,	-0.5f,
		 -50.0f,	-50.0f,	-0.5f,

		 -50.0f,	 50.0f,	 0.5f,
		  50.0f,	 50.0f,	 0.5f,
		  50.0f,	 50.0f,	-0.5f,
		 -50.0f,	 50.0f,	-0.5f,
	};
	unsigned int ind[36] =
	{
		0,1,2,
		2,3,0,
		4,5,6,
		6,7,4,
		0,1,5,
		5,4,0,
		2,3,7,
		7,6,2,
		1,2,6,
		6,5,1,
		3,0,4,
		4,7,3
	};
	unsigned int lind[24] =
	{
		0,1,
		0,3,
		0,4,
		1,2,
		1,5,
		2,3,
		2,6,
		3,7,
		4,7,
		4,5,
		5,6,
		6,7
	};
public:
	Square();
	~Square();
};