//#include<glad/glad.h>
//#include<glfw3.h>
//#include<fstream>
//#include<iostream>
//#include <string>
//
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"
//#include "Shader.h"
//#include "Texture.h"
//
//
//
//
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window) {
//
//
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
//		
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
//		
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
//		
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
//		
//	}
//
//
//	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
//
//	}
//
//}
//
//
//
//
//int main() {
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//
//
//	GLFWwindow* window = glfwCreateWindow(800, 600, "Learn", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//
//		return -1;
//
//	}
//
//
//
//	glViewport(0, 0, 800, 600);
//
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//
////	Texture tex = Texture("container.jpg", GL_TEXTURE_2D);
//
//
//
//
//
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//
//
//	Shader coreProgram("vertex1.glsl", "fragment1.glsl");
//	coreProgram.use();
//
//
//	float vertices[] = {
//
//		-0.5f,   -0.5f, 0.0f,  1.f, 0.0f,0.0f, 
//		0.5f,   -0.5f, 0.0f,  1.f, 0.0f,0.0f,  
//		0.0f,  0.5f, 0.0f,  1.f, 0.0f,0.0f
//
//
//
//	};
//
//
//
//
//
//	unsigned int indices[] = {
//
//		0,1,2
//
//	};
//
//	
//
//
//	unsigned int VAO, VBO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//
//
//
//
//	glBindVertexArray(0);
//
//
//	while (!glfwWindowShouldClose(window)) {
//
//		processInput(window);
//
//		glClearColor(0.0f / 255.f, 0.0f / 255.f, 0.0f / 255.f, 1);
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//		coreProgram.use();
//
//
//		glBindVertexArray(VAO);
//
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//
//
//
//	}
//
//
//
//
//	glfwTerminate();
//
//
//	return 0;
//
//}
//
