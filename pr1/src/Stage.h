#pragma once
#include "GL/glew.h"
#include <GLFW/glfw3.h>

#include <map>

#include "Object.h"
class Stage {
public:
	GLFWwindow* window = NULL;
	//Initialization of OpenGL
	void __init();
	//Adding objects to Stage
	//void __add_to_Stage(Object* Obj);
	//Deleting objects from Stage
	void __delete_from_Stage(unsigned int id);
	//Objects list
	//std::map<unsigned int, Object>Objects;
	//
	
};


