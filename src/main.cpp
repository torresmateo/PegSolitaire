#include <iostream>
#include <GL/glew.h>
#include "display.hpp"
#include "Board.hpp"
#include <string>

int main()
{

	/*string BoardConfiguration;
	Board b(SQUARE, 3, 3);
	b.generateBoard(BoardConfiguration);
	*/
	Display display(800, 600, "Hello World");

	while(!display.isClosed()){
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
		display.Update();
	}

	return 0;
}
