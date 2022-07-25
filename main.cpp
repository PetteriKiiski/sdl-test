#include "item.h"
#include <SDL2/SDL.h>
int main(int argc, char** arg)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* win = SDL_CreateWindow("SDL Window", 30, 30, 600, 500, SDL_WINDOW_SHOWN);
	SDL_Renderer* screen = SDL_CreateRenderer(win, -1, 0);
	item bob;
	bob.setRenderer(screen);
	bob.loadImage("grass.png");
	bool run = true;
	while (run)
	{
		SDL_Event ev;
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
				case SDL_QUIT:
					run = false;
					break;
			}
		bob.draw();
		SDL_RenderPresent(screen);
		}
	}
	SDL_DestroyWindow(win);
	SDL_Quit();
}
