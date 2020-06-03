#pragma once
class Triangle
{
public:
	float positions[6] =
	{
		 -50.f,	-50.f,
		  50.f,	-50.f,
		  0.f,	 50.f
	};
	unsigned int ind[3] =
	{
		4,5,6
	};
	unsigned int lind[6] =
	{
		4,5,
		4,6,
		5,6
	};
public:
	Triangle();
	~Triangle();
};