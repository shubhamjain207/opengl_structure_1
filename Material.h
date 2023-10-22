#pragma once


#include<glad/glad.h>
#include<glfw3.h>
#include<fstream>
#include<iostream>
#include <string>
#include <stdio.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Shader.h"

class Material {


private:

	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	GLint diffuseTex;
	


public:

	Material(glm::vec3 ambient,
	glm::vec3 diffuse,
	glm::vec3 specular,
	GLint diffuseTex
	) {
	
		this->ambient = ambient;
		this->diffuse = diffuse;
		this->specular = specular;
		this->diffuseTex = diffuseTex;
		
	
	}

	~Material() {}

	void sendToShader(Shader& program) {
	
		program.set3fv(this->ambient,"material.ambient");
		program.set3fv(this->diffuse, "material.diffuse");
		program.set3fv(this->specular, "material.specular");
		program.set1i(this->diffuseTex, "material.diffuseTex");
		
			
	
	}


};