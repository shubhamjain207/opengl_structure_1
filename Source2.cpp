#include<glad/glad.h>
#include<glfw3.h>
#include<fstream>
#include<iostream>
#include <string>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Shader.h"
#include "Texture.h"
#include "Material.h"
#include "Mesh.h"
#include "Vertex.h"


float posX = 0.0f, posY = 0.0f, posZ = 4.0f;
float count = 0;
float _count = 0.02;

float _radius = 40.0f;

float rotOnY = 0.0f;




void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window, Mesh mesh) {


	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		//_radius -= 0.5;
		/*posZ -= 0.01f;*/
	//	_radius += 1.0f;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		/*count-=_count;
		_count += 0.00001;*/
		//count -= 0.1;

		//rotOnY += 0.1f;


		mesh.move(glm::vec3(1.0f,0.0f,0.0f));
		

		//count -= 0.01;

	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		//_radius += 0.5;
		//posZ += 0.01f;

	//	_radius -= 1.0f;
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		/*count+= _count;
		_count += 0.00001;*/
		//count += 0.1;

		//rotOnY -= 0.1f;
		//count += 0.01;
	}


	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {

	}

}

//bool loadShaders(GLuint& program) {
//
//	bool loadSuccess = true;
//
//
//	char infoLog[512];
//	GLint success;
//
//
//	std::string temp = "";
//	std::string src = "";
//
//	std::ifstream in_File;
//
//	//Vertex-------->
//
//
//	in_File.open("vertex.glsl");
//
//	if (in_File.is_open()) {
//		while (std::getline(in_File, temp)) {
//			src += temp + "\n";
//		}
//	}
//	else {
//		std::cout << "CANNOT OPEN VERTEX SHADER FILE";
//	}
//
//	in_File.close();
//
//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//
//	const GLchar* vertSrc = src.c_str();
//	glShaderSource(vertexShader, 1, &vertSrc, NULL);
//	glCompileShader(vertexShader);
//
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(vertexShader,512,NULL,infoLog);
//		std::cout << "CANNOT Compile VERTEX SHADER FILE";
//		std::cout << infoLog;
//	}
//
//	in_File.close();
//
//	temp = "";
//	src = "";
//
//	
//
//
//	//Fragment-------->
//
//
//	in_File.open("fragment.glsl");
//
//	if (in_File.is_open()) {
//		while (std::getline(in_File, temp)) {
//			src += temp + "\n";
//		}
//	}
//	else {
//		std::cout << "CANNOT OPEN Fragment SHADER FILE";
//	}
//
//	in_File.close();
//
//	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//
//	const GLchar* fragSrc = src.c_str();
//	glShaderSource(fragmentShader, 1, &fragSrc, NULL);
//	glCompileShader(fragmentShader);
//
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		std::cout << "CANNOT Compile Fragment SHADER FILE";
//	}
//
//
//	temp = "";
//	src = "";
//
//	
//	program = glCreateProgram();
//
//	glAttachShader(program, vertexShader);
//	glAttachShader(program, fragmentShader);
//	glLinkProgram(program);
//
//
//	glGetProgramiv(program, GL_LINK_STATUS, &success);
//
//	if (!success) {
//		std::cout << "CANNOT link shaders";
//	}
//
//	glUseProgram(program);
//
//
//	glDeleteShader(fragmentShader);
//	glDeleteShader(vertexShader);
//
//
//
//	return loadSuccess;
//
//}



int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	GLFWwindow* window = glfwCreateWindow(800, 600, "Learn", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);



	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

		return -1;

	}



	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	//unsigned int texture;
	//glGenTextures(1, &texture);
	//glBindTexture(GL_TEXTURE_2D, texture);


	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//// set texture filtering parameters
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//int width, height, nrChannels;

	//unsigned int texture;
	//glGenTextures(1, &texture);
	//glBindTexture(GL_TEXTURE_2D, texture);
	//// set the texture wrapping/filtering options (on the currently bound texture object)
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//// load and generate the texture
	//int width, height, nrChannels;
	//unsigned char* data = stbi_load("wall.jpg", &width, &height, &nrChannels, 0);
	//if (data)
	//{
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	//	glGenerateMipmap(GL_TEXTURE_2D);
	//}
	//else
	//{
	//	std::cout << "Failed to load texture" << std::endl;
	//}
	//stbi_image_free(data);

