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

#include<soil2.h>




class Texture
{

private:

	GLuint id;
	int width;
	int height;
	GLenum type;
	GLint textureUnit;

public:
	Texture(const char* filename,GLenum type,GLint textureUnit) {

		this->type = type;
		this->textureUnit = textureUnit;
		
		unsigned char* image = SOIL_load_image(filename, &this->width, &this->height, NULL, SOIL_LOAD_RGBA);

		glGenTextures(1, &this->id);
		glBindTexture(GL_TEXTURE_2D, this->id);

		glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		
		
		if (image)
		{
			glTexImage2D(type, 0, GL_RGB, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(type);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		

		glActiveTexture(0);
		glBindTexture(type,0);
		SOIL_free_image_data(image);

	
	}


	~Texture() {

		glDeleteTextures(1,&this->id);
	}

	inline GLuint getId() const { return this->id; }

	inline GLint getTextureUnit() const { return this->textureUnit; }

	void bind() {
	
		glActiveTexture(GL_TEXTURE0 + this->textureUnit);
		glBindTexture(this->type,this->id);


	}

	void unbind(GLenum type) {
		glActiveTexture(0);
		glBindTexture(type, 0);
	}

};