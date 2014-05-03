#include "display.hpp"
#include <GL/glew.h>

Display::Display(int width, int height, const std::string& title)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	MWindow = SDL_CreateWindow(title.c_str(), 
							   SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
							   width, height, SDL_WINDOW_OPENGL);

	MGLContext = SDL_GL_CreateContext(MWindow);

	GLenum status = glewInit();
	if (status != GLEW_OK){
		std::cout << "Glew failed to initialize" << std::endl;
	}

	IsClosed = false;
}

Display::~Display()
{
	
	SDL_GL_DeleteContext(MGLContext);
	SDL_DestroyWindow(MWindow);
	SDL_Quit();
}

bool Display::isClosed()
{
	return IsClosed;
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Display::Update()
{
	SDL_GL_SwapWindow(MWindow);

	SDL_Event E;
	
	while(SDL_PollEvent(&E)){
		if(E.type == SDL_QUIT)
			IsClosed = true;
	}
}