//	Texture texture0("wall.jpg",GL_TEXTURE_2D);

	/*int height = 0;
	int width = 0;*/

	//unsigned char* image = SOIL_load_image("wall.jpg", &width, &height, NULL, 0);

	/*int width, height, nrChannels;
	std::string a = "resources/container.jpg";
	unsigned char* data = stbi_load(a.c_str(), &width, &height, &nrChannels, 0);

	if (data) {
		std::cout << "fhsal" << std::endl;
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}	
	 */
	/*GLuint texture0;
	 glGenTextures(1, &texture0);
	//glBindTexture(GL_TEXTURE_2D, texture0);*/

	//unsigned int texture;
	//glGenTextures(1, &texture);
	//glBindTexture(GL_TEXTURE_2D, texture);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//// set texture filtering parameters
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



	//stbi_image_free(data);
	
	/*}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}*/


	//glActiveTexture(0);
	//glBindTexture(GL_TEXTURE_2D, 0);

	Texture tex = Texture("container.jpg",GL_TEXTURE_2D,0);

	Material material(glm::vec3(0.1f),glm::vec3(0.f), glm::vec3(10.f),tex.getTextureUnit());


	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

	
	Shader coreProgram("vertex.glsl", "fragment.glsl");
	coreProgram.use();


//	GLuint coreProgram;
	
	
	/*Shader coreProgram("vertex1.glsl", "fragment1.glsl");
	coreProgram.use();*/


	/*if (!loadShaders(coreProgram)) {
		glfwTerminate();
	}*/

	Vertex vertices[] = {

		glm::vec3( - 0.5f,   -0.5f, 0.0f), glm::vec3(1.f, 0.0f,1.0f),   glm::vec2(-0.5f,-0.5f),glm::vec3(0.f, 0.0f,1.0f),
		glm::vec3(0.5f,   -0.5f, 0.0f),     glm::vec3(1.f, 0.0f,0.0f),   glm::vec2(0.5f,   -0.5f), glm::vec3(0.f, 0.0f,1.0f),
		glm::vec3(0.0f,  0.5f, 0.0f),    glm::vec3(1.f, 0.0f,0.0f),    glm::vec2(0.0f,  0.5f), glm::vec3(0.f, 0.0f,1.0f)


		//0.0f,   0.0f, 0.0f, 1.f,0.0f,0.0f, 0.0f,   0.0f,    0.f, 1.0f,0.0f,
		//0.0f,  -1.0f,-0.5f, 1.f,0.0f,0.0f, 0.0f,   -1.0f,    0.f, 1.0f,0.0f,
		//0.0f, -1.0f, 0.5f,  1.f,0.0f,0.0f, 0.0f,   -1.0f,    0.f, 1.0f,0.0f,

		//-0.5f,  0.5f, 0.0f,1.f,0.0f,0.0f,

	};

	unsigned noOfVertices = sizeof(vertices) / sizeof(Vertex);

	float platform[] = {

		0.5f,   0.0f, -0.5f,1.f,0.0f,0.0f,
		0.5f,   0.0f, 0.0f, 1.f,0.0f,0.0f,
		-0.5f,  0.0f, 0.0f,1.f,0.0f,0.0f,



	};


	//float vertices[] = {

	//	0.9f,0.1f,0.0f,  1.f,0.0f,0.0f,
	//	-0.9f,0.8f,0.0f, 0.0f,1.0f,0.0f,
	//	-0.8f,0.8f,0.0f, 0.0f,0.0f,1.0f,
	//	

	//	



	//};

	glm::vec3 cubePositions[] = {
	glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(0.9f,  0.0f, 0.0f),
	glm::vec3(-0.5f, -0.2f, 0.5f),
	glm::vec3(-0.8f, -0.0f, 0.3f),
	glm::vec3(0.4f, -0.4f, 0.5f),
	glm::vec3(-0.7f,  0.0f, 0.5f),
	glm::vec3(0.3f, -0.0f, 0.5f),
	glm::vec3(0.5f,  0.0f, 0.5f),
	glm::vec3(0.5f,  0.2f, 0.5f),
	glm::vec3(-0.3f, 0.0f, 0.5f)
	};

	GLuint indices[] = {
		
		0,1,2,
		3,4,5

	};


	unsigned noOfIndices = sizeof(indices) / sizeof(unsigned int);

	unsigned int indices1[] = {

		0,1,2

	};



	//unsigned nrOf = sizeof(indices) / sizeof(GLuint);


	//float vertices[] = {
	//	-0.5f, -0.5f, -0.5f, 0.5f,  0.5f,  0.5f,
	//	 0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	-0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	-0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,

	//	-0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	-0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	-0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,

	//	-0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	-0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	-0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	-0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	-0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	-0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,

	//	 0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,

	//	-0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	-0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	-0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,

	//	-0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	 0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	-0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
	//	-0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
	//};


	//glm::vec3 cubePositions[] = {
	//		   glm::vec3(0.0f,  0.0f,  0.0f),
	//		   glm::vec3(2.0f,  5.0f, -15.0f),
	//};

	Mesh mesh(vertices, noOfVertices, indices, noOfIndices, glm::vec3(1.f), glm::vec3(1.f), glm::vec3(1.f));

	/*unsigned int VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	
	
	glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11* sizeof(float), (void*)(8 * sizeof(float)));
	glEnableVertexAttribArray(3);



	glBindVertexArray(0);*/



	//unsigned int VAO1;
	//glGenVertexArrays(1, &VAO1);
	//glBindVertexArray(VAO1);

	//glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);

	////coreProgram.use();

	glm::mat4 ProjectionMatrix = glm::perspective(glm::radians(10.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	//coreProgram.setMat4fv(ProjectionMatrix, "ProjectionMatrix");
	GLint projectionMatrix = glGetUniformLocation(coreProgram.getId(), "ProjectionMatrix");
	glUniformMatrix4fv(projectionMatrix, 1, GL_FALSE, glm::value_ptr(ProjectionMatrix));
	
	

	


	while (!glfwWindowShouldClose(window)) {

		processInput(window,mesh);

		glClearColor(0.0f / 255.f, 0.0f / 255.f, 0.0f / 255.f, 1);
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		coreProgram.use();

		

		//glUseProgram(coreProgram);

		//glBindVertexArray(VAO);

		const float radius1 = _radius;
		float camX = static_cast<float>(sin(count) * 40.0f);
		float camZ = static_cast<float>(cos(count) * radius1);

		glm::mat4 ViewMatrix = glm::mat4(1.0f);
		ViewMatrix = glm::lookAt(glm::vec3(camX, 1.0f,camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		coreProgram.setMat4fv(ViewMatrix,"ViewMatrix");

		/*GLint viewMatrix = glGetUniformLocation(coreProgram.getId(), "ViewMatrix");
		glUniformMatrix4fv(viewMatrix, 1, GL_FALSE, glm::value_ptr(ViewMatrix));*/


		material.sendToShader(coreProgram);


		//glm::mat4 model = glm::mat4(1.0f);
		//model = glm::rotate(model, glm::radians(-25.0f), glm::vec3(1.0f, 0.0f, 0.3f));

		//unsigned int modelLoc = glGetUniformLocation(coreProgram, "Model");
		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));



		//glm::mat4 view = glm::mat4(1.0f);
		//float radius = 10.0f;

		//view = glm::lookAt(glm::vec3(posX, posY, posZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		//unsigned int viewLoc = glGetUniformLocation(shaderProgram2, "view");
		//glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));



		//glm::mat4 projection = glm::mat4(1.0f);
		//projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		//unsigned int projectionLoc = glGetUniformLocation(shaderProgram2, "projection");
		//glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

		//glBindVertexArray(VAO);
		///*glDrawArrays(GL_TRIANGLES, 0, 36);*/
		//glUseProgram(shaderProgram2);


		////for (int i = 0; i < 2;i++) {
		////	
		////				
		////	if (i == 0) {


		//glUseProgram(shaderProgram2);

		//glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
		//unsigned int colorLoc = glGetUniformLocation(shaderProgram2, "lightColor");
		//glUniform3fv(colorLoc, 1, glm::value_ptr(color));


		//glm::vec3 color2 = glm::vec3(1.0f, 0.0f, 0.f);
		//unsigned int colorLoc2 = glGetUniformLocation(shaderProgram2, "objectColor");
		//glUniform3fv(colorLoc2, 1, glm::value_ptr(color2));



		////    //}

		//   //else if (i == 1) {

		//   //	glUseProgram(shaderProgram2);

		//   //	glm::vec3 color1 = glm::vec3(0.0f, 1.f, 1.f);
		//   //	unsigned int colorLoc1 = glGetUniformLocation(shaderProgram2, "lightColor");
		//   //	glUniform3fv(colorLoc1, 1, glm::value_ptr(color1));

		//   //	glm::vec3 color2 = glm::vec3(1.0f, 1.0f, 1.f);
		//   //	unsigned int colorLoc2 = glGetUniformLocation(shaderProgram2, "objectColor");
		//   //	glUniform3fv(colorLoc2, 1, glm::value_ptr(color2));
		//   //	

		//   //
		//   //}
		//   //
		//glm::mat4 model = glm::mat4(1.0f);

		///*	model = glm::translate(model, cubePositions[i]);*/

		//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.3f));


		//unsigned int modelLoc = glGetUniformLocation(shaderProgram2, "model");

		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		//for (int i = 0; i < 100; i++) {

		/*	float r = static_cast<float>(rand()) / RAND_MAX;
			float g = static_cast<float>(rand()) / RAND_MAX;
			float b = static_cast<float>(rand()) / RAND_MAX;*/

		//if (count > 255.0f) {
		//	flag = false;
		//}

		//if (count < 0.0f) {
		//	flag = true;
		//}

		//if (count1 > 255.0f) {
		//	count1 = 0.0f;
		//}

		//if (count2 > 255.0f) {
		//	count2 = 0.0f;
		//}


	/*	float r = count / 255.0f;
		float g = count1 / 255.0f;
		float b = count2 / 255.0f;*/


		/*float g = static_cast<float>(rand()) / RAND_MAX;
		float b = static_cast<float>(rand()) / RAND_MAX;*/


		


		//GLint colorUniform = glGetUniformLocation(coreProgram, "FragColor1");
		//glUniform4f(colorUniform, 1.0f, 1.0f, 0.0f, 0.01f);

		//glUseProgram(coreProgram);


////	Light position
////coreProgram.use();
////
		glm::vec3 lightPos = glm::vec3(0.0f, 0.0f, -1.f);
		coreProgram.set3fv(lightPos, "LightPos");

		/*
		GLint lightPosLoc = glGetUniformLocation(coreProgram.getId(), "LightPos");
		glUniform3fv(lightPosLoc, 1, glm::value_ptr(lightPos));*/
////
		glm::vec3 color2 = glm::vec3(1.0f, 0.0f, 0.f);
	coreProgram.set3fv(color2, "ColorChange");

//
//unsigned int colorLoc2 = glGetUniformLocation(coreProgram.getId(), "ColorChange");
//		glUniform3fv(colorLoc2, 1, glm::value_ptr(color2));
	//	coreProgram.use();
		
		glm::vec3 pos = glm::vec3(camX, 0.0f, camZ);
		coreProgram.set3fv(pos, "cameraPos");

	//unsigned int viewPosition = glGetUniformLocation(coreProgram.getId(), "cameraPos");
	//glUniform3fv(viewPosition, 1, glm::value_ptr(pos));

		

		/*glDrawArrays(GL_TRIANGLES, 0, 3);*/

		//////for (int i = 0;i < 10; i++) {
		////coreProgram.use();
		glm::mat4 ModelMatrix = glm::mat4(1.0f);
		ModelMatrix = glm::rotate(ModelMatrix,glm::radians(rotOnY), glm::vec3(0.0f, 1.0f, 0.0f));
		coreProgram.setMat4fv(ModelMatrix, "ModelMatrix");

		/*GLint modelMatrix = glGetUniformLocation(coreProgram.getId(), "ModelMatrix");
		glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(ModelMatrix));*/
		tex.bind();
		
		
		

	  // 	 glBindVertexArray(VAO);

	  // //  glDrawArrays(GL_TRIANGLES, 0,3 );

		 //glDrawElements(GL_TRIANGLES, noOfIndices, GL_UNSIGNED_INT, 0);

		 mesh.render(&coreProgram);
			

		//}
		
		//}

		//if (flag) count += 0.4;
		//else count -= 0.4;


		/*count1 *= 0.01;
		count2 += 1;*/



		glfwSwapBuffers(window);
		glfwPollEvents();



	}




	glfwTerminate();


	return 0;

}

