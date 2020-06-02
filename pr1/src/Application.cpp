#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#include "Object.h"
#include "Stage.h"
#include "Square.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"


const double PI = 3.141592653589793;


int main(void)
{
	Stage MainStage;
	MainStage.__init();
	const char* glsl_version = "#version 150";
	unsigned int ind[] =
	{
		0,1,5,
		5,4,0
	};
	unsigned int lind[] =
	{
		0,1,
		0,4,
		4,5,
		1,5
	};
	Square sq;
	//VertexArray
	VertexArray va;
	//Buffer with coordinates
	VertexBuffer vb(sq.positions, 24);

	VertexBufferLayout layout;
	layout.__push<float>(3);
	va.__add_buffer(vb, layout);

	IndexBuffer ib(ind, 6);
	IndexBuffer line(lind, 8);


	glm::mat4 proj = glm::ortho(0.0f, 800.0f, 0.0f, 800.0f, -1.0f, 1.0f);
	

	Shader shader("res/shaders/Basic.shader");
	shader.__bind();
	shader.__set_uniform4f("u_Color", 0.8f, 0.3f, 0.5f, 1.0f);

	va.__unbind();
	vb.__unbind();
	ib.__unbind();
	line.__unbind();
	shader.__unbind();

	Renderer renderer;
	
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(MainStage.window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	unsigned int type;
	glm::vec3 scaling(1, 1, 1);
	glm::vec3 cameraTranslation(0, 0, 0);
	glm::vec3 translation(0, 0, 0);
	glm::vec2 buttonSize(50, 30);
	float colors[] = { 0.0f,0.0f,0.0f };
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(MainStage.window))
	{
		/* Render here */
		renderer.__clear();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		{
			glm::mat4 view = glm::translate(glm::mat4(1.0f), cameraTranslation);
			glm::mat4 modelt = glm::translate(glm::mat4(1.0f), translation);
			glm::mat4 models = glm::scale(glm::mat4(1.0f), scaling);
			glm::mat4 mvp = proj * view * modelt  * models;
			shader.__bind();
			shader.__set_uniform4f("u_Color", colors[0], colors[1], colors[2], 1.0f);
			shader.__set_uniformMat4f("u_MVP", mvp);

			renderer.__draw(va, ib, shader, 0);
		}

		shader.__set_uniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);

		renderer.__draw(va, line, shader,1);
		if (ImGui::Button("Square"))
			type = 1;
		if (ImGui::Button("Triangle"))
			type = 2;

		ImGui::SliderFloat2("Scaling", &scaling.x, 1.0f, 10.0f);
		ImGui::SliderFloat2("Translation", &translation.x, 0.0f, 800.0f);
		ImGui::SliderFloat2("Camera translation", &cameraTranslation.x, -800.0f, 800.0f);
		ImGui::SliderFloat3("Colors", &colors[0], -0.0f, 1.0f);
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(MainStage.window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		/* Swap front and back buffers */
		glfwSwapBuffers(MainStage.window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}