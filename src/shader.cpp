#include "shader.hpp"
#include <iostream>
#include <fstream>


static std::string LoadShader(const std::string& fileName);
static void CheckShaderError(GLuint shader, GLuint flag, 
							 bool isProgram, const std::string& errorMessage);
static GLuint CreateShader(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string& fileName)
{
	Program = glCreateProgram();
	Shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);
	Shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

	for(unsigned int i = 0; i < NUM_SHADERS; i++)
		glAttachShader(Program, Shaders[i]);

	glBindAttribLocation(Program, 0, "position");
	glBindAttribLocation(Program, 1, "texCoord");

	glLinkProgram(Program);
	CheckShaderError(Program, GL_LINK_STATUS, true, "Error: Program linkin failed: ");
	
	glValidateProgram(Program);
	CheckShaderError(Program, GL_VALIDATE_STATUS, true, "Error: Program is not valid: ");
	

}

void Shader::Bind()
{
	glUseProgram(Program);
}

Shader::~Shader()
{
	for(unsigned int i = 0; i < NUM_SHADERS; i++){
		glDetachShader(Program, Shaders[i]);
		glDeleteShader(Shaders[i]);
	}
	glDeleteProgram(Program);
}

static GLuint CreateShader(const std::string& text, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);
	
	if(shader == 0)
		std::cerr << "Error: Shader creation failed!" << std::endl;

	const GLchar* shaderSourceStrings[1];
	GLint shaderSourceStringLengths[1];

	shaderSourceStrings[0] = text.c_str();
	shaderSourceStringLengths[0] = text.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation fail: ");

	return shader;
}

static std::string LoadShader(const std::string& fileName)
{
	std::ifstream file;
	file.open((fileName).c_str());
	
	std::string output;
	std::string line;

	if(file.is_open()){
		while(file.good()){
			getline(file, line);
			output.append(line + "\n");
		}
	}else{
		std::cerr << "Unable to load Shader: " << fileName << std::endl;
	}

	return output;
}


static void CheckShaderError(GLuint shader, GLuint flag, 
							 bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if(isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);
	
	if(success == GL_FALSE){
		if(isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
	
		std::cerr << errorMessage << ": " << error << std::endl;
	}
}
