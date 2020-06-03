#pragma once
#include "Object.h"

class Square:public Object
{
public:
	float positions[8] =
	{
		 -50.0f,	-50.0f,	
		  50.0f,	-50.0f,	
		  50.0f,	 50.0f,	 
		 -50.0f,	 50.0f,	 
	};
	unsigned int ind[6] =
	{
		0,1,2,
		2,3,0
	};
	unsigned int lind[8] =
	{
		0,1,
		0,3,
		2,1,
		2,3
	};
public:
	Square();
	~Square();
};