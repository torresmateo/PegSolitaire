#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <GL/glew.h>

class Shader
{
public:
	Shader(const std::string& fileName);

	void Bind();

	virtual ~Shader();

protected:
private:
	static const unsigned int NUM_SHADERS = 2;
	Shader(const Shader& other){}
	void operator=(const Shader& other){}

	GLuint Program;
	GLuint Shaders[NUM_SHADERS];
};

#endif
