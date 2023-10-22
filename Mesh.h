#pragma once
#include<iostream>
#include<vector>

#include "Shader.h"
#include "Texture.h"
#include "Material.h"
#include "Vertex.h"


class Mesh
{
	
	unsigned noOfVertices;
	unsigned noOfIndices;


	GLuint VAO;
	GLuint VBO;
	GLuint EBO;


	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	glm::mat4 ModelMatrix;




public:
	void initVAO(Vertex* vertexArray, const unsigned& noOfVertices,
		GLuint* indexArray, const unsigned& noOfIndices) {

		this->noOfVertices = noOfVertices;
		this->noOfIndices = noOfIndices;

	
		
		glGenVertexArrays(1, &this->VAO);
		glBindVertexArray(this->VAO);


		glGenBuffers(1, &this->VBO);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
		glBufferData(GL_ARRAY_BUFFER, this->noOfVertices * sizeof(Vertex),vertexArray, GL_DYNAMIC_DRAW);



		glGenBuffers(1, &this->EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->noOfIndices * sizeof(GLuint), indexArray, GL_DYNAMIC_DRAW);


		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);


		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(8 * sizeof(float)));
		glEnableVertexAttribArray(3);



		glBindVertexArray(0);
	
	
	
	}

	void setPosition(const glm::vec3 position) {
	
		this->position = position;

	
	}

	void move(const glm::vec3 position) {
		
		this->position += position;
	
	}

	

	void updateUniform(Shader* shader) {
	
		shader->setMat4fv(ModelMatrix, "ModelMatrix");
	
	}

	void updateModelMatrix() {
			
		this->ModelMatrix = glm::mat4(1.0f);
		this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(rotation.x), glm::vec3(0.0f, 1.0f, 0.0f));
		this->ModelMatrix = glm::scale(this->ModelMatrix, this->scale);
		
		


	}



public:
	Mesh(
		Vertex* vertexArray, const unsigned& noOfVertices,
		GLuint* indexArray, const unsigned& noOfIndices,
		glm::vec3 position = glm::vec3(0.f),
		glm::vec3 rotation = glm::vec3(0.f),
		glm::vec3 scale = glm::vec3(1.f)) {
	
		 this->position = position;
		 this->rotation = rotation;
		 this->scale = scale;
		
		this->initVAO(vertexArray, noOfVertices,
			indexArray, noOfIndices);
		this->updateModelMatrix();
		
	
	}

	~Mesh() {
	
	
	}

	void render(Shader* shader) {

		this->updateModelMatrix();
		
		this->updateUniform(shader);



		shader->use();	

		glBindVertexArray(this->VAO);

	//	glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, this->noOfIndices, GL_UNSIGNED_INT, 0);
	}

};
