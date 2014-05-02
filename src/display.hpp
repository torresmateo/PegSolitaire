#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
class Display
{
public:
	Display(int widht, int height, const std::string& title);

	void Clear(float r, float g, float b, float a);
	void Update();
	bool isClosed();

	virtual ~Display();

protected:
private:
	Display(const Display& other){}
	void operator=(const Display& other){}

	SDL_Window* MWindow;
	SDL_GLContext MGLContext;

	bool IsClosed;
};

#endif
