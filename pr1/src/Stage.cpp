#include "Stage.h"
#include <iostream>

void Stage::__init()
{
	/* Initialize the library */
	if (!glfwInit())
		std::cout << "ErrorGLFW!" << std::endl;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 800, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
		std::cout << "Error" << std::endl;
}
//
//void Stage::__add_to_Stage(Object* Obj)
//{
//}

void Stage::__delete_from_Stage(unsigned int id)
{
}
